#include "request.h"

Request::Request(const std::string& method, const std::string& service):
    _service(service), _method(method) {}


const std::string& Request::service() const {
    return _service;
}

const std::string& Request::method() const {
    return _method;
}

const std::string& Request::request_header(const std::string& name) const {
    auto it = _request_headers.find(name);
    if (it != _request_headers.end()) {
        return it->second;
    }
    return nullptr;
}

const Headers& Request::request_header() const {
    return _request_headers;
}

const std::string& Request::http_request_header(const std::string& name) const {
    auto it = _http_request_headers.find(name);
    if (it != _http_request_headers.end()) {
        return it->second;
    }
    return nullptr;
}

const Headers& Request::http_request_header() const {
    return _request_headers;
}

const std::string& Request::http_response_header(const std::string& name) const {
    auto it = _http_response_headers.find(name);
    if (it != _http_response_headers.end()) {
        return it->second;
    }
    return nullptr;
}

const Headers& Request::http_response_header() const {
    return _http_response_headers;
}

