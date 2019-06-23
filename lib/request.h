#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <map>

using Header = std::pair<std::string, std::string>;
using Headers = std::map<std::string, std::string>;

class Request {
    public:
        Request() = default;
        Request(const std::string&, const std::string&);
        Request(const Request&) = default;
        Request& operator = (const Request&) = default;
        ~Request() = default;
        
        const std::string& service() const;
        const std::string& method() const;
        const std::string& request_header(const std::string&) const;
        const Headers& request_header() const;
        const std::string& http_request_header(const std::string&) const;
        const Headers& http_request_header() const;
        const std::string& http_response_header(const std::string&) const;
        const Headers& http_response_header() const;

        void service(const std::string&);
        void method(const std::string&);
        void http_start_line(std::string&);
        void request_header(const std::string&, const std::string&);
        void request_header(const Header&);
        void request_header(const Headers&);
        void http_request_header(const std::string&, const std::string&);
        void http_request_header(const Header&);
        void http_request_header(const Headers&);
        void http_response_header(const std::string&, const std::string&);
        void http_response_header(const Header&);
        void http_response_header(const Headers&);


    private:
        std::string _service;
        std::string _method;
        Headers _request_headers;

        std::string _http_start_line;
        Headers _http_request_headers;
        Headers _http_response_headers;
};

#endif // REQUEST_H
