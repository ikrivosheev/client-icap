#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>

class Response {
    public:
        Response(const std::string&, const std::string&, const std::string&);

        const std::string& protocol() const;
        const std::string& status() const;
        const std::string& reason() const;
        
    private:
        std::string _protocol;
        std::string _status;
        std::string _reason;
};


#endif // RESPONSE_H
