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
    bool createdComment = false;
    bool exited = false;
  public:
   void printDollarSign() {
       cout << "$";
   };
  
   vector<Base*> accessInput () {
     vector<Base*> temp = input;
     return temp;
   };
  
  vector<UserCommands*> accessParsed () {
     vector<UserCommands*> temp = parsed;
     return temp;
   };
      
   bool returnExited() {
        return exited;
   };
   void setInput(string);
   void parse();
   void program();
   void reset();
  
};
#endif
