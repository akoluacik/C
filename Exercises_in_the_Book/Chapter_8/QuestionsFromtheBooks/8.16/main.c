#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 128

int main(void){
	char s[SIZE], search_string[SIZE];
	char *searchPtr;
	fgets(s, SIZE, stdin);
	fgets(search_string, SIZE, stdin);
	search_string[strcspn(search_string, "\n")]=0;
	//search_string[strcspn( search_string, "\n")] = 0;
	searchPtr = strstr(s, search_string);
	//printf("%s", searchPtr);

	if(searchPtr){
		printf("%s%s\n", "The text line beginning with the first occurrence of: ", searchPtr);
		searchPtr = strstr(searchPtr+1, search_string);
		if(searchPtr){
			printf("%s%s\n","The text line beginning with the second occurrence of: ", searchPtr);  
		} else{
			printf("%s", "The string to be searched just appeared once.\n"); 
		}
	} else {
		printf("Search string is not found in the string.");
	}
	
}
