#include <stdio.h>
#include <string.h>

#define SIZE 11

char* protection_str(char [], int);
void getStr(char [], int size);

int main(){
	char s[SIZE];
	getStr(s, SIZE);
	char *protected_string = (char*)malloc(sizeof(char)*SIZE);
	protected_string = protection_str(s, strlen(s));
	printf("%s\n", protected_string);
	printf("%s\n","---------");
	printf("%s", "123456789");
}


void getStr(char s[], int size){
	fgets(s, size, stdin);
	s[strcspn(s, "\n")] = 0;
}


char* protection_str(char inp_amount[], int len){
	char protected_str[SIZE];
	//printf("%d", len);
	memset(protected_str, '*', 9 - len);
	strcpy(protected_str + 9-len, inp_amount);
	return protected_str;
}
