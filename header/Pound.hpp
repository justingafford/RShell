#ifndef POUND_HPP
#define POUND_HPP
#include "Connectors.hpp"
#include "UserCommands.hpp"
using namespace std;

class Pound : public Connectors {
 private:
  UserCommands* lhs;
  UserCommands* rhs;
 public:
  Pound() {
   lhs = 0;
   rhs = 0;
  };
  Pound(UserCommands* left, UserCommands* right);
  void evaluate();
  
};
#endif
