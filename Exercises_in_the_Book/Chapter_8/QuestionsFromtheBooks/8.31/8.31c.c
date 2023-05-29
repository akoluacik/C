#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

void getStr(char [], int size);
void wordfreq(char []);
void displaywordfreq(char [][SIZE], int [], int);


int main(){
	char s[SIZE];
	getStr(s, SIZE);
	wordfreq(s);
	
}


void getStr(char s[], int size){
	fgets(s, size, stdin);
	s[strcspn(s, "\n")] = 0;
}

void wordfreq(char s[]){
	char list_of_s[20][SIZE], *tokenPtr;
	tokenPtr = strtok(s, " ");
	int i, j, len=0, freq[SIZE]={0};
	
	while(tokenPtr){
		strcpy(list_of_s[len++], tokenPtr);
		tokenPtr = strtok(NULL, " ");
	}
	
	for(i=0;i<len-1;i++){
		for(j=i+1;j<len;j++){
			if( strcmp(list_of_s[i], "0") && !strcmp(list_of_s[i], list_of_s[j])){
				++freq[i];
				strcpy(list_of_s[j], "0");
			}
		}
	}
	displaywordfreq(list_of_s, freq, len);
	
}
void displaywordfreq(char list_of_s[][SIZE], int freq[], int len){
	int i;
	for(i=0;i<len;i++)
		if(strcmp(list_of_s[i], "0"))
			printf("%s -> %d\n", list_of_s[i], freq[i]+1);
}

