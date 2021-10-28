#include <stdio.h>
#include <string.h>

/*
memchr looks for the first occurence of the specified byte given as
the second argument in specified bytes given as third argument.
returns null if no occurence. returns the remaining string after
first occurence found.
*/


int main(){
	const char *s = "This is a string";
	
	printf("%s\'%c\'%s\"%s\"\n",
		"The remainder of s after char ", 'r',
		" is found is ", (char *) memchr(s, 'r', 10));
}
