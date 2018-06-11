#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "command.h"

void print_commands(struct command mycommands[], int no_commands)
{
    int i;
    for(i=0; i<no_commands; i++)
    {
        int j;
        fputs("command order: ", stdout);
        fprintf(stdout,"%d",mycommands[i].order);
        fputs("\n",stdout);
        fputs("command: ", stdout);
        fputs(mycommands[i].comm, stdout);
        fputs("\n",stdout);
        fputs("no of args: ", stdout);
        fprintf(stdout,"%d",mycommands[i].no_args);
        fputs("\n",stdout);
        fputs("args: ", stdout);
        for(j=1; j<=mycommands[i].no_args; j++)
        {
            fputs(mycommands[i].args[j], stdout);
            fputs(" ",stdout);
        }
        fputs("\n",stdout);
    }
}