#include <iostream>
#include <boost/asio.hpp>
#include "lib/icap.h"


int main() {
    boost::asio::io_service ios;
    Client client(ios);
    Response resp = client.options("localhost", "13440", "echo");
    std::cout << resp.status() << " " << resp.reason() << std::endl;
    for (auto& header: resp.headers()) {
        std::cout << header.first << ": " << header.second << std::endl;
    }
    return 0;
}
