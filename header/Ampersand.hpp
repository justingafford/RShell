#ifndef AMPERSAND_HPP
#define AMPERSAND_HPP
#include "Connectors.hpp"
using namespace std;

class Ampersand:: public Connectors {
 public:
  Base* lhs;
  Base* rhs;
 private:
  void evaluate();
  
};
#endif
