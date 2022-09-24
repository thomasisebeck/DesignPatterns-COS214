cmake_minimum_required(VERSION 3.23)
project(COS214)

set(CMAKE_CXX_STANDARD 14)

include_directories("COS 214 Coding/Practicals/Practical4/Task3")

add_executable(COS214
        "COS 214 Coding/Practicals/Practical4/Task3/BackupMemento.h"
        "COS 214 Coding/Practicals/Practical4/Task3/BackupOriginator.h"
        "COS 214 Coding/Practicals/Practical4/Task3/COS214_PA04.pdf"
        "COS 214 Coding/Practicals/Practical4/Task3/Directory.cpp"
        "COS 214 Coding/Practicals/Practical4/Task3/Directory.h"
        "COS 214 Coding/Practicals/Practical4/Task3/File.h"
        "COS 214 Coding/Practicals/Practical4/Task3/main.cpp"
        "COS 214 Coding/Practicals/Practical4/Task3/makefile"
        "COS 214 Coding/Practicals/Practical4/Task3/Navigator.h"
        "COS 214 Coding/Practicals/Practical4/Task3/NavigatorMemento.h"
        "COS 214 Coding/Practicals/Practical4/Task3/Node.h"
        "COS 214 Coding/Practicals/Practical4/Task3/NodeIterator.h")
