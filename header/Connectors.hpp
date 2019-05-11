#ifndef CONNECTORS_HPP
#define CONNECTORS_HPP
#include "Base.hpp"
using namespace std;

class Connectors: public Base {
 protected:
  Base* lhs;
  Base* rhs;
 public:
  virtual void evaluate() = 0;
  
};
#endif
