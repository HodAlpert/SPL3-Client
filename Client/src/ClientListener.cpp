#include <iostream>
#include <boost/thread.hpp>
#include "../include/ConnectionHandler.h"
using namespace boost::this_thread;

class ClientListener {
private:
    ConnectionHandler _handler;
    bool _shouldTerminate;
public:
    ClientListener (ConnectionHandler& handler) : _handler(handler),_shouldTerminate(false) {}

    void operator()(){
        std::string answer;
        while(_handler.getLine(answer))
        boost::this_thread::yield(); //Gives up the remainder of the current thread's time slice, to allow other threads to run. 
    }
};
 