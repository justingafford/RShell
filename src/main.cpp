#include "../header/Ampersand.hpp"
#include "../header/Base.hpp"
#include "../header/Connectors.hpp"
#include "../header/Pipe.hpp"
#include "../header/RShell.hpp"
#include "../header/Semicolon.hpp"
#include "../header/UserCommands.hpp"
#include <iostream>
#include <unistd.h> //Linux standard library

using namespace std;

int main () {
  string commandLine;
  RShell xd;
  
  while(!xd.exited()) {
    xd.printDollarSign();
    getline(cin, commandLine); //we use getline so that once you hit enter(i.e. \n) you stop writing to commandLine.
    if(commandLine == "exit") {
      break;
    }
    else {
      xd.setInput(commandLine);
      xd.parse();
      xd.program();
      xd.reset();
    }

  }
}    
