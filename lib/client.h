#ifndef CLIENT_H
#define CLIENT_H

#include <boost/asio.hpp>

#include "request.h"
#include "response.h"

using boost::asio::ip::tcp;


class Client {
    public:
       Client(boost::asio::io_service&);
        
       Response request(const Request&);
       Response options(const std::string&, const std::string& port, const std::string&);
    private:
       boost::asio::io_service& _ios;
       tcp::socket _socket;
};

#endif // CLIENT_H
