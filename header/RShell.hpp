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
<<<<<<< HEAD
    string terminalCommand;
=======
    string terminalLine;
>>>>>>> a78a393043d8d865f43f4b993245d2c9a36dd704
    vector<Base*> input;
  public:
   void printDollarSign() {
       cout << "$";
   };
   void setInput();
   void parse();
   void program();
   void addInput(Base*);
   void reset();
  
};
#endif
