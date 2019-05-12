#include "../header/Ampersand.hpp"
#include "../header/Base.hpp"
#include "../header/Connectors.hpp"
#include "../header/Pipe.hpp"
#include "../header/RShell.hpp"
#include "../header/Semicolon.hpp"
#include "../header/UserCommands.hpp"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;

TEST(UserCommandsTest, ExecuteTest) {
    UserCommands* test = new UserCommands();
    test->DoNotExecute();
    ASSERT_EQ(test->ExecuteStatus(),false);
    test->DoExecute();
    ASSERT_EQ(test->ExecuteStatus(),true);
    
}

TEST(ConnectorsTests, Semicolon) {
    UserCommands* left = new UserCommands("echo hello");
    UserCommands* right = new UserCommands("echo world");
    Semicolon* semi = new Semicolon(left,right);
    semi->evaluate();
    ASSERT_EQ(left->ExecuteStatus(),true);
    ASSERT_EQ(right->ExecuteStatus(),true);
    
}

TEST(ConnectorsTests, Pipe) {
    UserCommands* left = new UserCommands();
    UserCommands* right = new UserCommands();
    Pipe* pip = new Pipe(left,right);
    left->DoNotExecute();
    right->DoNotExecute();
    pip->evaluate();
    ASSERT_EQ(left->ExecuteStatus(),false);
    ASSERT_EQ(right->ExecuteStatus(),true);
}

TEST(ConnectorsTests, Ampersand) {
    UserCommands* left = new UserCommands();
    UserCommands* right = new UserCommands();
    Ampersand* amp = new Ampersand(left,right);
    left->DoNotExecute();
    right->DoExecute();
    amp->evaluate();
    ASSERT_EQ(left->ExecuteStatus(),false);
    ASSERT_EQ(right->ExecuteStatus(),false);
}

TEST(RShellTests, ExitTest) {
}

TEST(RShellTests, SingleCommandTest) {
    
}

TEST(RShellTests, MultipleCommandTest) {
    
}

TEST(RShellTests, CommentedCommandTest) {
    
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
