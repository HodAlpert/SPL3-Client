cmake_minimum_required(VERSION 3.8)
project(SPL3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Client/include/ConnectionHandler.h Client/src/ConnectionHandler.cpp Client/src/EchoClient.cpp Client/src/ClientWriter.cpp Client/include/ClientWriter.h Client/src/ConnectionHandler.cpp)
add_executable(SPL3 ${SOURCE_FILES} Client/include/ConnectionHandler.h Client/src/ConnectionHandler.cpp Client/src/EchoClient.cpp Client/src/ClientWriter.cpp)

# get BOOST librery
find_package(Boost COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)
    target_link_libraries(SPL3 ${Boost_LIBRARIES})
endif()
