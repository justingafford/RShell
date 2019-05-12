 #include "../header/Pipe.hpp"
 #include <iostream>
 
using namespace std;

Pipe::Pipe(UserCommands* left, UserCommands* right) {
   lhs = left;
   rhs = right;
 }
void Pipe::evaluate() {
   if (!lhs->ExecuteStatus()) {
     rhs->DoExecute();
   }
   else {
     rhs->DoNotExecute();
   }
}
