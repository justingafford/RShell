#ifndef POUND_HPP
#define POUND_HPP
#include "Connectors.hpp"
using namespace std;

class Pound : public Connectors {
 private:
  Base* lhs;
  Base* rhs;
 public:
  Pound() {
   lhs = 0;
   rhs = 0;
  };
  Pound(Base* left, Base* right);
  void evaluate();
  
};
#endif
