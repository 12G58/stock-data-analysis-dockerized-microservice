#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
#include <iostream>

typedef websocketpp::client<websocketpp::config::asio_client> client;

int main() {
    client c;
    std::string uri = "ws://ws.finnhub.io?token=YOUR_API_KEY"; // Replace with your API key

    try {
        c.set_access_channels(websocketpp::log::alevel::all);
        c.clear_access_channels(websocketpp::log::alevel::frame_payload);
        c.set_error_channels(websocketpp::log::elevel::all);

        c.init_asio();

        c.set_open_handler([](websocketpp::connection_hdl) {
            std::cout << "Connection opened." << std::endl;
        });

        c.set_fail_handler([](websocketpp::connection_hdl) {
            std::cerr << "Connection failed." << std::endl;
        });

        c.set_message_handler([](websocketpp::connection_hdl, client::message_ptr msg) {
            std::cout << "Received message: " << msg->get_payload() << std::endl;
        });

        websocketpp::lib::error_code ec;
        client::connection_ptr con = c.get_connection(uri, ec);
        if (ec) {
            std::cerr << "Could not create connection because: " << ec.message() << std::endl;
            return 1;
        }

        c.connect(con);
        c.run();
    } catch (websocketpp::exception const & e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}