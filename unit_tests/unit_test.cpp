#include "../header/Ampersand.hpp"
#include "../header/Base.hpp"
#include "../header/Connectors.hpp"
#include "../header/Pipe.hpp"
#include "../header/RShell.hpp"
#include "../header/Semicolon.hpp"
#include "../header/UserCommands.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>

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

TEST(RShellTests, SingleCommandTest) {
    RShell test;
    string command = "echo hello";
    test.setInput(command);
    test.parse();
    test.program();
    ASSERT_EQ(test.accessParsed().at(0)->returnCommand(),"echo hello");
    ASSERT_EQ(test.accessParsed().size(),1);
    test.reset();
    ASSERT_EQ(test.accessParsed().empty(),true);
    ASSERT_EQ(test.accessInput().empty(),true);
}

TEST(RShellTests, MultipleCommandTest) {
    RShell test;
    string command = "echo hello && echo world || mkdir test";
    test.setInput(command);
    test.parse();
    test.program();
    ASSERT_EQ(test.accessParsed().at(0)->returnCommand(),"echo hello ");
    ASSERT_EQ(test.accessParsedTwo().at(0)->returnCommand(),"&&");
    ASSERT_EQ(test.accessParsed().at(1)->returnCommand()," echo world ");
    ASSERT_EQ(test.accessParsedTwo().at(1)->returnCommand(),"||");
    ASSERT_EQ(test.accessParsed().at(1)->returnCommand()," mkdir test");
    ASSERT_EQ(test.accessParsed().size(),3);
    ASSERT_EQ(test.accessParsedTwo().size(),2);
    test.reset();
    ASSERT_EQ(test.accessParsed().empty(),true);
    ASSERT_EQ(test.accessInput().empty(),true);
}

TEST(RShellTests, CommentedCommandTest) {
    RShell test;
    string command = "echo test #&& this is a test";
    test.setInput(command);
    test.parse();
    test.program();
    ASSERT_EQ(test.accessParsed().at(0)->returnCommand(),"echo test ");
    ASSERT_EQ(test.commentCreated(),true);
    test.reset();
    ASSERT_EQ(test.accessParsed().empty(),true);
    ASSERT_EQ(test.accessInput().empty(),true);
}

TEST(ExitTests, BasicExit) {
    RShell test;
    string command = "exit";
    test.setInput(command);
    test.parse();
    test.program();
    test.reset();
}

TEST(ExitTests, ExitWithCommands) {
    RShell test;
    string command = "echo exiting && exit";
    test.setInput(command);
    test.parse();
    test.program();
    test.reset();
    ASSERT_EQ(test.returnExited(),true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
