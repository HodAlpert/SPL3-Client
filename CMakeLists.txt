cmake_minimum_required(VERSION 3.8)
project(SPL3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Client/include/ConnectionHandler.h Client/src/ConnectionHandler.cpp Client/src/EchoClient.cpp Client/src/ClientListener.cpp)
add_executable(SPL3 ${SOURCE_FILES} Client/include/ConnectionHandler.h Client/src/ConnectionHandler.cpp Client/src/EchoClient.cpp Client/src/ClientListener.cpp)

# get BOOST librery
find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
endif()

if(Boost_FOUND)
    target_link_libraries(SPL3 ${Boost_LIBRARIES})
endif()