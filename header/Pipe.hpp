#ifndef PIPE_HPP
#define PIPE_HPP
#include "Connectors.hpp"
#include "UserCommand.hpp"
using namespace std;

class Pipe : public Connectors {
 private:
  UserCommand* lhs;
  UserCommand* rhs;
 public:
  Pipe() {
   lhs = 0;
   rhs = 0;
  };
  Pipe(UserCommands* left, UserCommand* right);
  void evaluate();
  
};
#endif
