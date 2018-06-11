# Linux-Command-Line-Parser-

# Goal
  Strengthening students’ skills in gaining new knowledge in C coding particularly, with string
processing and pointers
#Description
  Homeworks 3 and 4 will involve developing a basic shell (command line interpreter) for Linux.<br/>
In this assignment, HW3, you will build the portion of the shell that parses a user-entered command<br/>
sequence so that it can later be executed. In this portion of the assignment you are only building a<br/>
parser for the commands, you don’t actually execute them yet. Instead you print out the details of<br/>
the parsed commands.<br/>
  You are given a skeleton code and required to build on it to achieve this task. The user entry is a<br/>
number of commands with their arguments, if any, separated by pipes, if any.<br/>
Here are some valid, sample inputs:<br/>
  ls –la<br/>
  ls –la | wc –l<br/>
  ls | grep “something” | sort | wc –l<br/> 
  
#  Functionality<br/>
  A basic shell is just an infinite loop that prints a print, receives a line of user input, and executes the<br/>
appropriate programs. In this assignment, you will only write the parser.<br/>
Consider the following pseudo-code for this assignment:<br/>
> Infinite loop<br/>
    The program displays a prompt,<br/>
    The user enters a commands on a line,<br/>
    The program reads the line,
       if the user entry is spaces or empty line, then perform next iteration of the<br/>
      loop i.e., continue<br/>
       if the user entry is a special command, exit, then exit the loop i.e., break<br/>
    Parse the commands, i.e., recognize the commands and store them in an array of a<br/>
      given formatted structure,<br/>
    Call a provided function, print_commands, to display the information about<br/>
    these commands<br/>
    Display the prompt again, waiting for the user to enter another command.<br/>
> end
