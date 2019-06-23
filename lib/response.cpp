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

