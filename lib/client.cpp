#include <iostream>
#include <boost/asio/read_until.hpp>
#include "client.h"

Client::Client(boost::asio::io_service& ios):
    _ios(ios), _socket(ios) {}


Response Client::request(const Request& request) {
    tcp::resolver::query q(request.host(), request.port());
    tcp::resolver resolver(_ios);
    boost::asio::connect(_socket, resolver.resolve(q));

    boost::asio::write(_socket, boost::asio::buffer(request.prepare_headers()));
    
    boost::asio::streambuf buffer;
    boost::asio::read_until(_socket, buffer, "\r\n");
    std::istream response_stream(&buffer);
    std::string version, status, reason;
    response_stream >> version >> status >> reason;
    return Response(version, status, reason);
}

Response Client::options(const std::string& host, const std::string& port, const std::string& service) {
    Request req(host, port, "OPTIONS", service);
    return request(req);
}

