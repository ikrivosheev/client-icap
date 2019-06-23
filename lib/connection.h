#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>
#include "request.h"
#include "response.h"


class Connection {
    public:
        Connection(const std::string&, const int);
        ~Connection();

        void connect();
        void disconnect();

        void send(const Request&);
        Response response();

    private:
        std::string _host;
        int _port;
        bool _sended; 
}
