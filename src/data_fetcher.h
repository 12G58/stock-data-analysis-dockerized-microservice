// #ifndef DATA_FETCHER_H
// #define DATA_FETCHER_H

// #include <string>
// #include <json/json.h>
// #include <functional>
// #include <websocketpp/config/asio_client.hpp>  // Correct config header
// #include <websocketpp/client.hpp>  // WebSocket++ client
// // #include <websocketpp/config/asio_no_tls.hpp> 

// // Corrected typedef for the WebSocket++ client
// typedef websocketpp::client<websocketpp::config::asio_client> client;

// class DataFetcher {
// private:
//     std::string apiKey;
//     bool isConnected;
//     client c;  // Use the typedef

// public:
//     explicit DataFetcher(const std::string& apiKey);
//     void connectWebSocket(const std::string& symbol, const std::function<void(const Json::Value&)>& callback);
//     bool isWebSocketConnected() const;
// };

// #endif


#ifndef DATA_FETCHER_H
#define DATA_FETCHER_H

#include <string>
#include <functional>
#include <json/json.h>
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>

typedef websocketpp::client<websocketpp::config::asio_client> client; // No TLS

class DataFetcher {
public:
    DataFetcher(const std::string& apiKey);

    void connectWebSocket(const std::string& symbol, const std::function<void(const Json::Value&)>& callback);

    bool isWebSocketConnected() const;

private:
    std::string apiKey;
    client c;
    bool isConnected;
};

#endif
