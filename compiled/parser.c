#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "command.h"
#include "print_commands.h"
#include "get_commands.h"
int status = 1;
char *readline(void)
{
	int bufsize = MAX_CHAR_LINE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer) {
		exit(EXIT_FAILURE);
	}

	while (1) {
		// Read a character
		c = getchar();
		if (c == EOF || c == '\n') {
			buffer[position] = '\0';
			return buffer;
		} else {
			buffer[position] = c;
		}
		position++;
		if (position >= bufsize) {
			bufsize += MAX_CHAR_LINE;
			buffer = realloc(buffer, bufsize);
			if (!buffer) {
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}


int main()
{
	char *prompt = "cmps405> ";
	char **args;
	int no_of_commands;
	char line[MAX_CHAR_LINE];   
	struct command mycommands[MAX_COMMANDS];
	while(1)
	{
		/*
TODO: Fill in code here to do the following:
-Display the prompt
-Read a line from the user
-Call the function get_commands to parse the line and place
its contents into mycommands
-Call the function print_commands to print the commands in mycommands

Note:
-If the user enters "exit" then this program should quit.
		 */

		printf("%s",prompt);
		memset(line,'\0',MAX_CHAR_LINE);
		memcpy(line,readline(),MAX_CHAR_LINE);
		if(strcmp(line,"exit") == 0)
			break;
                else if(strcmp(line,"\r\n") == 0)
                {}
		else
		{
			no_of_commands = get_commands(line,mycommands);
			print_commands(mycommands,no_of_commands);
		}

	}
	return 0;
}
