#include <stdio.h>
#include <string.h>

int main(){
	const char *string1 = "A zoo has many animals including zebras";
	int c = 'z'; // char to search for
	
	printf("%s\n%s'%c'%s\"%s\"\n",
		"The remainder of string1 beginning with the",
		"last occurence of char ", c,
		" is: ", strrchr(string1, c));
}
