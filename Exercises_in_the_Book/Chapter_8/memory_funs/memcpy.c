/*
memcpy does the same thing with strcpy, but memcpy is more efficient
if you know how many chars you will copy.
*/

#include <stdio.h>
#include <string.h>

int main(){
	char s1[17];
	char s2[] = "Copy this string";
	
	memcpy(s1, s2, strlen(s2));
	printf("%s\n%s\n\"%s\"\n", "After s2 is copied into s1 with memcpy",
	"s1 contains", s1);
}
