#ifndef RSHELL_HPP
#define RSHELL_HPP
#include <iostream>
#include "Base.hpp"
#include "UserCommands.hpp"
#include "Connectors.hpp"
#include "Ampersand.hpp"
#include "Pipe.hpp"
#include "Semicolon"
using namespace std;

class RShell {
  public:
   //sting userCommand;
   void printDollarSign() {
       cout << "$";
   };
   void program();
};
#endif
