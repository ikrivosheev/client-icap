#include <boost/asio.hpp>
#include "lib/icap.h"


int main() {
    boost::asio::io_service ios;
    Client client("localhost", "9000", ios);
    return 0;
}
