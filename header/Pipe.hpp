#ifndef PIPE_HPP
#define PIPE_HPP
#include "Connectors.hpp"
#include "UserCommands.hpp"
using namespace std;

class Pipe : public Connectors {
 private:
  UserCommands* lhs;
  UserCommands* rhs;
 public:
  Pipe() {
   lhs = 0;
   rhs = 0;
  };
  Pipe(UserCommands* left, UserCommands* right);
  void evaluate();
  bool ExecuteStatus() {return true;}
  char ** argument() {
      return deezArgs;
  }
  string returnCommand() {return "||";}
  void DoExecute() {}
  void DoNotExecute() {}
  
};
#endif
