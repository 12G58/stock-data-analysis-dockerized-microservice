// #include <crow.h>
// #include "data_fetcher.h"
// #include <iostream>

// int main() {
//     crow::SimpleApp app;
    
//     // Your API key
//     std::string apiKey = "ctc3l2hr01qjor97mfu0ctc3l2hr01qjor97mfug"; // Replace with your Finnhub API key

//     if (apiKey.empty()) {
//         std::cerr << "API key not provided. Exiting..." << std::endl;
//         return -1;
//     }

//     std::cout << "API key initialized: " << apiKey << std::endl;

//     // Create an instance of the DataFetcher
//     DataFetcher dataFetcher(apiKey);

//     // Define the route for /stream_stock
//     app.route_dynamic("/stream_stock")
//     .methods("GET"_method)
//     ([&dataFetcher](const crow::request& req) {
//         auto symbol = req.url_params.get("symbol");
//         if (!symbol) {
//             std::cerr << "Error: Missing stock symbol in request." << std::endl;
//             return crow::response(400, "Missing stock symbol");
//         }

//         std::string stockSymbol = std::string(symbol);
//         std::cout << "Starting websocket for symbol: " << stockSymbol << std::endl;

//         // Attempt to establish WebSocket connection
//         dataFetcher.connectWebSocket(stockSymbol, [](const Json::Value& data) {
//             std::cout << "Real-time stock data: " << data.toStyledString() << std::endl;
//         });

//         if (!dataFetcher.isWebSocketConnected()) {
//             std::cerr << "Error: Failed to establish WebSocket connection for symbol: " << stockSymbol << std::endl;
//             return crow::response(500, "Failed to establish secure WebSocket connection");
//         }

//         return crow::response(200, "WebSocket connection established for " + stockSymbol);
//     });

//     std::cout << "Starting server on port 8081..." << std::endl;

//     // Set up the server with SSL certificates
//     app.bindaddr("0.0.0.0")
//        .port(8081)
//        .ssl_file("/home/free/data-analytics-microservice/cert.pem", "/home/free/data-analytics-microservice/key.pem")
//        .multithreaded()
//        .run();
// }

// #include <crow.h>
// #include "data_fetcher.h"
// #include <iostream>
// #include <thread>

// int main() {
//     crow::SimpleApp app;

//     // Replace with your Finnhub API key
//     std::string apiKey = "YOUR_FINNHUB_API_KEY"; 

//     if (apiKey.empty()) {
//         std::cerr << "API key not provided. Exiting..." << std::endl;
//         return -1;
//     }

//     std::cout << "API key initialized: " << apiKey << std::endl;

//     // Create an instance of the DataFetcher
//     DataFetcher dataFetcher(apiKey);

//     // Define the route for /stream_stock
//     app.route_dynamic("/stream_stock")
//         .methods("GET"_method)
//         ([&dataFetcher](const crow::request& req) {
//             auto symbol = req.url_params.get("symbol");
//             if (!symbol) {
//                 std::cerr << "Error: Missing stock symbol in request." << std::endl;
//                 return crow::response(400, "Missing stock symbol");
//             }

//             std::string stockSymbol = std::string(symbol);
//             std::cout << "Starting websocket for symbol: " << stockSymbol << std::endl;

//             // Run WebSocket connection in a separate thread
//             std::thread websocketThread([&dataFetcher, stockSymbol]() {
//                 dataFetcher.connectWebSocket(stockSymbol, [](const Json::Value& data) {
//                     std::cout << "Real-time stock data: " << data.toStyledString() << std::endl;
//                 });
//             });

//             // Detach the thread so it can run independently
//             websocketThread.detach();

//             // Check if WebSocket is connected (may not be immediately connected)
//             if (!dataFetcher.isWebSocketConnected()) {
//                 std::cerr << "Warning: WebSocket connection may still be in progress." << std::endl;
//             }

//             return crow::response(200, "WebSocket connection initiated for " + stockSymbol);
//         });

//     std::cout << "Starting server on port 8080..." << std::endl; // Changed port to 8080

//     // Set up the server without SSL 
//     app.bindaddr("0.0.0.0")
//         .port(8080) // No SSL, use regular port
//         .multithreaded()
//         .run();
// }



#include <crow.h>
#include "data_fetcher.h"
#include <iostream>
#include <thread>

int main() {
    crow::SimpleApp app;

    // Replace with your Finnhub API key
    std::string apiKey = "ctc3l2hr01qjor97mfu0ctc3l2hr01qjor97mfug";

    if (apiKey.empty()) {
        std::cerr << "API key not provided. Exiting..." << std::endl;
        return -1;
    }

    std::cout << "API key initialized: " << apiKey << std::endl;

    // Create an instance of the DataFetcher
    DataFetcher dataFetcher(apiKey);

    // Define the route for /stream_stock
    app.route_dynamic("/stream_stock")
        .methods("GET"_method)
        ([&dataFetcher](const crow::request& req) {
            auto symbol = req.url_params.get("symbol");
            if (!symbol) {
                std::cerr << "Error: Missing stock symbol in request." << std::endl;
                return crow::response(400, "Missing stock symbol");
            }

            std::string stockSymbol = std::string(symbol);
            std::cout << "Starting websocket for symbol: " << stockSymbol << std::endl;

            // Run WebSocket connection in a separate thread
            std::thread websocketThread([&dataFetcher, stockSymbol]() {
                dataFetcher.connectWebSocket(stockSymbol, [](const Json::Value& data) {
                    std::cout << "Real-time stock data: " << data.toStyledString() << std::endl;
                });
            });

            // Detach the thread so it can run independently
            websocketThread.detach();

            // Check if WebSocket is connected (may not be immediately connected)
            if (!dataFetcher.isWebSocketConnected()) {
                std::cerr << "Warning: WebSocket connection may still be in progress." << std::endl;
            }

            return crow::response(200, "WebSocket connection initiated for " + stockSymbol);
        });

    std::cout << "Starting server on port 8080..." << std::endl;

    // Set up the server without SSL
    app.bindaddr("0.0.0.0")
        .port(8080)
        .multithreaded()
        .run();
}