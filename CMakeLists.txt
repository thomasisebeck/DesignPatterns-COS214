cmake_minimum_required(VERSION 3.23)
project(COS214)

set(CMAKE_CXX_STANDARD 14)

include_directories("COS 214 Coding/Practicals/Practical 1 Specifications/Given/Task6")

add_executable(COS214
        "COS 214 Coding/Practicals/Practical 1 Specifications/Given/Task6/AuditableSnapshot.h"
        "COS 214 Coding/Practicals/Practical 1 Specifications/Given/Task6/main.cpp"
        "COS 214 Coding/Practicals/Practical 1 Specifications/Given/Task6/Snapshot.cpp"
        "COS 214 Coding/Practicals/Practical 1 Specifications/Given/Task6/Snapshot.h"
        "COS 214 Coding/Practicals/Practical 1 Specifications/Given/Task6/User.cpp"
        "COS 214 Coding/Practicals/Practical 1 Specifications/Given/Task6/User.h"
        "COS 214 Coding/Practicals/Practical 1 Specifications/Given/Task6/UserManager.cpp"
        "COS 214 Coding/Practicals/Practical 1 Specifications/Given/Task6/UserManager.h")
