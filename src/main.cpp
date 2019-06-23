#include <iostream>
#include <boost/asio.hpp>
#include "lib/icap.h"


int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage c-icap <host> <port> <service>" << std::endl;
        return 1;
    }
    boost::asio::io_service ios;
    Client client(ios);
    Response resp = client.options(argv[1], argv[2], argv[3]);
    std::cout << resp.version() << " " << resp.status() << " " << resp.reason() << std::endl;
    for (auto& header: resp.headers()) {
        std::cout << header.first << ": " << header.second << std::endl;
    }
    return 0;
}
