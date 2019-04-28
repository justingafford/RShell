# CS 100 Programming Project
Spring 2019,

Justin Gafford jgaff001@ucr

Wayland Chang wchan051@ucr.edu

### Introduction
In this project we are creating the basis for a command shell that can compile a command in a command prompt and execute them according to the specifications defined in our class descriptions. In terms of formatting, the user can can use any combination of '&&', '||' or ';' as 'connectors' which connect multiple commands, allowing them all to compile at once. In order to accomplish this, we have a base class which all other classes inherit from, a connector class which the semicolon, ampersand, and pipe class inherit, and a command class which stores user inputs.

As specified by the Assignment 2 manual, we must build a program in the following steps:
```
1. Print a command prompt (e.g. `$`)
2. Read in a line of command(s) (and connector(s)) from standard input
3. Execute the appropriate commands using fork, execvp, and waitpid
```

### UML Diagram

### Class Descriptions
__rshell__

rshell acts as the main user interface class. In this class, the user is prompted for an input. After the input is recieved, we pass in this command and then finally, execute it. The rshell class redirects to the base class in order to start the functionality of the program.

__base__

The base class establishes a composite pattern for our program as it contains a pure virtual function(virtual void evaluate()), which all other classes inherit from, allowing them to evaluate/compile commands that are passed in by the user. Both the connectors class and the userCommands class extend to the base class.

__connectors__

Functionally the connectors class is the class which the semicolon, pipe, and ampersand classes are derived from(in our program these classes would be ';', '||' and '&&', respectively.) We have two base pointers, which represent the two operands in each operation. You may link together the constuction of the connector classes in order to compile multiple lines of code at once (i.e. command1 || command2 && command3). This class extends to the base class. Furthermore, the connectors class has a virtual void evaluate() function which all its derived classes(semicolon,ampersand,pipe) inherit and implement functionality to.

__userCommands__

This is where all user commands waiting to be compiled are stored. These commands are stored in a vector and have set instructions to execute a program(s). We have two base pointers, representing the two operands in each operation stored in the vector. This class extends to base class. In the userCommands class, we define a evaluate function which evaluates each user command, interpretting their functionality.

__semicolon__

The semicolon class inherits from the connectors class, and is represented in our program by the ';' symbol. This allows multiple commands to be executed at once using its evaluate function, as the right operand(right base pointer) of a semicolon will be executed, assuming it exists.

__ampersand__

The ampersand class inherits from the connectors class, and is represented in our program by the '&&' symbol. This allows multiple commands to be executed at once using its evaluate function, as the right operand(right base pointer) of a ampersand call(&&) will be executed if and only if the left operand(left base pointer) succeeded.

__pipe__

The pipe class inherits from the connectors class, and is represented in our program by the '||' symbol. This allows multiple commands to be executed at once using its evaluate function, as the right operand(right base pointer) of a pipe call(||) will be executed if and only if the left operand(left base pointer) failed.

### Prototypes/Research
__fork()__

__execvp()__

__waitpid()__

__Primary websites used for Research:__

* [Prototype](http://www.cs.ecu.edu/karl/4630/sum01/example1.html) - used to help build prototype.

* [fork()](https://www.geeksforgeeks.org/difference-fork-exec/) - used to understand fork() command.

* [execvp()](https://stackoverflow.com/questions/27541910/how-to-use-execvp) - used to understand execvp() command.

* [waitpid()](https://stackoverflow.com/questions/21248840/example-of-waitpid-in-use) - used to understand waitpid() command.

### Roadmaps/Issues
