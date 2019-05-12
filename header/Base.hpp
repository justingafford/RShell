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
  virtual bool ExecuteStatus();
  virtual char ** argument();
  virtual string returnCommand();
  virtual void DoExecute();
  virtual void DoNotExecute();
  virtual void evaluate() = 0;

 
};
#endif
