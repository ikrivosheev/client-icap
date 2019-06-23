#include "client.h"

Client::Client(const std::string& host, const std::string& port, boost::asio::io_service& ios):
    _socket(ios) {
        tcp::resolver::query q(host, port);
        tcp::resolver resolver(ios);
        boost::asio::connect(_socket, resolver.resolve(q));
    }

Response Client::request(const Request& request) {
    return Response();
}

Response Client::options(const std::string& service) {
    Request req("OPTIONS", service);
    return request(req);
}

