# CS 100 Programming Project
Spring 2019,

Justin Gafford jgaff001@ucr

Wayland Chang wchan051@ucr.edu

### Introduction
In this project we are creating the basis for a command shell that can compile a command in a command prompt and execute them according to the specifications defined in our class descriptions. In terms of formatting, the user can can use any combination of '&&', '||' or ';' as 'connectors' which connect multiple commands, allowing them all to compile at once. In order to accomplish this, we have a base class which all other classes inherit from, a connector class which the semicolon, and, and or class inherit, and a command class which stores user inputs.

As specified by the Assignment 2 manual, we must build a program in the following steps:
```
1. Print a command prompt (e.g. `$`)
2. Read in a line of command(s) (and connector(s)) from standard input
3. Execute the appropriate commands using fork, execvp, and waitpid
```

### UML Diagram

### Class Descriptions
__rshell__

rshell acts as the main user interface class. In this class, the user is prompted for an input. After the input is recieved, we pass in this command and then finally, execute it.

__base__

This b

__connectors__

Functionally the connectors class is the class which the semicolon, or, and and classes are derived from(in our program these classes would be ';', '||' and '&&', respectively.) We have two base pointers, which represent the two operands in each operation. You may link together the constuction of the connector classes in order to compile multiple lines of code at once (i.e. command1 || command2 && command3).

__userCommands__

This is where all user commands waiting to be compiled are stored. These commands are stored in a vector and have set instructions to execute a program(s).

__semicolon__

__and__

__or__

### Prototypes/Research

### Roadmaps/Issues
