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
                const short bufsize = 1024;
                char buf[bufsize];
                std::cin.getline(buf, bufsize);
                std::string line(buf);
                size_t len = line.length();

                if (!_handler.sendLine(line)) {
//                    std::cout << "Disconnected. Exiting...\n" << std::endl;
                    break;
                }
                if (line.compare("SIGNOUT")==0){
                    while(!_handler.getSignoutAnswerReviced()){

                    }
                    _handler.setAnswerReadByWriterThread(true);
                    if(_handler.isSignoutAnswer())
                        break;
                    _handler.setSignoutAnswerReviced(false);


                }

            }
            std::cout << "Writer Thread Disconnected. Exiting...\n" << std::endl;


    }



};
 