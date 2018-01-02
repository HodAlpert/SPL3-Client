#flags
CC = g++
CFLAGS  = -std=c++11 
BFLAG   = -lboost_thread -lboost_system
LFLAGS  = -L/usr/lib

# All Targets
all: BBclient

# Tool invocations
BBclient: bin/ClientWriter.o bin/ConnectionHandler.o bin/EchoClient.o
	@echo 'Building targets'
	@echo 'Invoking: C++ Linker'
	$(CC) -o bin/ClientWriter.o bin/ConnectionHandler.o bin/EchoClient.o $(LFLAGS)
	@echo 'Finished building targets'
	@echo ' '
	
# ConnectionHandler
bin/ConnectionHandler.o: src/ConnectionHandler.cpp
	$(CC) $(CFLAGS) -c -Iinclude bin/ConnectionHandler.o src/ConnectionHandler.cpp
	$(CC) $(CFLAGS)  bin/ConnectionHandler.o  $(BFLAGS) -o src/ConnectionHandler.cpp
# EchoClient
bin/EchoClient.o: src/EchoClient.cpp
	$(CC) $(CFLAGS) -c -Iinclude bin/EchoClient.o -o src/EchoClient.cpp
	$(CC) $(CFLAGS)  bin/EchoClient.o  $(BFLAGS) -o src/EchoClient.cpp
# ClientWriter
bin/ClientWriter.o: src/ClientWriter.cpp
	$(CC) $(CFLAGS) -c -Iinclude bin/ClientWriter.o -o src/ClientWriter.cpp
	$(CC) $(CFLAGS) bin/ClientWriter.o  $(BFLAGS) -o src/ClientWriter.cpp
	
#Clean the build directory
clean: 
	rm -f bin/*
