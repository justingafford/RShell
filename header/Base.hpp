#ifndef BASE_HPP
#define BASE_HPP
using namespace std;

class Base {
 protected:
  Base* lhs;
  Base* rhs;
 public:
  Base() {
    lhs = 0;
    rhs = 0;
  };
  virtual void evaluate() = 0;
  virtual string returnType () { return "";}
 
};
#endif
