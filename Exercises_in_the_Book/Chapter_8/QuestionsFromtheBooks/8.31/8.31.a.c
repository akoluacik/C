#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

void getStr(char [], int size);
void nofLetters(char []);
void printnofLetters(int []);


int main(){
	char s[SIZE];
	getStr(s, SIZE);
	nofLetters(s);
}


void getStr(char s[], int size){
	fgets(s, size, stdin);
	s[strcspn(s, "\n")] = 0;
}

void nofLetters(char s[]){
	int i;
	int alpha[26]={0};
	for(i=0;s[i]!='\0';i++){
		tolower(s[i]);
		++alpha[s[i]-97];
	}
	
	printnofLetters(alpha);
}

void printnofLetters(int alpha[]){
	int i;
	for(i=0;i<26;i++)
		printf("%d %c('s)\n", alpha[i], 65 + i);
}




