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
    //this creates the list of commands i.e. echo test, mkdir yeet, etc
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
	
    //parse part 2(this populates parsed2 vector, creating a vector of connectors
    unsigned save = -1; //index where we read a comment if you make one.
    unsigned j = 0;
    if(parsed.size() > 2) {
    	for (unsigned i = 0; i < terminalCommand.size(); i++) {
	//cout << "7" << endl;
		if(terminalCommand.at(i) == ';') {
			//cout << "8" << endl;
		
	        	Semicolon* semi = new Semicolon(parsed.at(j),parsed.at(j + 1));
			parsed2.push_back(semi);
			j++;
	    	}
		else if(terminalCommand.at(i) == '|' && terminalCommand.at(i+1) == '|' ) {
			//cout << "9" << endl;
        		Pipe* pip = new Pipe(parsed.at(j),parsed.at(j + 1));
		    	parsed2.push_back(pip);
			j++;	
		}
		else if (terminalCommand.at(i) == '&' && terminalCommand.at(i+1) == '&') {
			//cout << "10" << endl;
			
            		Ampersand* amp = new Ampersand(parsed.at(j),parsed.at(j + 1));
		 	parsed2.push_back(amp);
		}
		else if (terminalCommand.at(i) == '#') {
			//cout << "11" << endl;
	    		save = i;
	    		break;
        	}		
	}
    }
    else {
	for (unsigned i = 0; i < terminalCommand.size(); i++) {
	    if(terminalCommand.at(i) == ';' || terminalCommand.at(i) == '|' || terminalCommand.at(i) == '&') {
		cout << "Error: connectors(';', '||' and '&&') must have a left and right operand." << endl;
		break;
		//cout << "14" << endl;
	    }
	    else if(terminalCommand.at(i) == '#') {
		//cout << "15" << endl;
		save = i;
		break;
	    }
			
	}
    } 
    
	//part 3(creates comments.txt file
    if(save != -1) {
        ofstream ofs;	
        ofs.open("comments.txt");
        if(ofs.is_open()) {
            for(unsigned k = save; k < terminalCommand.size();k++) {
	        //write parsed[j] to comment section;
		//cout << "18" << endl;
                ofs << terminalCommand.at(k);
		//cout << "19" << endl;
            }
            ofs.close();
  	    createdComment = true;
     	}
        else {
            cout << "Error creating comment section" << endl;
        }
    }
	
    int inputSize = parsed.size() + parsed2.size();
    int itr1 = 0;
    int itr2 = 0;
    while(input.size() != inputSize) {
	if(itr1 < parsed.size()) {
	    input.push_back(parsed.at(itr1));
	    itr1++;
	}
	if(itr2 < parsed2.size()) {
	    input.push_back(parsed2.at(itr2));
  	    itr2++;
	}
    }
    createCommands(parsed);
}

void RShell::setInput(string inp) {
	terminalCommand = inp;
}
bool commandError = false;
void RShell::program() {
    for (unsigned i = 0; i < parsed.size(); i++) {
        if ((parsed.at(i)->returnCommand() == "exit" || parsed.at(i)->returnCommand() == " exit"  || parsed.at(i)->returnCommand() == "exit " || parsed.at(i)->returnCommand() == " exit ") && parsed.at(i)->ExecuteStatus()) {
	    exited = true;
            exit(1);
        }
	    
	else if(i < parsed2.size() &&(parsed2.at(i)->returnCommand() == ";" || parsed2.at(i)->returnCommand() == "&&" || parsed2.at(i)->returnCommand() == "||"))
	    parsed2.at(i)->evaluate();
	else {
	    if(parsed.at(i)->ExecuteStatus()) {
		parsed.at(i)->DoNotExecute();
		pid_t pid = fork();
		if(pid < 0) {
		    perror("Fork() failed.");
		}
		else if (pid == 0) {
		    if((execvp((parsed.at(i)->argument()[0]),parsed.at(i)->argument()) == -1)) {
			commandError = true;
		        perror("Command Error.");
		    	exit(0);
		    }
	            else {
			commandError = true;
	            	while(wait(0) != pid);
                    	parsed.at(i)->DoExecute();
	            }    
            	}
	    }
        }
	
    }
}

void RShell::reset() {
	input.clear();
	parsed.clear();
	parsed2.clear();
}
