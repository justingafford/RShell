 #include "../header/Ampersand.hpp"
 #include <iostream>
 
using namespace std;

Ampersand::Ampersand(UserCommands* left, UserCommands* right) {
   lhs = left;
   rhs = right;
 }
void Ampersand::evaluate() {
   if (!lhs->ExecuteStatus()) {
     rhs->DoExecute();
   }
   else {
     rhs->DoNotExecute();
   }
}
