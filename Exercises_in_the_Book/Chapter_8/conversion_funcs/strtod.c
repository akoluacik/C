#include <stdio.h>
#include <stdlib.h>

int main(){
	const char *string = "51.2% are admitted.";
	// const char *string = "are 51.2% admitted.";
	// double d = strtod(string+5, &stringPtr);
	char *stringPtr;
	double d = strtod(string, &stringPtr);
	printf("The string \"%s\" converted to the \n", string);
	printf("Double value %.2f and the string \"%s\" \n", d, stringPtr);
	return 0;
}
