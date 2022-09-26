cmake_minimum_required(VERSION 3.23)
project(COS214)

set(CMAKE_CXX_STANDARD 14)

include_directories("COS 214 Coding/Practicals/Practical4/Task5")

add_executable(COS214
        "COS 214 Coding/Practicals/Practical4/Task5/BackupCaretaker.h"
        "COS 214 Coding/Practicals/Practical4/Task5/BackupMemento.h"
        "COS 214 Coding/Practicals/Practical4/Task5/BackupOriginator.h"
        "COS 214 Coding/Practicals/Practical4/Task5/ConcreteObserver.h"
        "COS 214 Coding/Practicals/Practical4/Task5/COS214_PA04.pdf"
        "COS 214 Coding/Practicals/Practical4/Task5/Directory.cpp"
        "COS 214 Coding/Practicals/Practical4/Task5/Directory.h"
        "COS 214 Coding/Practicals/Practical4/Task5/File.h"
        "COS 214 Coding/Practicals/Practical4/Task5/main.cpp"
        "COS 214 Coding/Practicals/Practical4/Task5/makefile"
        "COS 214 Coding/Practicals/Practical4/Task5/Navigator.h"
        "COS 214 Coding/Practicals/Practical4/Task5/NavigatorMemento.h"
        "COS 214 Coding/Practicals/Practical4/Task5/Node.h"
        "COS 214 Coding/Practicals/Practical4/Task5/NodeIterator.h"
        "COS 214 Coding/Practicals/Practical4/Task5/Observer.h"
        "COS 214 Coding/Practicals/Practical4/Task5/Root.h")
