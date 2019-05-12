#ifndef BASE_HPP
#define BASE_HPP
#include <string>
using namespace std;

class Base {
 protected:
  Base* lhs;
  Base* rhs;
  char* deezArgs[1024];
 public:
  Base() {
    lhs = 0;
    rhs = 0;
  };
  virtual bool ExecuteStatus() = 0;
  virtual char ** argument() = 0;
  virtual string returnCommand() = 0;
  virtual void DoExecute() = 0;
  virtual void DoNotExecute() = 0;
  virtual void evaluate() = 0;

 
};
#endif
