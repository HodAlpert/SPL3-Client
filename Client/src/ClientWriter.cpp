#include <iostream>
#include "../include/ConnectionHandler.h"
#include <boost/thread.hpp>

class ClientWriter {
private:
    ConnectionHandler &_handler;

public:
    ClientWriter(ConnectionHandler &handler) : _handler(handler) {}

    void operator()() {
        while (!_handler.isShould_terminate()) {
            try {//checks if thread was interrupted
                boost::this_thread::interruption_point();
                const short bufsize = 1024;
                char buf[bufsize];
                std::cin.getline(buf, bufsize);
                std::string line(buf);
                size_t len = line.length();
                if (!_handler.sendLine(line)) {
                    std::cout << "Disconnected. Exiting...\n" << std::endl;
                    break;
                }
//                if(line.compare("SIGNOUT")==0) {
//                    break;
//                }
//                std::cout << line << std::endl;
            }

            catch (boost::thread_interrupted &) {//
                break;
            }
        }
    }


};
 