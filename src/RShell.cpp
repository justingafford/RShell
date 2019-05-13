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
	
		if(terminalCommand.at(i) == ';') {
	    	UserCommands* temp = new UserCommands;
	    	temp->setCommand(";");
    	    parsed.push_back(temp);
		}
		else if(terminalCommand.at(i) == '|') {
	    	UserCommands* temp = new UserCommands;
	    	temp->setCommand("||");
    	    parsed.push_back(temp);
		}
		else if(terminalCommand.at(i) == '&') {
	    	UserCommands* temp = new UserCommands;
	    	temp->setCommand("&&");
    		parsed.push_back(temp);
		}
		else if(terminalCommand.at(i) == '#') {
	    	UserCommands* temp = new UserCommands;
	    	temp->setCommand("#");
    	    parsed.push_back(temp);
		}
    	else if(terminalCommand.at(i) != '\n') {
	    	UserCommands* temp = new UserCommands;
	    	temp->setCommand(currFunction);
    		parsed.push_back(temp);
   		}
    }

    //parse part 2(this populates input vector by allocating new variables of type UserCommands
    // and Connectors
    unsigned save = -1;
    for (unsigned i = 0; i < parsed.size(); i++) {
		if(parsed.size() > 2) {
			if(parsed.at(i)->returnCommand() == ";") {
	        	Semicolon* semi = new Semicolon(parsed.at(i-1),parsed.at(i+1));
				input.push_back(semi);
	    	}
			else if(parsed.at(i)->returnCommand() == "||") {
        		Pipe* pip = new Pipe(parsed.at(i-1),parsed.at(i+1));
		    	input.push_back(pip);
			}
			else if (parsed.at(i)->returnCommand() == "&&") {
            	Ampersand* amp = new Ampersand(parsed.at(i-1),parsed.at(i+1));
				input.push_back(amp);
			}
			else if (parsed.at(i)->returnCommand() == "#") {
	    		save = i;
	    		break;
        	}
			else {
	    		UserCommands* comm = new UserCommands();
				comm = parsed.at(i);
	    		input.push_back(comm);
			}    
	    }
		else {
			if(parsed.at(i)->returnCommand() == ";" || parsed.at(i)->returnCommand() == "||" || parsed.at(i)->returnCommand() == "&&") {
				cout << "Error: connectors(';','||','&&') must have a left and right operand." << endl;
			}
			else {
				if(parsed.at(i)->returnCommand() == "#") {
					save = i;
					break;
				}
				else { //parsed.at(i) is a UserCommand
					UserCommands* comm = new UserCommands();
					comm = parsed.at(i);
	    			input.push_back(comm);
				}
			}
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
  	    createdComment = true;
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
    for (unsigned i = 0; i < input.size(); i++) {
        if (input.at(i)->returnCommand() == "exit") {
	    exited = true;
            exit(1);
        }
	if(input.at(i)->returnCommand() == ";" || input.at(i)->returnCommand() == "&&" || input.at(i)->returnCommand() == "||")
	    input.at(i)->evaluate();
	else {
	    if(input.at(i)->ExecuteStatus()) {
			input.at(i)->DoNotExecute();
			pid_t pid = fork();
		if(pid < 0) {
		    perror("Fork() failed.");
		}
		else if (pid == 0) {
		    if(execvp((input.at(i)->argument()[0]),input.at(i)->argument()) == -1)
		        perror("Command Error.");
		    exit(0);
		}
	        else {
	            while(wait(0) != pid);
                    input.at(i)->DoExecute();
	        }    
            }
	}
    }  
}

void RShell::reset() {
	input.clear();
	parsed.clear();
}
