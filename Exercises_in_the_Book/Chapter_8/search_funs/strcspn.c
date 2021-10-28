#include <stdio.h>
#include <string.h>

int main(){
	const char *string1 = "The value is 3.14159";
	const char *string2 = "1234567890";
	
	printf("%s%s\n%s%s\n\n%s\n%s%u\n",
		"string = ", string1, "string2 = ", string2,
		"The length of the initial segment of string1",
		"containing no chars from string2= ", strcspn(string1, string2));
}
