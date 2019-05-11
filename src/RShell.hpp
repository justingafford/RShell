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
    string terminalLine;
    vector<Base*> input;
  public:
   void printDollarSign() {
       cout << "$";
   };
   void setInput(string);
   void parse();
   void program();
   void addInput(Base*);
   void reset();
  
};
#endif

