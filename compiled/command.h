#define MAX_CHAR_LINE 1024
#define MAX_NO_ARGS 10
#define MAX_COMMANDS 10

struct command
{
    char *comm;
    char *args[MAX_NO_ARGS+2]; //the first item is the command itself and the last is NULL
    int no_args;//actual number of arguments excluding the first item, command name, and the last item, NULL.
    int order;//the order of the command 0, 1, ...
};
