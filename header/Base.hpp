#ifndef BASE_HPP
#define BASE_HPP
using namespace std;

class Base {
 public:
  Base* lhs;
  Base* rhs;
  Base() {
    lhs = 0;
    rhs = 0;
  };
 private:
  virtual void evaluate() = 0;
  
};
#endif
