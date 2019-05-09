#ifndef USERCOMMANDS_HPP
#define USERCOMMANDS_HPP
#include "Base.hpp"
#include <iostream>
#include <queue> //use a queue to hold usercommands
using namespace std;

class UserCommands: public Base {
 private:
  queue<Base*> userCommands;
 public:
  UserCommands () {
  };
  //call the destructor whenever we finish user commands(i.e. they press enter, and it compiles)
  ~UserCommands () {
    queue<Base*> empty;
    userCommands = empty;
  };
  UserCommands(Base* comm) {
    userCommands.push(comm);
  };
  void evaluate();
  
};
#endif
