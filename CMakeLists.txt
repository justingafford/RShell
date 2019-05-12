main:
    $(CC) $(CFLAGS) -c ../src/main.cpp
unit_test:
    $(CC) $(CFLAGS) -c ../unit_tests/unit_test.cpp
ampersand:
    $(CC) $(CFLAGS) -c ../src/Ampersand.cpp
pipe:
    $(CC) $(CFLAGS) -c ../src/Pipe.cpp
rshell:
    $(CC) $(CFLAGS) -c ../src/RShell.cpp
semicolon:
    $(CC) $(CFLAGS) -c ../src/Semicolon.cpp
usercommands:
    $(CC) $(CFLAGS) -c ../src/UserCommands.cpp

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 
ADD_SUBDIRECTORY(googletest)
 
SET(CMAKE_CXX_STANDARD 11)
 
ADD_EXECUTABLE(RShell
    ampersand
    pipe
    rshell
    semicolon
    usercommands
    main
)
 
ADD_EXECUTABLE(test
    ampersand
    pipe
    rshell
    semicolon
    usercommands
    unit_test
)
 
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
