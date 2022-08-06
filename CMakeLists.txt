cmake_minimum_required(VERSION 3.23)
project(COS214)

set(CMAKE_CXX_STANDARD 14)

include_directories("COS 214 Coding/Practicals/Practical2/Code")

add_executable(COS214
        "COS 214 Coding/Practicals/Practical2/Code/Enemy.cpp"
        "COS 214 Coding/Practicals/Practical2/Code/Enemy.h"
        "COS 214 Coding/Practicals/Practical2/Code/main.cpp"
        "COS 214 Coding/Practicals/Practical2/Code/Snake.cpp"
        "COS 214 Coding/Practicals/Practical2/Code/Snake.h"
        "COS 214 Coding/Practicals/Practical2/Code/SquadMember.cpp"
        "COS 214 Coding/Practicals/Practical2/Code/SquadMember.h")
