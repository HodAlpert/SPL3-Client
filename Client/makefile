# Flags
CC = g++
CFLAGS  = -std=c++11 
BFLAGS  = -lboost_thread -lboost_system
LFLAGS  = -L/usr/lib

# All Targets
all: BBclient

# Tool invocations
BBclient: bin/ClientWriter.o bin/ConnectionHandler.o bin/EchoClient.o
	@echo 'Building targets'
	@echo 'Invoking: C++ Linker'
	$(CC) -o bin/BBClient bin/ClientWriter.o bin/ConnectionHandler.o bin/EchoClient.o $(LFLAGS) $(BFLAGS)
	@echo 'Finished building targets'
	@echo ' '
	
# ConnectionHandler
bin/ConnectionHandler.o: src/ConnectionHandler.cpp
	$(CC) $(CFLAGS) -c -Iinclude src/ConnectionHandler.cpp -o bin/ConnectionHandler.o

# ClientWriter
bin/ClientWriter.o: src/ClientWriter.cpp
	$(CC) $(CFLAGS) -c -Iinclude src/ClientWriter.cpp -o bin/ClientWriter.o

# EchoClient
bin/EchoClient.o: src/EchoClient.cpp
	$(CC) $(CFLAGS) -c -Iinclude src/EchoClient.cpp -o bin/EchoClient.o

# Clean the build directory
clean: 
	rm -f bin/*
