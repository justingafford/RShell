#ifndef PIPE_HPP
#define PIPE_HPP
#include "Connectors.hpp"
using namespace std;

class Pipe:: public Connectors {
 public:
  Base* lhs;
  Base* rhs;
 private:
  Pipe() {
   lhs = 0;
   rhs = 0;
  };
  Pipe(Base* left, Base* right);
  void evaluate();
  
};
#endif
