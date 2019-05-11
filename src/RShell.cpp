#include "RShell.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void RShell::program () {

}

void RShell::setInput(string input) {
	terminalLine = input;
}

void RShell::parse() {

}

void RShell::reset() {
	input.clear();
}
