#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "command.h"
#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM " \t\r\n\a"
int get_commands(char* line, struct command mycommands[])
{
 
    /*
    TODO: Fill in code here to do the following:
    -Parse the line and fill in the mycommands array
    -Return the number of commands read 
    */
   int bufsize =TOKEN_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token, **tokens_backup;
  int command_count=0;
  int no_of_args = 1;
  int order = 0;
  if (!tokens) {
    exit(EXIT_FAILURE);
  }

  token = strtok(line, TOKEN_DELIM);
  while (token != NULL) {
    tokens[position] = token;
   if(strcmp(token,"|") == 0)
            {
		command_count ++; 
		order ++;
                position = 0;
                no_of_args = 1;
    token = strtok(NULL, TOKEN_DELIM);
		}
   if(position == 0)
{
    mycommands[command_count].comm = token;
    mycommands[command_count].order= order;
}
   else
   {
    mycommands[command_count].args[no_of_args]  =  (char *)malloc(TOKEN_BUFSIZE);
    memcpy(mycommands[command_count].args[no_of_args],token,TOKEN_BUFSIZE);
    mycommands[command_count].no_args= no_of_args;
     no_of_args ++; 
   }
   position++;
   
    if (position >= bufsize) {
      bufsize += TOKEN_BUFSIZE;
      tokens_backup = tokens;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
		free(tokens_backup);
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, TOKEN_DELIM);
  }
  tokens[position] = NULL; 
    return command_count+1;
}
