// #include "data_fetcher.h"
// #include <iostream>
// #include <websocketpp/config/asio_no_tls_client.hpp>
// #include <websocketpp/client.hpp>
// #include <json/json.h>

// typedef websocketpp::client<websocketpp::config::asio_client> c;

// DataFetcher::DataFetcher(const std::string& apiKey) : apiKey(apiKey), isConnected(false) {}

// void DataFetcher::connectWebSocket(const std::string& symbol, const std::function<void(const Json::Value&)>& callback) {
    
//     std::cout << "Initializing websocket connection for symbol: " << symbol << std::endl;

//     std::string wsUrl = "wss://ws.finnhub.io?token=" + apiKey;
//     c.init_asio();
//     std::cout << "WebSocket client initialized" << std::endl;

//     c.set_message_handler([this, callback](websocketpp::connection_hdl hdl, client::message_ptr msg) {
//         (void)hdl; // Ignore unused parameter
//         std::cout << "Message received from websocket: " << msg->get_payload() << std::endl;

//         Json::CharReaderBuilder reader;
//         Json::Value jsonData;
//         std::string errs;

//         std::istringstream sstream(msg->get_payload());
//         if (Json::parseFromStream(reader, sstream, &jsonData, &errs)) {
//             callback(jsonData);
//         } else {
//             std::cerr << "Error parsing websocket message: " << errs << std::endl;
//         }
//     });

//     c.set_open_handler([this, symbol](websocketpp::connection_hdl hdl) {
//         std::cout << "WebSocket connection opened." << std::endl;
//         isConnected = true;
//         c.send(hdl, "{\"type\":\"subscribe\",\"symbol\":\"" + symbol + "\"}", websocketpp::frame::opcode::text);
//     });

//     c.set_fail_handler([](websocketpp::connection_hdl) {
//         std::cerr << "WebSocket connection failed." << std::endl;
//     });

//     c.set_close_handler([this](websocketpp::connection_hdl) {
//         std::cout << "WebSocket connection closed." << std::endl;
//         isConnected = false;
//     });

//     websocketpp::lib::error_code ec;
//     client::connection_ptr con = c.get_connection(wsUrl, ec);
//     if (ec) {
//         std::cerr << "WebSocket connection initialization error: " << ec.message() << std::endl;
//         return;
//     }

//     std::cout << "WebSocket connection established, sending subscribe message..." << std::endl;

//     c.connect(con);
//     c.run();
// }


// bool DataFetcher::isWebSocketConnected() const {
//     return isConnected;
// }




// #include "data_fetcher.h"
// #include <iostream>
// #include <websocketpp/config/asio_no_tls_client.hpp>
// #include <websocketpp/client.hpp>
// #include <json/json.h>
// #include <functional>
// #include <sstream>

// typedef websocketpp::client<websocketpp::config::asio_client> client;

// DataFetcher::DataFetcher(const std::string& apiKey) : apiKey(apiKey), isConnected(false) {}

// void DataFetcher::connectWebSocket(const std::string& symbol, const std::function<void(const Json::Value&)>& callback) {
//     std::cout << "Initializing websocket connection for symbol: " << symbol << std::endl;

//     std::string wsUrl = "wss://ws.finnhub.io?token=" + apiKey;
//     client wsClient;

//     wsClient.init_asio();
//     wsClient.set_message_handler([callback](websocketpp::connection_hdl, client::message_ptr msg) {
//         Json::CharReaderBuilder reader;
//         Json::Value jsonData;
//         std::string errs;

//         std::istringstream sstream(msg->get_payload());
//         if (Json::parseFromStream(reader, sstream, &jsonData, &errs)) {
//             callback(jsonData);
//         } else {
//             std::cerr << "Error parsing websocket message: " << errs << std::endl;
//         }
//     });

//     wsClient.set_open_handler([symbol](websocketpp::connection_hdl hdl) {
//         std::cout << "WebSocket connection opened." << std::endl;
//         wsClient.send(hdl, "{\"type\":\"subscribe\",\"symbol\":\"" + symbol + "\"}", websocketpp::frame::opcode::text);
//     });

