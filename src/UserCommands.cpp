#include "UserCommands.hpp"
#include <iostream>

using namespace std;

void evaluate() {
  
}

void DoNotExecute() {
  execute = false;
}

void DoExecute() {
  execute = true;
}

bool ExecuteStatus() {
  return execute;
}
