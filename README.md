# Linux-Command-Line-Parser-

# Goal
  Strengthening students’ skills in gaining new knowledge in C coding particularly, with string
processing and pointers
#Description
  Homeworks 3 and 4 will involve developing a basic shell (command line interpreter) for Linux.
In this assignment, HW3, you will build the portion of the shell that parses a user-entered command
sequence so that it can later be executed. In this portion of the assignment you are only building a
parser for the commands, you don’t actually execute them yet. Instead you print out the details of
the parsed commands.
  You are given a skeleton code and required to build on it to achieve this task. The user entry is a
number of commands with their arguments, if any, separated by pipes, if any.
Here are some valid, sample inputs:
  ls –la
  ls –la | wc –l
  ls | grep “something” | sort | wc –l
  
#  Functionality
  A basic shell is just an infinite loop that prints a print, receives a line of user input, and executes the
appropriate programs. In this assignment, you will only write the parser.
Consider the following pseudo-code for this assignment:
> Infinite loop
    The program displays a prompt,
    The user enters a commands on a line,
    The program reads the line,
       if the user entry is spaces or empty line, then perform next iteration of the
      loop i.e., continue
       if the user entry is a special command, exit, then exit the loop i.e., break
    Parse the commands, i.e., recognize the commands and store them in an array of a
      given formatted structure,
    Call a provided function, print_commands, to display the information about
    these commands
    Display the prompt again, waiting for the user to enter another command.
> end
