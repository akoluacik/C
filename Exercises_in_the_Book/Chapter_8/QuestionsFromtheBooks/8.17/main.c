#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

int occurences(char [], char *);

int main(){
	
	char word[SIZE], search_string[SIZE];
	fgets(word, SIZE, stdin);
	fgets(search_string, SIZE, stdin);
	//scanf("%[^\n]%*c", word);
	//scanf("%[^\n]%*c", search_string);
	word[strcspn(word, "\n")]=0;
	search_string[strcspn(search_string, "\n")]=0;
	printf("count:%d\n", occurences(word, search_string));
	return 0;
}

int occurences(char s[], char *search_string){
	char *searchPtr ;
	int count = 0;
	
	while((searchPtr = strstr(s, search_string))){
		count++;
		searchPtr = strstr(searchPtr+1, search_string);
	}
	return count;
}
