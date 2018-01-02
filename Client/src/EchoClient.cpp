#include <stdlib.h>
#include <iostream>
#include "../include/ConnectionHandler.h"
#include <boost/thread/thread.hpp>
#include "./ClientWriter.cpp"

/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/
int main (int argc, char *argv[]) {
//    if (argc < 3) {
//        std::cerr << "Usage: " << argv[0] << " host port" << std::endl << std::endl;
//        return -1;
//    }
//    std::string host = argv[1];
//    short port = atoi(argv[2]);
    std::string host = "127.0.0.1";
    short port = 2000;


    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    } else
        std::cout << "connected to server" << std::endl;
    ClientWriter writer(connectionHandler);
    boost::thread WriterThread(writer);


    //From here we will see the rest of the ehco client implementation:
    while (true) {
        std::string answer;
        size_t len;
        if (!connectionHandler.getLine(answer)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
        len = answer.length();
        // A C string must end with a 0 char delimiter.  When we filled the answer buffer from the socket
        // we filled up to the \n char - we must make sure now that a 0 char is also present. So we truncate last character.
        answer.resize(len - 1);
        std::cout << "Reply: " << answer << " " << len << " bytes " << std::endl << std::endl;
        if (answer == "bye") {
            std::cout << "Exiting...\n" << std::endl;
            WriterThread.boost::interrupt();
            connectionHandler.set_shouldTerminate(true);
            break;
        }

    }
    return 0;
}
