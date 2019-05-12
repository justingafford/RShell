#ifndef AMPERSAND_HPP
#define AMPERSAND_HPP
#include "Connectors.hpp"
#include "UserCommands.hpp"
using namespace std;

class Ampersand : public Connectors {
 private:
   UserCommands* lhs;
   UserCommands* rhs;
 public:
  Ampersand() {
   lhs = 0;
   rhs = 0;
  };
  Ampersand(UserCommands* left, UserCommands* right);
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
