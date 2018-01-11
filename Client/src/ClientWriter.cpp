#include <iostream>
#include "../include/ConnectionHandler.h"
#include <boost/thread.hpp>

class ClientWriter {
private:
    ConnectionHandler &_handler;

public:
    ClientWriter(ConnectionHandler &handler) : _handler(handler) {}

    void operator()() {
        while (true) {
                const short bufsize = 1024;
                char buf[bufsize];
                if(_handler.isShould_terminate()){
                    std::string finalLine("TERMINATE");
                    _handler.sendLine(finalLine);
                    std::cout << "Disconnected. Exiting...\n" << std::endl;
                    break;
                }
                std::cin.getline(buf, bufsize);
                std::string line(buf);
                size_t len = line.length();

                if (!_handler.sendLine(line)) {
//                    std::cout << "Disconnected. Exiting...\n" << std::endl;
                    break;
                }
            }


    }



};
 