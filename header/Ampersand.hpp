#ifndef AMPERSAND_HPP
#define AMPERSAND_HPP
#include "Connectors.hpp"
using namespace std;

class Ampersand:: public Connectors {
 public:
  Base* lhs;
  Base* rhs;
 private:
  Ampersand() {
   lhs = 0;
   rhs = 0;
  };
  Ampersand(Base* left, Base* right);
  void evaluate();
  
};
#endif
