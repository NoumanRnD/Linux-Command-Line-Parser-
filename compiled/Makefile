all: parser

parser: parser.o print_commands.o get_commands.o
	gcc -g -o parser parser.o print_commands.o get_commands.o

parser.o: parser.c command.h print_commands.h get_commands.h
	gcc -g -c parser.c

print_commands.o: print_commands.c command.h
	gcc -g -c print_commands.c

get_commands.o: get_commands.c command.h
	gcc -g -c get_commands.c

clean:
	rm -f parser *.o
