#include "client.h"

Response Client::request(const Request&) {
    Connection conn(url);
    conn.send(request);
    return conn.response();
}

Response Client::options(const Headers& request_headers, const std::string& url) {
    Request request("OPTIONS", service);
    request.request_header(request_headers);
    return request(request);
}

