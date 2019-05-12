#ifndef RSHELL_HPP
#define RSHELL_HPP
#include <iostream>
#include "Base.hpp"
#include "UserCommands.hpp"
#include "Connectors.hpp"
#include "Ampersand.hpp"
#include "Pipe.hpp"
#include "Semicolon.hpp"
using namespace std;

class RShell {
  private:
    string terminalCommand;
    vector<UserCommands*> parsed;
    vector<Base*> input;
    string currFunction;
    bool exited = false;
  public:
   void printDollarSign() {
       cout << "$";
   };
   bool didExit() {
       return exited;
   }; 
   void setInput(string);
   void parse();
   void program();
   void reset();
  
};
#endif
