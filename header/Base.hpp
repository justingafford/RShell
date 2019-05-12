#ifndef BASE_HPP
#define BASE_HPP
using namespace std;

class Base {
 protected:
  Base* lhs;
  Base* rhs;
  char* argument[256];
 public:
  Base() {
    lhs = 0;
    rhs = 0;
  };
  virtual string returnCommand();
  virtual void DoExecute();
  virtual void DoNotExecute();
  virtual void evaluate() = 0;

 
};
#endif
