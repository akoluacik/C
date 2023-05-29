#include <stdio.h>
#include <string.h>

void getStr(char [], int size);
void driver(char [], char [], char , char []);
int endsWith(char [], char, char []);

int main(){
	
	char s[100];
	getStr(s, 100);
	
	//char *last = strrchr(s, 't');
	driver(s, " ", 't', "tion");
	
	
	return 0;
}

void getStr(char s[], int size){
	fgets(s, size, stdin);
	s[strcspn(s, "\n")] = 0;
}

void driver(char s[], char delimiter[], char start, char end[]){
	char *tokenPtr = strtok(s, delimiter);
	while(tokenPtr){
		if (endsWith(tokenPtr, start, end))
			printf("%s\n", tokenPtr);
		tokenPtr = strtok(NULL, delimiter);
	}
}

int endsWith(char s[], char start, char end[]){
	char *last = strrchr(s, start);
	if(last && !strcmp(last, end))
		return 1;
	return 0;
}
