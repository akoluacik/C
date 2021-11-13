/*****************************************************************
(Printing Command-Line Arguments) Write a program that prints the 
command-line  arguments of the program.
******************************************************************/

#include <stdio.h>

int main(int argc, char *argv[]){ // argv[0] holds the name of the executable file
    int i;
    if(argc == 1){ // if no arguments passed, give info about usage.
        puts("Usage: filename [arguments]");
        return 0;
    }
    for(i = 1; i < argc; ++i)
        printf("%s\n", argv[i]);
    
}