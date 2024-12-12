#ifndef DATA_FETCHER_H
#define DATA_FETCHER_H
#include <string>
#include <functional>
#include <json/json.h>
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>

typedef websocketpp::client<websocketpp::config::asio_client> client;

class DataFetcher {
public:
    DataFetcher(const std::string& apiKey);
    void connectWebSocket(const std::string& symbol, const std::function<void(const Json::Value&)>& callback);
    void disconnectWebSocket();
    bool isWebSocketConnected() const;

private:
    std::string apiKey;
    client wsClient; // Member variable to store the WebSocket client
    bool isConnected;
};

#endif
