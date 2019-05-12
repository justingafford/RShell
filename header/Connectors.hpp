#ifndef CONNECTORS_HPP
#define CONNECTORS_HPP
#include "Base.hpp"
using namespace std;

class Connectors: public Base {
 protected:
  Base* lhs;
  Base* rhs;
 public:
  void evaluate() {}
  bool ExecuteStatus() {return true;}
  char ** argument() {
      char * placeholder[0];
      return placeholder;
  }
  string returnCommand() {}
  void DoExecute() {}
  void DoNotExecute() {}
  
};
#endif
