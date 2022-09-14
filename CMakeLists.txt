cmake_minimum_required(VERSION 3.23)
project(COS214)

set(CMAKE_CXX_STANDARD 14)

include_directories("COS 214 Coding/Practicals/Practical4/Task1")

add_executable(COS214
        "COS 214 Coding/Practicals/Practical4/Task1/Directory.cpp"
        "COS 214 Coding/Practicals/Practical4/Task1/Directory.h"
        "COS 214 Coding/Practicals/Practical4/Task1/File.h"
        "COS 214 Coding/Practicals/Practical4/Task1/main.cpp"
        "COS 214 Coding/Practicals/Practical4/Task1/Node.h")
