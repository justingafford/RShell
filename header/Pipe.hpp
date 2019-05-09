#ifndef PIPE_HPP
#define PIPE_HPP
#include "Connectors.hpp"
using namespace std;

class Pipe:: public Connectors {
 public:
  Base* lhs;
  Base* rhs;
 private:
  void evaluate();
  
};
#endif
