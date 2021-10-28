#include <stdio.h>
#include <string.h>

int main(){
	const char *string = "This is a string";
	char ch1 = 'a';
	char ch2 = 'z';
	
	if(strchr(string, ch1) != NULL) // or strchr(string,chr) is also OK.
		printf("\'%c\' was in \"%s\".\n", ch1, string);
	else // if ch1 was not found
		printf("\'%c\' was not found in \"%s\".\n", ch2, string);
	
	// if ch2 was found in string
	if(strchr(string, ch2)) // or strchr(string, ch2) != NULL
		printf("\'%c\' was in \"%s\".\n", ch2, string);
	else // if ch1 was not found
		printf("\'%c\' was not found in \"%s\".\n", ch2, string);
		
	
}
/*
should be known
*/

/*int main(){
	const char *string = "This is a string";
	char ch1 = 'a';
	char *ptr = strchr(string, ch1);
	if(ptr)
		printf("\'%c\' is found in %s at index %d", ch1, string, (int)(ptr-string));
}*/
