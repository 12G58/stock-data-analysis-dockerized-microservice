#include "data_fetcher.h"
#include <iostream>
#include <sstream>
#include <json/json.h>
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>

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