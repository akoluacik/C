#include <stdio.h>
#include <string.h>

int islower(int ch);
int isupper(int ch);
int isdigit(int ch);
int isalpha(int ch);
int isalphanum(int ch);
int space(int ch);

char toLower(int ch);
char toUpper(int ch);

int main(){
	char temp = 'B';
	
	printf("%c", toLower(temp));
	return 0;
}

int islower(int ch){
	return (ch>=97 && ch<=122)?1:0;
}

int isupper(int ch){
	return (ch>=65 && ch<=90)?1:0;
}

int isalpha(int ch){
	return (islower(ch) || isupper(ch))?1:0;
}

int isdigit(int ch){
	return (ch>=48 && ch<=57)?1:0;
}

int isalphanum(int ch){
	return (isalpha(ch) || isdigit(ch))?1:0;
}

int isspace(int ch){
	return (ch==' ')?1:0;
}

char toLower(int ch){
	if(isalpha(ch) && isupper(ch))
		ch = ch + 32;
	return ch;
}

char toUpper(int ch){
	if(isalpha(ch) && islower(ch))
		ch = ch - 32;
	return ch;
}
