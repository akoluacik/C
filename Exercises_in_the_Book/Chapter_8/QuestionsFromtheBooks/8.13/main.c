#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *appender(char s);
void shiftLeft(char [], int);

int main()
{
    char s[100], *lastThree;
    char word[100];
    fgets(s, 100, stdin);
    s[strcspn(s, "\n")] = 0;
    char *tokenPtr = strtok(s, " ");
    while(tokenPtr != NULL){
		
    	lastThree = appender(tokenPtr[0]);
    	//printf("lastThree : %s\n", lastThree); for debugging
    	
    	shiftLeft(tokenPtr, strlen(tokenPtr));
    	
    	sprintf(word, "%s%s ", tokenPtr, lastThree); // concatenation
    	
    	
    	printf("tokenptr:%s ", word);
    	tokenPtr = strtok(NULL, " ");
	}
	
    
    return 0;
}

char *appender(char s){
    char *returned = (char*)malloc(sizeof(char)*4);
    snprintf(returned, sizeof(returned), "%c%s",s,"ay");
    return returned;
}

void shiftLeft(char s[], int len){
	int i;
	for(i=0;i<len-1;i++){
		s[i]=s[i+1];
	}
	s[i] = '\0';
}
