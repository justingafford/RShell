#ifndef USERCOMMANDS_HPP
#define USERCOMMANDS_HPP
#include "Base.hpp"
#include <iostream>
#include <vector> //use a queue to hold usercommands
#include <string>
using namespace std;

class UserCommands: public Base {
 private:
  string command; //represents the user command i.e. echo,etc.
  bool execute; //does the command execute?
 public:
  UserCommands () {
  };
  void setCommand(string comm) {
   command = comm;
  };
  
  void evaluate();
  void DidNotExecute();
  void DidExecute();
  bool ExecuteStatus();
};
#endif
