#ifndef RSHELL_HPP
#define RSHELL_HPP
#include <iostream>
#include <cstring>
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
    vector<Connectors*> parsed2;
    vector<Base*> input;
    string currFunction;
    bool createdComment = false;
    bool exited = false;
  public:
    void printDollarSign() {
        cout << "$";
    };
  
    vector<Base*> accessInput () {
        return input;
    };
    void createCommands(vector<UserCommands*> parsedd){
       char * temp = new char[terminalCommand.length() + 1];             
       strcpy(temp, terminalCommand.c_str());                                  
       char * token = strtok(temp, " ;|&#"); 
       while (token != NULL) {                                                 
            argument.push_back(yeet);
            token = strtok(NULL, " ;|&#");
      }
    };
    bool commentCreated () {
        return createdComment;
    };
    vector<UserCommands*> accessParsed () {
        return parsed;
    };
    vector<Connectors*> accessParsedTwo () {
        return parsed2;
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
