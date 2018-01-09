#include <stdlib.h>
#include <iostream>
#include "../include/ConnectionHandler.h"
#include <boost/thread.hpp>
#include "ClientWriter.cpp"


/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/

int main (int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " host port" << std::endl << std::endl;
        return -1;
    }
    std::string host = argv[1];
    short port = atoi(argv[2]);

    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    } else
        std::cout << "connected to server" << std::endl;
    ClientWriter writer(connectionHandler);
    boost::thread WriterThread(writer);

    //From here we will see the rest of the ehco client implementation:
    while (!connectionHandler.isShould_terminate()) {
        std::string answer;
        size_t len;
        if (!connectionHandler.getLine(answer)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            connectionHandler.setShould_terminate(false);
            break;
        }
        len = answer.length();
        // A C string must end with a 0 char delimiter.  When we filled the answer buffer from the socket
        // we filled up to the \n char - we must make sure now that a 0 char is also present. So we truncate last character.
        answer.resize(len - 1);
        std::cout << answer << std::endl;
        if (answer.compare("ACK signout succeeded")==0) {
            std::cout << "Exiting...\n" << std::endl;
            connectionHandler.close();
            std::exit;
            break;
        }
    }
    return 0;
}
