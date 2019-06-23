#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>
#include <boost/asio.hpp>
#include "request.h"
#include "response.h"

using boost::asio::ip::tcp;

static const std::string SEP("\r\n");

class Connection {
    public:
        Connection(const std::string&, const std::string&, boost::asio::io_service&);
        ~Connection() = default;

        void connect();
        void disconnect();

        void send(const Request&);
        Response response();

    private:
        std::string _host;
        std::string _port;
        boost::asio::io_service& _ios;
        tcp::socket _socket;
};

#endif // CONNECTION_H
