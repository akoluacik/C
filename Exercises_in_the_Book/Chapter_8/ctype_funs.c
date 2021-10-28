#include <stdio.h>
#include <ctype.h>

int main(){
	printf("\n%s\n%s%s%s\n%s%s%s\n", "According to isdigit: ",
		"8 is ",isdigit('8') ? "a ": "not a ", "digit",
		"# is ", isdigit('#') ? "a ": "not a ", "digit");
}
