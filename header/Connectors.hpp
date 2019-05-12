#ifndef CONNECTORS_HPP
#define CONNECTORS_HPP
#include "Base.hpp"
using namespace std;

class Connectors: public Base {
 protected:
  Base* lhs;
  Base* rhs;
 public:
  virtual bool ExecuteStatus() = 0;
  virtual char ** argument() = 0;
  virtual string returnCommand() = 0;
  virtual void DoExecute() = 0;
  virtual void DoNotExecute() = 0;
  virtual void evaluate() = 0;
  
};
#endif
