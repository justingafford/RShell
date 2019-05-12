#include "../header/RShell.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unistd.h> 
#include <stdio.h> 
#include <sys/wait.h>
using namespace std;

void RShell::parse () {
    stringstream ss;
    //parse part 1(put commands into vector of strings)
    for(unsigned i = 0; i < terminalCommand.size();  i++) {
    
    while(terminalCommand.at(i) != ';'|| terminalCommand.at(i) !='&'  || terminalCommand.at(i)!='|' || terminalCommand.at(i)!='#' || terminalCommand.at(i) = '/n' ) {
	ss << terminalCommand.at(i); 
	ss >> currFunction; 
	i++;
    }
    if(terminalCommand.at(i) != '\n') {
	UserCommands* temp = new UserCommands;
	temp->setCommand(currFunction);
    	parsed.push_back(temp);
   }
}
//parse part 2(this populates input vector by allocating new variables of type UserCommands
// and Connectors
unsigned save = -1;
for (unsigned i = 0; i < parsed.size(); i++) {
    if(parsed.at(i)->returnCommand() == ";") {
        if(i > 0 && i < parsed.size()) {
	    Semicolon semi = new Semicolon(parsed.at(i-1),parsed.at(i+1));
	    else if (i > 1 && i == parsed.size()) {
		Semicolon* semi = new Semicolon(parsed.at(i-1),"");
	    }
	    else if (parsed.size() ==1) {
   		Semicolon* semi = new Semicolon();
	    }
	input.push_back(semi);
    }
    else if(parsed.at(i)->returnCommand() == "||") {
        if(i > 0 && i < parsed.size()) {
	    Pipe* pip = new Pipe(parsed.at(i-1),parsed.at(i+1));
	    else if (i > 1 && i == parsed.size()) {
		    Pipe* pip= new Pipe(parsed.at(i-1),"");
	    }
	    else if (parsed.size() ==1) {
   		Pipe* pip= new Pipe();
	    }
	    input.push_back(pip);
        }
        else if (parsed.at(i)->returnCommand() == "&&") {
            if(i > 0 && i < parsed.size()) {
	        Ampersand amp = new Ampersand(parsed.at(i-1),parsed.at(i+1));
	        else if (i > 1 && i == parsed.size()) {
		     Ampersand* amp = new Ampersand(parsed.at(i-1),"");
	        }
	        else if (parsed.size() ==1) {
   		     Ampersand* amp = new Ampersand();
	        }
	        input.push_back(amp);
        }
        else if (parsed.at(i)->returnCommand() = = "#") {
	    save = i;
	    break;
        }
        else if (parsed.size() != 0) {
	    UserCommands* comm = new UserCommands[parsed.at(i)];
	    input.push_back(comm);
        }
    }
//part 3
    if(save != -1) {
        ofstream ofs;	
        ofs.open("comments.txt");
        if(ofs.is_open()) {
            for(unsigned j = save; j < parsed.size();j++) {
	
                //write parsed[j] to comment section;
                ofs << parsed.at(j);
            }
            ofs.close();	
        }
        else {
            cout << "Error creating comment section" << endl;
        }
    }

}

void RShell::setInput(string input) {
	terminalCommand = input;
}

void RShell::program() {

}

void RShell::reset() {
	input.clear();
}
