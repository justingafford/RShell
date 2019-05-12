CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 
ADD_SUBDIRECTORY(googletest)
 
SET(CMAKE_CXX_STANDARD 11)
 
ADD_EXECUTABLE(RShell
    src/Ampersand.cpp
    src/Pipe.cpp
    src/Rshell.cpp
    src/Semicolon.cpp
    src/UserCommands.cpp
    src/main.cpp
)
 
ADD_EXECUTABLE(test
    src/Ampersand.cpp
    src/Pipe.cpp
    src/RShell.cpp
    src/Semicolon.cpp
    src/UserCommands.cpp
    src/unit_test.cpp
)
 
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
