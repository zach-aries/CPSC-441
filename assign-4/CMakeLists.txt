cmake_minimum_required(VERSION 3.9)
project(assign_4)

set(CMAKE_CXX_STANDARD 11)

add_executable(assign_4 main.cpp src/binary_tree.cpp src/binary_tree.h src/tree_processor.cpp src/tree_processor.h)

include_directories(src)