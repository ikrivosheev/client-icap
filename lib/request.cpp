#include <sstream>
#include "request.h"

const std::string Request::VERSION = "ICAP/1.0";
const std::string Request::SEP = "\r\n";

Request::Request(
    const std::string& host, 
    const std::string& port, 
    const std::string& method, 
    const std::string& service):
        _host(host), _port(port), _method(method), _service(service) {}


std::string Request::prepare_headers() const {
    std::stringstream ss;
    ss << _method << " " 
        << "icap://" << _host << ":" << _port << "/" << _service << " "
        << Request::VERSION << Request::SEP;
    ss << Request::SEP;
    return ss.str();
}

const std::string& Request::service() const {
    return _service;
}

const std::string& Request::method() const {
    return _method;
}

const std::string& Request::host() const {
    return _host;
}

const std::string& Request::port() const {
    return _port;
}
