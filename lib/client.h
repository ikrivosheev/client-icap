#ifndef CLIENT_H
#define CLIENT_H

#include "pool.h"
#include "request.h"
#include "response.h"
#include "connection.h"

class Client {
    public:
       Client() = default;
        
       Response request(const Request&);
       Response options(const Headers&, const std::string&);
};

#endif // CLIENT_H
