cmake_minimum_required(VERSION 3.9)
project(assign_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(assign_1 main.cpp src/Server.cpp src/Server.h src/Client.cpp src/Client.h src/Proxy.cpp src/Proxy.h src/HttpHeader.cpp src/HttpHeader.h)

include_directories(src)