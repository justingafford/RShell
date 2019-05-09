#ifndef PIPE_HPP
#define PIPE_HPP
#include "Connectors.hpp"
using namespace std;

class Pipe : public Connectors {
 private:
  Base* lhs;
  Base* rhs;
 public:
  Pipe() {
   lhs = 0;
   rhs = 0;
  };
  Pipe(Base* left, Base* right);
  void evaluate();
  
};
#endif
