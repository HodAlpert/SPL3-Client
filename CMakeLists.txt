cmake_minimum_required(VERSION 3.8)
project(SPL3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Client/include/ConnectionHandler.h Client/src/ConnectionHandler.cpp Client/src/EchoClient.cpp)
add_executable(SPL3 ${SOURCE_FILES} Client/include/ConnectionHandler.h Client/src/ConnectionHandler.cpp Client/src/EchoClient.cpp)