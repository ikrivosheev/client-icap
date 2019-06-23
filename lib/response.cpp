#include "response.h"

Response::Response(
    const std::string& protocol, 
    const std::string& status, 
    const std::string& reason):
        _protocol(protocol), _status(status), _reason(reason) {}

const std::string& Response::protocol() const {
    return _protocol;
}

const std::string& Response::status() const {
    return _status;
}

const std::string& Response::reason() const {
    return _reason;
}

Headers::const_iterator Response::header(const std::string& name) const {
    return _headers.find(name);
}

const Headers& Response::headers() const {
    return _headers;
}

void Response::header(const std::string& name, std::string& value) {
    _headers[name] = value;
}

void Response::header(const Header& header) {
    _headers.insert(header);
}

