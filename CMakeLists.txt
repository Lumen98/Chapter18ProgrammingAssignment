cmake_minimum_required(VERSION 3.26)
project(Chapter19ProgrammingAssignment)

set(CMAKE_CXX_STANDARD 17)

add_executable(Chapter19ProgrammingAssignment main.cpp
        LinkedList.cpp
        LinkedList.h
        DisplayMenu.cpp
        DisplayMenu.h
        Node.cpp
)
