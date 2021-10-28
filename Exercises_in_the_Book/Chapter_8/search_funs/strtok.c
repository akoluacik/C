#include <stdio.h>
#include <string.h>

int main(void){
	char string[] = "This is a sentence with 7 tokens by blank.";
	printf("%s\n%s\n\n%s\n",
		"The string to be tokenized is:", string,
		"The tokens are:");
	
	char *tokenPtr = strtok(string, " ");
	
	while (tokenPtr != NULL){
		printf("%s\n", tokenPtr);
		tokenPtr = strtok(NULL, " "); // get next token.
		// first argument, NULL, means we're continuing tokenizing.
		// strtok function has a static variable in it so it memorize where did the operation last time left off,
		// if you pass the same string again, it starts with the beginning.
		// note that strtok is a destructive function that makes changes in original string,
		// so copy the original string if you need.
	}
	
}
