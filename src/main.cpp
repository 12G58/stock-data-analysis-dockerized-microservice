#include <crow.h>
#include <curl/curl.h>
#include <json/json.h>
#include <iostream>
#include <string>
#include <vector>
#include "data_processor.h" //include processor and fetcher. 
#include "data_fetcher.h" 

// handle CURL responses
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Parse JSON response to extract prices
std::vector<double> extractPrices(const std::string& jsonResponse) {
    Json::CharReaderBuilder reader;
    Json::Value jsonData;
    std::string errs;
    std::istringstream stream(jsonResponse);

    if (!Json::parseFromStream(reader, stream, &jsonData, &errs)) {
        throw std::runtime_error("Failed to parse JSON: " + errs);
    }

    std::vector<double> prices;
    prices.push_back(jsonData["c"].asDouble()); // Current price
    prices.push_back(jsonData["h"].asDouble()); // High 
    prices.push_back(jsonData["l"].asDouble()); // Low 
    prices.push_back(jsonData["o"].asDouble()); // Open 

    return prices;
}

int main() {
    crow::SimpleApp app;

    // Your Finnhub API key
    std::string apiKey = "API_KEY"; // To be replaced with a valid API key (to finnhub in this case)

    if (apiKey.empty()) {
        std::cerr << "API key not provided. Exiting..." << std::endl;
        return -1;
    }

    std::cout << "API key initialized: " << apiKey << std::endl;

    // Data processor instance
    DataProcessor dataProcessor;

    // Define the route for /stream_stock
    app.route_dynamic("/stream_stock")
        .methods("GET"_method)
        ([&apiKey, &dataProcessor](const crow::request& req) {
            auto symbol = req.url_params.get("symbol");
            if (!symbol) {
                return crow::response(400, "Missing stock symbol");
            }

            std::string stockSymbol = std::string(symbol);
            std::cout << "Received request for stock symbol: " << stockSymbol << std::endl;

            // Prepare Finnhub API URL
            std::string url = "https://finnhub.io/api/v1/quote?symbol=" + stockSymbol + "&token=" + apiKey;

            // Initialize CURL
            CURL* curl = curl_easy_init();
            std::string response;

            if (curl) {
                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

                CURLcode res = curl_easy_perform(curl);

                if (res != CURLE_OK) {
                    std::cerr << "CURL error: " << curl_easy_strerror(res) << std::endl;
                    curl_easy_cleanup(curl);
                    return crow::response(500, "Failed to fetch data from Finnhub");
                }

                long http_code = 0;
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
                curl_easy_cleanup(curl);

                if (http_code != 200) {
                    std::cerr << "Finnhub API returned HTTP code: " << http_code << std::endl;
                    return crow::response(500, "Finnhub API returned an error");
                }
            } else {
                return crow::response(500, "CURL initialization failed");
            }

            std::cout << "Response from Finnhub: " << response << std::endl;

            // Process the data
            try {
                std::vector<double> prices = extractPrices(response);

                double movingAverage = dataProcessor.calculateMovingAverage(prices, 3); // can change period
                std::vector<double> outliers = dataProcessor.detectOutliers(prices, 2.0); // threshold
                auto bands = dataProcessor.calculateBollingerBands(prices, 3, 2.0); // period and multiplier

                Json::Value result;
                result["moving_average"] = movingAverage;
                for (double outlier : outliers) {
                    result["outliers"].append(outlier);
                }
                for (const auto& band : bands) {
                    Json::Value bandJson;
                    bandJson["upper"] = band.first;
                    bandJson["lower"] = band.second;
                    result["bollinger_bands"].append(bandJson);
                }

                Json::StreamWriterBuilder writer;
                return crow::response(Json::writeString(writer, result));

            } catch (const std::exception& e) {
                return crow::response(500, std::string("Error processing data: ") + e.what());
            }
        });

    std::cout << "Starting server on port 8081..." << std::endl;

    // server with SSL certificates; the ssl can be disabled using curl -k for testing, otherwise requires a valid cert and key from a certification authority (CA). 
    app.bindaddr("0.0.0.0")
        .port(8081)
        .ssl_file("/home/free/data-analytics-microservice/cert.pem", "/home/free/data-analytics-microservice/key.pem")
        .multithreaded()
        .run();
}
