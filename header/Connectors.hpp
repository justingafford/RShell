#ifndef CONNECTORS_HPP
#define CONNECTORS_HPP
#include "Base.hpp"
using namespace std;

class Connectors: class Base {
 protected:
  Base* lhs;
  Base* rhs;
 public:
  void evaluate();
  
};
#endif
