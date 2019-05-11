#include "Ampersand.hpp"
#include "Base.hpp"
#include "Connectors.hpp"
#include "Pipe.hpp"
#include "RShell.hpp"
#include "Semicolon.hpp"
#include "UserCommands.hpp"
#include <iostream>
#include <unistd.h> //Linux standard library

using namespace std;

int main () {
  string commandLine;
  RShell xd;
  
  while(commandLine != "exit") {
    xd->printDollarSign();
    getline(cin, commandLine); //we use getline so that once you hit enter(i.e. \n) you stop writing to commandLine.
    if(commandLine == exit) {
      break;
    }
    else {
      rshell.setInput(commandLine);
      rshell.parse();
      rshell.execute();
      rshell.clear();
    }
  }
  
    
