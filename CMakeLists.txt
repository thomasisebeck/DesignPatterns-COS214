cmake_minimum_required(VERSION 3.23)
project(COS214)

set(CMAKE_CXX_STANDARD 14)

include_directories("COS 214 Coding/Lecture code/MyFlyweight")

add_executable(COS214
        "COS 214 Coding/Lecture code/MyFlyweight/FlyweightTest.cpp"
        "COS 214 Coding/Lecture code/MyFlyweight/Goodie.h"
        "COS 214 Coding/Lecture code/MyFlyweight/Player.h"
        "COS 214 Coding/Lecture code/MyFlyweight/PlayerFactory.h"
        "COS 214 Coding/Lecture code/MyFlyweight/Terrorist.h")
