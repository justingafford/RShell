 #include "../header/Semicolon.hpp"
 #include <iostream>
 
using namespace std;

Semicolon::Semicolon(UserCommands* left, UserCommands* right) {
   lhs = left;
   rhs = right;
 }
void Semicolon::evaluate() {
   lhs->DoExecute();
   rhs->DoExecute();
}
