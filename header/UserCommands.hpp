#ifndef USERCOMMANDS_HPP
#define USERCOMMANDS_HPP
#include "Base.hpp"
#include <iostream>
#include <vector> //use a queue to hold usercommands
#include <string>
using namespace std;

class UserCommands: public Base {
 private:
  vector<string> arguments;
  string command; //represents the user command i.e. echo,etc.
  bool execute; //does the command execute?
  char* deezArgs[1024];
 public:
  UserCommands () {
   command = "";
   execute = true;
  };
  UserCommands (string comm) {
   command = comm;
   execute = true;
  };
  void setCommand(string c) {
    command = c;
  };
  string returnCommand() {
    return command;
  };
  vector<std::string> returnArguments(){
    return arguments;
  };
  char ** argument() {
    return deezArgs;
  };
  void addArguments(string arg){
    arguments.push_back(arg);
  }
  void evaluate();
  void DoNotExecute();
  void DoExecute();
  bool ExecuteStatus();
};
#endif
