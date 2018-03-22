cmake_minimum_required(VERSION 3.9)
project(assign_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(assign_2 main.cpp src/Debug.cpp src/Debug.h src/Server.cpp src/Server.h src/Client.cpp src/Client.h src/FileHelper.cpp src/FileHelper.h src/Protocol.cpp src/Protocol.h)

include_directories(src)