//     wsClient.set_close_handler([](websocketpp::connection_hdl) {
//         std::cout << "WebSocket connection closed." << std::endl;
//     });

//     wsClient.set_fail_handler([](websocketpp::connection_hdl) {
//         std::cerr << "WebSocket connection failed." << std::endl;
//     });

//     websocketpp::lib::error_code ec;
//     auto connection = wsClient.get_connection(wsUrl, ec);

//     if (ec) {
//         std::cerr << "Connection initialization error: " << ec.message() << std::endl;
//         return;
//     }

//     wsClient.connect(connection);
//     wsClient.run();
// }

// bool DataFetcher::isWebSocketConnected() const {
//     return isConnected;
// }



// #include "data_fetcher.h"
// #include <iostream>
// #include <sstream>
// #include <json/json.h>

// DataFetcher::DataFetcher(const std::string& apiKey) : apiKey(apiKey), isConnected(false) {}

// void DataFetcher::connectWebSocket(const std::string& symbol, const std::function<void(const Json::Value&)>& callback) {
//     if (symbol.empty()) {
//         throw std::invalid_argument("Stock symbol cannot be empty.");
//     }

//     std::string wsUrl = "wss://ws.finnhub.io?token=" + apiKey;
//     wsClient.init_asio();

//     wsClient.set_message_handler([callback](websocketpp::connection_hdl, client::message_ptr msg) {
//         Json::CharReaderBuilder reader;
//         Json::Value jsonData;
//         std::string errs;

//         std::istringstream sstream(msg->get_payload());
//         if (Json::parseFromStream(reader, sstream, &jsonData, &errs)) {
//             callback(jsonData);
//         } else {
//             std::cerr << "Error parsing WebSocket message: " << errs << std::endl;
//         }
//     });

//     wsClient.set_open_handler([this, symbol](websocketpp::connection_hdl hdl) {
//         std::cout << "WebSocket connection opened." << std::endl;
//         isConnected = true;
//         wsClient.send(hdl, "{\"type\":\"subscribe\",\"symbol\":\"" + symbol + "\"}", websocketpp::frame::opcode::text);
//     });

//     wsClient.set_fail_handler([](websocketpp::connection_hdl) {
//         std::cerr << "WebSocket connection failed." << std::endl;
//     });

//     wsClient.set_close_handler([this](websocketpp::connection_hdl) {
//         std::cout << "WebSocket connection closed." << std::endl;
//         isConnected = false;
//     });

//     websocketpp::lib::error_code ec;
//     client::connection_ptr con = wsClient.get_connection(wsUrl, ec);
//     if (ec) {
//         std::cerr << "WebSocket connection initialization error: " << ec.message() << std::endl;
//         return;
//     }

//     wsClient.connect(con);
//     wsClient.run();
// }

// bool DataFetcher::isWebSocketConnected() const {
//     return isConnected;
// }

// void DataFetcher::disconnectWebSocket() {
//     if (isConnected) {
//         wsClient.stop();
//         isConnected = false;
//     }
// }


// #include "data_fetcher.h"
// #include <iostream>
// #include <sstream>
// #include <json/json.h>
// #include <websocketpp/config/asio_no_tls_client.hpp>
// #include <websocketpp/client.hpp>
// typedef websocketpp::clientwebsocketpp::config::asio_client client;

// DataFetcher::DataFetcher(const std::string& apiKey) : apiKey(apiKey), isConnected(false) {}

// void DataFetcher::connectWebSocket(const std::string& symbol, const std::function<void(const Json::Value&)>& callback) {
//     if (symbol.empty()) {
//         throw std::invalid_argument("Stock symbol cannot be empty.");
//     }
//     std::string wsUrl = "wss://ws.finnhub.io?token=" + apiKey;
//     wsClient.init_asio();

