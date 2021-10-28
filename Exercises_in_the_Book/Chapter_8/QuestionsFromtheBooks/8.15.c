#include <stdio.h>
#include <string.h>

int main(){
	
	char s[100], *tokenPtr;
	char sRev[100] = {'\0'};
	//scanf("%[^\n]s", s);
	fgets(s, 100, stdin); // adds newline that I cannot understand
	s[strcspn(s, "\n")] = 0; // to fix the problem, elegant way.
	tokenPtr = strtok(s, " ");
	while(tokenPtr != NULL){
		strrev(tokenPtr);
		strcat(sRev, tokenPtr);
		strcat(sRev, " ");
		tokenPtr = strtok(NULL, " ");
	}
	printf("%s", sRev);
}
