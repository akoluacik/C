#include <stdio.h>
#include <string.h>

int main(){
	const char *string1 = "This is a test";
	const char *string2 = "beware";
	
	printf("%s\"%s\"\n'%c'%s\n\"%s\"\n",
		"Of the chars in ", string2,
		*strpbrk(string1, string2),
		" appears earliest in ", string1); 	
}
