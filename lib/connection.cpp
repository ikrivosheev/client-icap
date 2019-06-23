#include <iostream>
#include <boost/asio/read_until.hpp>
#include <boost/asio/buffers_iterator.hpp>
#include "connection.h"


Connection::Connection(
    const std::string& host, 
    const std::string& port, 
    boost::asio::io_service& ios):
        _host(host), _port(port), _ios(ios), _socket(ios) {}


void Connection::connect() {
    tcp::resolver::query q(_host, _port);
    tcp::resolver resolver(_ios);
    boost::asio::connect(_socket, resolver.resolve(q));
}

void Connection::disconnect() {
    _socket.close();
}

void Connection::send(const Request& request) {
    boost::asio::write(_socket, boost::asio::buffer(request.prepare_headers()));
}

Response Connection::response() {
    boost::asio::streambuf buffer;
    
    std::size_t bytes = boost::asio::read_until(_socket, buffer, SEP + SEP);
    std::istream response_stream(&buffer);
    std::string version, status, reason;
    response_stream >> version >> status >> reason;
    response_stream.ignore(2);
    Response resp(version, status, reason);
    
    std::string line;
    while (std::getline(response_stream, line)) {
        line.pop_back();
        if (line.size() == 0) 
            break;
        auto pos = line.find(": ");
        auto name = line.substr(0, pos);
        auto value = line.substr(pos + 2);
        resp.header(name, value);
    }
    return resp;
}
