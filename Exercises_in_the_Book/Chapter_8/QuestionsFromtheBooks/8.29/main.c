#include <stdio.h>
#include <string.h>

int ownstrcmp(char [], char []);

int main(){
	
	char test1[] = "me";
	char test2[] = "merhaba";
	printf("%d\n", ownstrcmp(test1, test2));
	return 0;
}

int ownstrcmp(char s1[], char s2[]){
	int i;
	for(i=0;s1[i]!='\0' && s2[i]!='\0';i++){
			if(s1[i]>s2[i]) return 1;
			else if(s1[i] < s2[i]) return -1;
	}
	if(strlen(s1)>strlen(s2)) return 1;
	else if(strlen(s2)>strlen(s1)) return -1;
	return 0;
}
