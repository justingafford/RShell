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
    
    		while(terminalCommand.at(i) != ';'|| terminalCommand.at(i) !='&'  || terminalCommand.at(i)!='|' || terminalCommand.at(i)!='#' || terminalCommand.at(i) != '/n' ) {
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
	bool zeroset = false;
	if (parsed.size() > 1) {
	for (unsigned i = 1; i < parsed.size() - 1; i++) {
		
    		if(parsed.at(i)->returnCommand() == ";") {
        		if(i < parsed.size() && zeroset) {
	    			Semicolon* semi = new Semicolon(parsed.at(i-1),parsed.at(i+1));
				input.push_back(semi);
			}
			else if (i > 1 && i == parsed.size() && zeroset) {
					UserCommands* cmd = new UserCommands();
					Semicolon* semi = new Semicolon(parsed.at(i-1),cmd);
					input.push_back(semi);
					
				}
			}
			else if(parsed.at(0)->returnCommand = ";" && !zeroset) {
				Semicolon* semi= new Semicolon(cmd,parsed.at(1));
				input.push_back(semi);
				zeroset = true;
		
			}
    		}
		
		else if(parsed.at(i)->returnCommand() == "||") {
        		if(i < parsed.size() && zeroset) {
	    			Pipe* pip = new Pipe(parsed.at(i-1),parsed.at(i+1));
				input.push_back(pip);
			}
	    		else if (i > 1 && i == parsed.size() && zeroset) {
				UserCommands* cmd = new UserCommands();
		    		Pipe* pip= new Pipe(parsed.at(i-1),cmd);
				input.push_back(pip);
	    		}
	    		else if(parsed.at(0)->returnCommand = "&&" && !zeroset) {
				Pipe* pip= new Pipe(cmd,parsed.at(1));
				input.push_back(pip);
				zeroset = true;
				
			}
	    
        	}
		
        	else if (parsed.at(i)->returnCommand() == "&&") {
            		if(i < parsed.size() && zeroset) {
	        		Ampersand* amp = new Ampersand(parsed.at(i-1),parsed.at(i+1));
				input.push_back(amp);
			}
	        	else if (i > 1 && i == parsed.size() && zeroset) {
				UserCommands* cmd = new UserCommands();
		     		Ampersand* amp = new Ampersand(parsed.at(i-1),cmd);
				input.push_back(amp);
	        	}
	        	
	        	else if(parsed.at(0)->returnCommand = "&&" && !zeroset) {
				Pipe* amp= new Ampersand(cmd,parsed.at(1));
				input.push_back(amp);
				zeroset = true;
			}
        	}
			
        	else if (parsed.at(i)->returnCommand() == "#") {
	    		save = i;
	    		break;
        	}
			
        	else {
	    		UserCommands* comm = new UserCommands();
			comm = parsed.at(i);
	    		input.push_back(comm);
			if(!zeroset) {
				comm = parsed.at(i);
	    			input.push_back(comm);
				zeroset = true;
			}
        	}
	}
	}
	else if(parsed.size() == 1) {
		if (parsed.at(i)->returnCommand() == "#") {
	    		save = i;
	    		break;
        	}
		else if (parsed.at(0)->returnCommand = ";") {
			Semicolon* semi= new Semicolon();
			input.push_back(semi);
		}
		else if(parsed.at(0)->returnCommand = "||") {
			Pipe* pip= new Pipe();
			input.push_back(pip);
		}
		else if (parsed.at(0)->returnCommand = "&&") {
			Ampersand* amp= new Ampersand();
			input.push_back(amp);
		}
		else {
	    		UserCommands* comm = new UserCommands();
			comm = parsed.at(i);
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
