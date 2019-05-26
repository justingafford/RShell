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
        cout.flush();
    };
  
    vector<Base*> accessInput () {
        return input;
    };
    bool commentCreated () {
        return createdComment;
    };
    void createCommands() {
        for(unsigned i = 0; i < parsedd.size(); i++) {     
             char* commandTemp = new char[parsedd.at(i)->returnCommand().size()]; 
             strcpy(commandTemp,parsedd.at(i)->returnCommand().c_str());
             parsedd.at(i)->argument()[i] = commandTemp;
        }
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
