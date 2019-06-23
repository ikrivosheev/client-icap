#include "url.h"

#define CURL_URL_GET(h, option, buffer, flags, url_h, empty_error, error_str) \
    uc = curl_url_get(h, option, &buffer, flags); \
    if (uc && uc != empty_error) { \
        throw std::overflow_error(error_str); \
    } \
    if (uc != empty_error) { \
        url_h(buffer); \
    } \
    delete buffer;


URL URL::from_string(const std::string& url) {
    URL result;
    CURLU * h;
    char* buffer;

    h = curl_url();
    if (!h) {
        throw "ERROR";
    }
    auto uc = curl_url_set(h, CURLUPART_URL, url.c_str(), CURLU_NON_SUPPORT_SCHEME);
     
    if (uc) {
        throw "ERROR";
    }
    CURL_URL_GET(h, CURLUPART_SCHEME, buffer, 0, result.scheme, CURLUE_NO_SCHEME, "Error on parse scheme") 
    CURL_URL_GET(h, CURLUPART_OPTIONS, buffer, 0, result.userinfo, CURLUE_NO_OPTIONS, "Error on parse options")
    CURL_URL_GET(h, CURLUPART_HOST, buffer, 0, result.host, CURLUE_NO_HOST, "Error on parse host") 
    CURL_URL_GET(h, CURLUPART_PATH, buffer, 0, result.path, -1, "Error on parse path") 
    CURL_URL_GET(h, CURLUPART_QUERY, buffer, 0, result.query, CURLUE_NO_QUERY, "Error on parse query") 
    CURL_URL_GET(h, CURLUPART_FRAGMENT, buffer, 0, result.fragment, CURLUE_NO_FRAGMENT, "Error on parse fragment") 
    
    uc = curl_url_get(h, CURLUPART_PORT, &buffer, 0);
    if (uc && uc != CURLUE_NO_PORT) {
        throw std::overflow_error("Error on parse port");
    }
    int port = 1344;
    if (uc != CURLUE_NO_PORT) {
        try {
            port = std::stoi(buffer);
        }
        catch(std::exception const& e) {
            throw std::overflow_error("Error on convert port to int");
        }
    }
    result.port(port);
    delete buffer;

    return result;
}

std::string URL::str() const {
    std::stringstream ss;
    ss << _scheme << "://" 
        << _userinfo << "@" 
        << _host << ":" 
        << _port << _path << "?" << _query;
    return ss.str();
}

const std::string& URL::scheme() const {
    return _scheme;
}
                                     
const std::string& URL::userinfo() const {
    return _userinfo;
}

const std::string& URL::host() const {
    return _host;
}

int URL::port() const {
    return _port;
}

const std::string& URL::path() const {
    return _path; 
}

const std::string& URL::query() const {
    return _query;
}

const std::string& URL::fragment() const {
    return _fragment;
}
                                     
URL& URL::scheme(const std::string& scheme) {
    _scheme = scheme;
    return (*this);
}

URL& URL::userinfo(const std::string& userinfo) {
    _userinfo = userinfo;
    return (*this);
}

URL& URL::host(const std::string& host) {
    _host = host;
    return (*this);
}

URL& URL::port(int port) {
    _port = port;
    return (*this);
}

URL& URL::path(const std::string& path) {
    _path = path;
    return (*this);
}

URL& URL::query(const std::string& query) {
    _query = query;
    return (*this);
}

URL& URL::fragment(const std::string& fragment) {
    _fragment = fragment;
    return (*this);
}
