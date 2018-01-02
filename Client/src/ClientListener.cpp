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
        // Get back an answer: by using the expected number of bytes (len bytes + newline delimiter)
        // We could also use: connectionHandler.getline(answer) and then get the answer without the newline char at the end
        len=answer.length();
        // A C string must end with a 0 char delimiter.  When we filled the answer buffer from the socket
        // we filled up to the \n char - we must make sure now that a 0 char is also present. So we truncate last character.
        answer.resize(len-1);
        std::cout << "Reply: " << answer << " " << len << " bytes " << std::endl << std::endl;
        if (answer == "bye") {
            std::cout << "Exiting...\n" << std::endl;
            break;
        }
    }
};
 