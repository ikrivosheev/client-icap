#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>
#include "headers.h"

class Response {
    public:
        Response(const std::string&, const std::string&, const std::string&);

        const std::string& version() const;
        const std::string& status() const;
        const std::string& reason() const;
        
        Headers::const_iterator header(const std::string&) const;
        const Headers& headers() const;

        void header(const std::string&, std::string&);
        void header(const Header& header);
        
    private:
        std::string _version;
        std::string _status;
        std::string _reason;
        Headers _headers;
};


#endif // RESPONSE_H