//     wsClient.set_message_handler([callback](websocketpp::connection_hdl, client::message_ptr msg) {
//         Json::CharReaderBuilder reader;
//         Json::Value jsonData;
//         std::string errs;

//         std::istringstream sstream(msg->get_payload());
//         if (Json::parseFromStream(reader, sstream, &jsonData, &errs)) {
//             callback(jsonData);
//         } else {
//             std::cerr << "Error parsing WebSocket message: " << errs << std::endl;
//         }
//     });

//     wsClient.set_open_handler([this, symbol, callback](websocketpp::connection_hdl hdl) {
//         std::cout << "WebSocket connection opened." << std::endl;
//         isConnected = true;
//         wsClient.send(hdl, "{\"type\":\"subscribe\",\"symbol\":\"" + symbol + "\"}", websocketpp::frame::opcode::text);
//     });

//     wsClient.set_fail_handler([](websocketpp::connection_hdl) {
//         std::cerr << "WebSocket connection failed." << std::endl;
//     });

//     wsClient.set_close_handler([this](websocketpp::connection_hdl) {
//         std::cout << "WebSocket connection closed." << std::endl;
//         isConnected = false;
//     });

//     websocketpp::lib::error_code ec;
//     client::connection_ptr con = wsClient.get_connection(wsUrl, ec);
//     if (ec) {
//         std::cerr << "WebSocket connection initialization error: " << ec.message() << std::endl;
//         return;
//     }

//     wsClient.connect(con);
//     wsClient.run();
// }

// bool DataFetcher::isWebSocketConnected() const {
//     return isConnected;
// }

// void DataFetcher::disconnectWebSocket() {
//     if (isConnected) {
//         wsClient.stop();
//         isConnected = false;
//     }
// }


#include "data_fetcher.h"
#include <iostream>
#include <sstream>
#include <json/json.h>
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>

// Corrected typedef is now in the header file
// typedef websocketpp::client<websocketpp::config::asio_client> client;

DataFetcher::DataFetcher(const std::string& apiKey) : apiKey(apiKey), isConnected(false) {}

void DataFetcher::connectWebSocket(const std::string& symbol, const std::function<void(const Json::Value&)>& callback) {
    if (symbol.empty()) {
        throw std::invalid_argument("Stock symbol cannot be empty.");
    }
    std::string wsUrl = "wss://ws.finnhub.io?token=" + apiKey;
    wsClient.init_asio();

    wsClient.set_message_handler([callback](websocketpp::connection_hdl, client::message_ptr msg) {
        Json::CharReaderBuilder reader;
        Json::Value jsonData;
        std::string errs;

        std::istringstream sstream(msg->get_payload());
        if (Json::parseFromStream(reader, sstream, &jsonData, &errs)) {
            callback(jsonData);
        } else {
            std::cerr << "Error parsing WebSocket message: " << errs << std::endl;
        }
    });

    wsClient.set_open_handler([this, symbol, callback](websocketpp::connection_hdl hdl) {
        std::cout << "WebSocket connection opened." << std::endl;
        isConnected = true;
        wsClient.send(hdl, "{\"type\":\"subscribe\",\"symbol\":\"" + symbol + "\"}", websocketpp::frame::opcode::text);
    });

    wsClient.set_fail_handler([](websocketpp::connection_hdl) {
        std::cerr << "WebSocket connection failed." << std::endl;
    });

    wsClient.set_close_handler([this](websocketpp::connection_hdl) {
        std::cout << "WebSocket connection closed." << std::endl;
        isConnected = false;
    });

    websocketpp::lib::error_code ec;
    client::connection_ptr con = wsClient.get_connection(wsUrl, ec);
    if (ec) {
        std::cerr << "WebSocket connection initialization error: " << ec.message() << std::endl;
        return;
    }

    wsClient.connect(con);
    wsClient.run();
}

bool DataFetcher::isWebSocketConnected() const {
    return isConnected;
}

void DataFetcher::disconnectWebSocket() {
    if (isConnected) {
        wsClient.stop();
        isConnected = false;
    }
}