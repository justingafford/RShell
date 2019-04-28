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

__base__

__connectors__

__userCommands__

__semicolon__

__and__

__or__

### Prototypes/Research

### Roadmaps/Issues
