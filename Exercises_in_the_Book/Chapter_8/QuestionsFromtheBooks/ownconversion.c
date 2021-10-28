#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str2int(int);
int isdigit(int);
long str2double(int);

int driver(char *, char **);

int main(){
	char *s = "51% are admitted."; // static string literal, it READ-ONLY.
	
	char *sPtr;
	int x = driver(s, &sPtr); // The Linux Programming Interface book
	printf("%d %s", x, sPtr);
	
	return 0;
}

int isdigit(int ch){
	return (ch>=48 && ch<=57)?1:0;
}

int str2int(int ch){
	return ch-48;
}

int driver(char *s, char **sPtr){
	int i=0, number=0;
	while(s[i]!='\0' && isdigit(s[i])){
		number = number*10 + str2int(s[i]);
		i++;
	}
	*sPtr = s + i;
	//printf("%s\n", sPtr);
	return number;
}
