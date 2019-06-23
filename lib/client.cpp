#include "client.h"
#include "connection.h"

Client::Client(boost::asio::io_service& ios): _ios(ios) {}


Response Client::request(const Request& req) {
    Connection conn(req.host(), req.port(), _ios);
    conn.connect();
    conn.send(req);
    Response resp = conn.response();
    conn.disconnect();
    return resp; 
}

Response Client::options(const std::string& host, const std::string& port, const std::string& service) {
    Request req(host, port, "OPTIONS", service);
    return request(req);
}

