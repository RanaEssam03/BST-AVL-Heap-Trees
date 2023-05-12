cmake_minimum_required(VERSION 3.25)
project(BST_AVL_Heap_Trees)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(AVL)

add_executable(BST_AVL_Heap_Trees
        AVL/AVL.cpp
        AVL/AVL.h
        AVL/Node.h
        main.cpp
        Student.h)
