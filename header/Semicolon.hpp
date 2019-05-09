#ifndef SEMICOLON_HPP
#define SEMICOLON_HPP
#include "Connectors.hpp"
using namespace std;

class Semicolon:: public Connectors {
 private:
  Base* lhs;
  Base* rhs;
 public:
  Semicolon () { 
    lhs = 0;
    rhs = 0;
  };
  Semicolon(Base* left,Base* right);
  void evaluate();
  
};
#endif
