cmake_minimum_required(VERSION 3.23)
project(COS214)

set(CMAKE_CXX_STANDARD 14)

include_directories("COS 214 Coding/Practicals/Practical3")

add_executable(COS214
        "COS 214 Coding/Practicals/Practical3/AeratedChocolate.h"
        "COS 214 Coding/Practicals/Practical3/Aero.h"
        "COS 214 Coding/Practicals/Practical3/CadburyFactory.h"
        "COS 214 Coding/Practicals/Practical3/Chocolate.h"
        "COS 214 Coding/Practicals/Practical3/Confectionary.h"
        "COS 214 Coding/Practicals/Practical3/ConfectionaryFactory.h"
        "COS 214 Coding/Practicals/Practical3/DairyMilk.h"
        "COS 214 Coding/Practicals/Practical3/DairyMilkBubbly.h"
        "COS 214 Coding/Practicals/Practical3/Lindor.h"
        "COS 214 Coding/Practicals/Practical3/LindtFactory.h"
        "COS 214 Coding/Practicals/Practical3/main.cpp"
        "COS 214 Coding/Practicals/Practical3/MilkyBar.h"
        "COS 214 Coding/Practicals/Practical3/NestleFactory.h")
