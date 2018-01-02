#include <stdlib.h>
#include <iostream>
#include "../include/ConnectionHandler.h"
#include <boost/thread/thread.hpp>

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
    }
    else
        std::cout<<"connected to server"<<std::endl;


    //From here we will see the rest of the ehco client implementation:
    while (true) {
//        try {//checks if thread was interrupted
//            boost::this_thread::interruption_point();
//        }
//        catch (boost::thread_interrupted&) {//
//            std::cout << "Disconnected. Exiting...\n" << std::endl;
//            break;
//        }
        const short bufsize = 1024;
        char buf[bufsize];
        std::cin.getline(buf, bufsize);
        std::string line(buf);
        int len=line.length();
        if (!connectionHandler.sendLine(line)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
        // connectionHandler.sendLine(line) appends '\n' to the message. Therefor we send len+1 bytes.
        std::cout << "Sent " << len+1 << " bytes to server" << std::endl;


        // We can use one of three options to read data from the server:
        // 1. Read a fixed number of characters
        // 2. Read a line (up to the newline character using the getline() buffered reader
        // 3. Read up to the null character

    }
    return 0;
}