#include "../header/RShell.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include <stdio.h> 
#include <sys/wait.h>
using namespace std;

void RShell::parse () {
    //this creates the parsed list.
    char * temp = new char[terminalCommand.length() + 1];             
    strcpy(temp, terminalCommand.c_str());                                  
    
    char * token = strtok(temp, ";|&#"); 
    while (token != NULL) {                                                 
       UserCommands* yeet = new UserCommands(token);
       parsed.push_back(yeet);
       token = strtok(NULL, ";|&#");
    }
    //cout << "This is the size of vector: " << parsed.size() << endl;
    //cout << "Parsed at 0: " <<  parsed.at(0)->returnCommand() << endl;
    //parse part 2(this populates input vector by allocating new variables of type UserCommands
    // and Connectors)
	
    unsigned save = -1; //index where we read a comment if you make one.
    for (unsigned i = 0; i < parsed.size(); i++) {
	//cout << "7" << endl;
	if(parsed.size() > 2) {
		if(parsed.at(i)->returnCommand() == ";") {
			//cout << "8" << endl;
	        	Semicolon* semi = new Semicolon(parsed.at(i - 1),parsed.at(i + 1));
			input.push_back(semi);
	    	}
		else if(parsed.at(i)->returnCommand() == "||") {
			//cout << "9" << endl;
        		Pipe* pip = new Pipe(parsed.at(i - 1),parsed.at(i + 1));
		    	input.push_back(pip);
		}
		else if (parsed.at(i)->returnCommand() == "&&") {
			//cout << "10" << endl;
            		Ampersand* amp = new Ampersand(parsed.at(i - 1),parsed.at(i + 1));
			input.push_back(amp);
		}
		else if (parsed.at(i)->returnCommand() == "#") {
			//cout << "11" << endl;
	    		save = i;
	    		break;
        	}
		else {
	    		UserCommands* comm = new UserCommands();
			//cout << "12" << endl;
			comm = parsed.at(i);
			//cout << "13" << endl;
	    		input.push_back(comm);
		}    
	}
	else {
		if(parsed.at(i)->returnCommand() == ";" || parsed.at(i)->returnCommand() == "||" || parsed.at(i)->returnCommand() == "&&") {
			cout << "Error: connectors(';','||','&&') must have a left and right operand." << endl;
			//cout << "14" << endl;
		}
		else {
			if(parsed.at(i)->returnCommand() == "#") {
				//cout << "15" << endl;
				save = i;
				break;
			}
			else { //parsed.at(i) is a UserCommand
				UserCommands* comm = new UserCommands();
				//cout << "16" << endl;
				comm = parsed.at(i);
				//cout << "17" << endl;
	    			input.push_back(comm);
			}
		}
	}
    } 
    
	//part 3(creates comments.txt file
    if(save != -1) {
        ofstream ofs;	
        ofs.open("comments.txt");
        if(ofs.is_open()) {
            for(unsigned j = save; j < parsed.size();j++) {
	        //write parsed[j] to comment section;
		//cout << "18" << endl;
                ofs << parsed.at(j);
		//cout << "19" << endl;
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
