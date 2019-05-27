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
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;

void RShell::parse () {
  std::string parsedCMD;
  int i = 0;

  bool parseArguments = false;
  UserCommands* currentCMD;
    
  while(i < terminalCommand.size()) {
    if(terminalCommand.at(i) != ' '){
        if(terminalCommand.at(i) == '&' || terminalCommand.at(i) == '|' || terminalCommand.at(i) == ';' || terminalCommand.at(i) == '#') {
      	    parsed.push_back(currentCMD);
	    parseArguments = false;
	    if (terminalCommand.at(i) == ';') {
	    	parsed.push_back(new UserCommands(";"));
	    }
	    else if (terminalCommand.at(i) == '#') {
	        break;
	    }
	    i++;
	    if (i < terminalCommand.size()) {
		if(terminalCommand.at(i) == '&') {
		    parsed.push_back(new UserCommands("&&"));
		    i++;
		}
		else if(terminalCommand.at(i) == '|') {
		    parsed.push_back(new UserCommands("||"));
		    i++;
		}
      	    }
	    while(terminalCommand.at(i) == ' ' && i < terminalCommand.size()) {
		i++;
	    }
	}
      parsedCMD += terminalCommand.at(i);
      i++;
       
    }else{ //if there's a space, then that indicates the start of the arguments or something else
      //this assumes no pipes/ampersands/etc., in order for those to work that'd require an if-statement to break off the currentCMD from the next
      //aka, pushing it back to the vector and then starting with a new currentCMD object
      if(!parseArguments){
	currentCMD = new UserCommands(parsedCMD);
	currentCMD->addArguments(parsedCMD); //a program always has the argument of itself
	parseArguments = true; //we now have the program, need to decipher its arguments
      }
      else{
	currentCMD->addArguments(parsedCMD);
      }
      while(terminalCommand.at(i) == ' ' && i < terminalCommand.size()){ //advance past any trailing spaces
	i++;
      }
      parsedCMD.clear(); //empty the string for the next command or argument
    }
  }

  if(parsedCMD.size() > 0){ //meaning we still have to account for the last command
    if(!parseArguments){ //meaning the last command is a program
      currentCMD = new UserCommands(parsedCMD);
      currentCMD->addArguments(parsedCMD);
      parsed.push_back(currentCMD);
    }else{ //meaning the last command is just an argument
      currentCMD->addArguments(parsedCMD);
      parsed.push_back(currentCMD);
    }
    parsedCMD.clear();
  }

  /*
    char * token = strtok(temp, " ;|&#"); 
    while (token != NULL) {                                                 
    UserCommands* yeet = new UserCommands(token);
    parsed.push_back(yeet);
    token = strtok(NULL, " ;|&#");
    }
  */
    
  //cout << "This is the size of vector: " << parsed.size() << endl;
  //cout << "Parsed at 0: " <<  parsed.at(0)->returnCommand() << endl;
	
  //parse part 2(this populates parsed2 vector, creating a vector of connectors
  unsigned save = -1; //index where we read a comment if you make one.
  unsigned j = 0;

  //having a connector implies more than one command
  if(parsed.size() > 1) {
    for(int i = 0; i < parsed.size(); i++){
      if(parsed.at(i)->returnCommand() == ";"){
	Semicolon* semi;
	if(i != 0 && i != parsed.size() - 1){
	  semi = new Semicolon(parsed.at(i-1), parsed.at(i+1));
	}
	if(i == 0){
	  semi = new Semicolon(NULL, parsed.at(i+1));
	}
	if(i == parsed.size() - 1){
	  semi = new Semicolon(parsed.at(i-1),NULL);
	}
	parsed2.push_back(semi);
      }

      if(parsed.at(i)->returnCommand() == "||"){
	Pipe* pipe;
	if(i != 0 && i != parsed.size() - 1){
	  pipe = new Pipe(parsed.at(i-1), parsed.at(i+1));
	}
	if(i == 0){
	  pipe = new Pipe(NULL, parsed.at(i+1));
	}
	if(i == parsed.size() - 1){
	  pipe = new Pipe(parsed.at(i-1),NULL);
	}
	parsed2.push_back(pipe);
      }

      if(parsed.at(i)->returnCommand() == "&&"){
	Ampersand* amp;
	if(i != 0 && i != parsed.size() - 1){
	  amp = new Ampersand(parsed.at(i-1), parsed.at(i+1));
	}
	if(i == 0){
	  amp = new Ampersand(NULL, parsed.at(i+1));
	}
	if(i == parsed.size() - 1){
	  amp = new Ampersand(parsed.at(i-1),NULL);
	}
	parsed2.push_back(amp);
      }

      if(parsed.at(i)->returnCommand() == "#"){
	save = i;
	break;
      }
    
      else if(parsed.at(i)->returnCommand() != "&&" || parsed.at(i)->returnCommand() != "||" || parsed.at(i)->returnCommand() != ";" ||parsed.at(i)->returnCommand() != "#") {
         Semicolon* dummy = new Semicolon(); // never should execute, just makes sure that parsed2.size() == parsed.size(), for future coding
         parsed2.push_back(dummy);
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

    //i'm assuming this function creates the commands and arguments pairing.
    //that isn't necessary with having the UserCommand have immediate knowledge of each command and argument it has
    //createCommands(parsed);
}

void RShell::setInput(string inp) {
  terminalCommand = inp;
}

bool commandError = false;
//inverted boo
void RShell::program() {
  //cout << "$";
  for (unsigned i = 0; i < parsed.size(); i++) {
    if (parsed.at(i)->returnCommand() == "exit"  && parsed.at(i)->ExecuteStatus()) {
      exited = true;
      exit(1);
    }
	    
    else {
      if(parsed.at(i)->ExecuteStatus()) {
	parsed.at(i)->DoNotExecute();
	pid_t pid = fork();
	//pid_t pid = 0;
	if(pid < 0) {
	  perror("Fork() failed.");
	}
	else if (pid == 0) {
	  //this is where the execvp happens, and where we need to decipher the program name and arguments
	  std::string program = parsed.at(i)->returnCommand();
	  vector<string> stringArgs = parsed.at(i)->returnArguments();
	  vector<char *> realArgs;

	  for(int i = 0; i < stringArgs.size(); i++){
	    char* temp;
	    strcpy(temp, stringArgs.at(i).c_str());
	    realArgs.push_back(temp);
	  }

	  //the NULL for the end of the args list
	  realArgs.push_back(NULL);

	  //this uses the vector's internal array as the args list,
	  //which is just a clever way of going from <char*>vector -> char* []
	  if(program == "&&" || program == "#" || program == ";" || program == "||") {
		  parsed2.at(i)->evaluate();
	  }
	  else if(execvp(program.c_str(), &realArgs[0]) == -1) {
	    commandError = true;
	    perror("Command Error");
	    exit(0);
	  }
	  cout.flush();
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

void RShell::reset() {
	input.clear();
	parsed.clear();
	parsed2.clear();
}
