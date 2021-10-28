#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

void removeWord(char [], char [], char []);

int main(){
	char s[SIZE], givenWord[SIZE], word[SIZE]="";
	fgets(s, SIZE, stdin);
	fgets(givenWord, SIZE, stdin);
	s[strcspn(s, "\n")] = 0;
	givenWord[strcspn(givenWord, "\n")] = 0;
	//printf("%s", s);
	//printf("%d", nofWords(s));
	removeWord(s, givenWord, word);
	printf("%s", word);
	//printf("%d", nofWords(word));
	return 0;
}

void removeWord(char s[], char givenWord[], char word[]){
	
	char *tokenPtr = strtok(s, " ");
	while(tokenPtr){
		if(strcmp(tokenPtr, givenWord)){
			strcat(word, tokenPtr);
			strcat(word, " ");
		}
		tokenPtr = strtok(NULL, " ");
	}

}

/*int nofWords(char s[]){
	int i, count=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i] == ' ') count++;
	}
	//free(tokenPtr);
	return count;
}*/



// this is an apple which is not very important in our life as water is
