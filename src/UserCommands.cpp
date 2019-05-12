#include "../header/UserCommands.hpp"
#include <iostream>

using namespace std;

void UserCommands::evaluate() {
  
}

void UserCommands::DoNotExecute() {
  execute = false;
}

void UserCommands::DoExecute() {
  execute = true;
}

bool UserCommands::ExecuteStatus() {
  return execute;
}

char** UserCommands::getArgument() {
  return argument;
}
