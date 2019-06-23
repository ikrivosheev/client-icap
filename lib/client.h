#ifndef CLIENT_H
#define CLIENT_H

#include <boost/asio.hpp>

#include "request.h"
#include "response.h"

using boost::asio::ip::tcp;


class Client {
    public:
       Client(const std::string&, const std::string&, boost::asio::io_service&);
        
       Response request(const Request&);
       Response options(const std::string&);
    private:
       tcp::socket _socket;
};

#endif // CLIENT_H
