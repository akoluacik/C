#include <stdio.h>
#include <string.h>

#define SIZE 100


int startsWith(char [], char [], int);

int main(){
	char s[SIZE];
	fgets(s, SIZE, stdin);
	s[strcspn(s, "\n")] = 0;
	
	char *tokenPtr = strtok(s, " ");
	while(tokenPtr){
		if(startsWith(tokenPtr, "th", 2))
			printf("%s\n", tokenPtr);
		tokenPtr = strtok(NULL, " ");
	}
	
	
	return 0;
}

int startsWith(char input[], char search[], int lenSearch){
	if(!strncmp(input, search, lenSearch)) return 1;
	return 0;
	
}
