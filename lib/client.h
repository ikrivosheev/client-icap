#ifndef CLIENT_H
#define CLIENT_H

#include <boost/asio.hpp>

#include "request.h"
#include "response.h"


class Client {
    public:
       Client(boost::asio::io_service&);
        
       Response request(const Request&);
       Response options(const std::string&, const std::string& port, const std::string&);
    private:
       boost::asio::io_service& _ios;
};

#endif // CLIENT_H
