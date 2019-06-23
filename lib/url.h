#ifndef URL_H
#define URL_H

#include <string>
#include <sstream>
#include <curl/curl.h>

class URL {
    public:
        static URL from_string(const std::string&);
        
        URL() = default;
        URL(const URL&) = default;
        URL& operator = (const URL&) = default;
        ~URL() = default;
        
        std::string str() const;

        const std::string& scheme() const;
        const std::string& userinfo() const;
        const std::string& host() const;
        int port() const;
        const std::string& path() const;
        const std::string& query() const;
        const std::string& fragment() const;

        URL& scheme(const std::string&);
        URL& userinfo(const std::string&);
        URL& host(const std::string&);
        URL& port(int);
        URL& path(const std::string&);
        URL& query(const std::string&);
        URL& fragment(const std::string&);

    private:
        std::string _scheme;
        std::string _userinfo;
        std::string _host;
        int _port = 1344;
        std::string _path;
        std::string _query;
        std::string _fragment;
};

#endif // URL_H
