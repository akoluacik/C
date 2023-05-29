#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

void getStr(char [], int size);
void nofWords(char []);
void printnofWords(int []);



int main(){
	char s[SIZE];
	getStr(s, SIZE);
	nofWords(s);
}


void getStr(char s[], int size){
	fgets(s, size, stdin);
	s[strcspn(s, "\n")] = 0;
}

void nofWords(char s[]){
	int i, wordLength=0;
	int letters[7]={0}; // holds # of one-letters words at its 1st index, two-letter words at its 2nd index and so on.
	
	for(i=0;i<=strlen(s);i++){
		if(s[i] != ' ' && i != strlen(s))
			++wordLength;
		
		else{
			++letters[wordLength];
			wordLength = 0;
		}
	}
	printnofWords(letters);
}

void printnofWords(int letters[]){
	int i;
	printf("%s\t%s\n", "Word Length", "Occurences");
	for(i=1;i<=7;i++)
		printf("%d\t\t%d\n", i, letters[i]);
}



