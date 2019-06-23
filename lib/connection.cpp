#include "connection.h"


Connection::Connection(const std::string& host, int port): 
    _host(host), _port(port) {};


void Connection::connect() {
}

void Connection::disconnect() {
}

void Connection::send(const Request& requeset) {
}

Response Connection::response() {
}
