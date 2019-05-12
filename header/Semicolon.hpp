#ifndef SEMICOLON_HPP
#define SEMICOLON_HPP
#include "Connectors.hpp"
#include "UserCommands.hpp"
using namespace std;

class Semicolon : public Connectors {
 private:
   UserCommands* lhs;
   UserCommands* rhs;
 public:
  Semicolon () { 
    lhs = 0;
    rhs = 0;
  };
  Semicolon(UserCommands* left,UserCommands* right);
  bool ExecuteStatus() {return true;}
  char ** argument() {
      return deezArgs;
  }
  string returnCommand() {}
  void DoExecute() {}
  void DoNotExecute() {}
  void evaluate();
  
};
#endif
