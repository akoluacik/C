#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ownstrcpy(char dest[], char src[]);


int main(){
	char dest[] = "Hello";
	char src[] = "Wo";
	ownstrcpy(dest, src);
	printf("%s\n", dest);
	return 0;
}

void ownstrcpy(char dest[], char src[]){
	int idx1=0, idx2=0;
	
	while(dest[idx1])
		idx1++;
	
	while(src[idx2] != '\0'){
		dest[idx1] = src[idx2];
		idx1++;
		idx2++;
	}
	dest[idx1]='\0';
}

