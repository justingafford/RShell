#ifndef SEMICOLON_HPP
#define SEMICOLON_HPP
#include "Connectors.hpp"
using namespace std;

class Semicolon:: public Connectors {
 public:
  Base* lhs;
  Base* rhs;
 private:
  Semicolon () { 
    lhs = 0;
    rhs = 0;
  };
  Semicolon(Base* left,Base* right);
  void evaluate();
  
};
#endif
