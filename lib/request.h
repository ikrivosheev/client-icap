#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <map>

using Header = std::pair<std::string, std::string>;
using Headers = std::map<std::string, std::string>;

class Request {
    public:
        static const std::string VERSION;
        static const std::string SEP;

        Request(const std::string&, const std::string&, const std::string&, const std::string&);
        Request(const Request&) = default;
        Request& operator = (const Request&) = default;
        ~Request() = default;

        std::string prepare_headers() const;
        
        const std::string& port() const;
        const std::string& host() const;
        const std::string& method() const;
        const std::string& service() const;

    private:
        std::string _host;
        std::string _port;
        std::string _method;
        std::string _service;

        Headers _request_headers;

        std::string _http_start_line;
        Headers _http_request_headers;
        Headers _http_response_headers;
};

#endif // REQUEST_H
