cmake_minimum_required(VERSION 3.9)
project(assign_3)

set(CMAKE_CXX_STANDARD 11)

add_executable(assign_3 main.cpp src/FileParser.cpp src/FileParser.h src/Edge.cpp src/Edge.h src/Graph.cpp src/Graph.h src/Node.cpp src/Node.h src/Dijkstra.cpp src/Dijkstra.h src/PrintHelper.cpp src/PrintHelper.h)

include_directories(src)