#ifndef CONNECTORS_HPP
#define CONNECTORS_HPP
#include "Base.hpp"
using namespace std;

class Connectors: class Base {
 public:
  Base* lhs;
  Base* rhs;
 private:
  void evaluate();
  
};
#endif
