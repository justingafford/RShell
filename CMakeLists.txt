$(CC) $(CFLAGS) -c ../src/main.cpp
$(CC) $(CFLAGS) -c ../src/Ampersand.cpp
$(CC) $(CFLAGS) -c ../src/Pipe.cpp
$(CC) $(CFLAGS) -c ../src/RShell.cpp
$(CC) $(CFLAGS) -c ../src/Semicolon.cpp
$(CC) $(CFLAGS) -c ../src/UserCommands.cpp

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 
ADD_SUBDIRECTORY(googletest)
 
SET(CMAKE_CXX_STANDARD 11)
 
ADD_EXECUTABLE(RShell
    Ampersand.cpp
    Pipe.cpp
    RShell.cpp
    Semicolon.cpp
    UserCommands.cpp
    main.cpp
)
 
ADD_EXECUTABLE(test
    Ampersand.cpp
    Pipe.cpp
    RShell.cpp
    Semicolon.cpp
    UserCommands.cpp
    unit_test.cpp
)
 
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
