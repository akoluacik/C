#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

void nofVowels(char [], int);
void nofDigits(char [], int);
void nofBlanks(char [], int);
void nofConsonants(char [], int);

int main(){
	
	void (*f[4])(char s[], int len) = {nofVowels, nofDigits, nofBlanks, nofConsonants};
	size_t i;
	char s[SIZE];
	fgets(s, SIZE, stdin);
	s[strcspn(s, "\n")] = 0;
	for(i=0;i<4;i++){
		(*f[i])(s, strlen(s));
	}
	
	return 0;
}

void nofVowels(char s[], int len){
	int i, count=0;
	for(i=0;s[i]!='\0';i++){
		if(tolower(s[i])>='a' && tolower(s[i])<='z'){
			if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i] == 'u')
				count++;
		}
	}
	// printf("nofvowelsfunc\n");
	printf("%s%d\n","Number of vowels is: ", count);
	// return count;
	
}

void nofDigits(char s[], int len){
	int i, count=0;
	for(i=0;s[i]!='\0';i++){
		if(isdigit(s[i]))
			count++;
	}
	// printf("nofdigitsfunc\n");
	printf("%s%d\n","Number of digits is: ", count);
	// return count;
}

void nofBlanks(char s[], int len){
	int i, count=0;
	for(i=0;s[i]!='\0';i++){
		if(isspace(s[i]))
			count++;
	}
	// printf("nofvblanksfunc\n");
	printf("%s%d\n","Number of blanks is: ", count);
	// return count;
}

void nofConsonants(char s[], int len){
	// printf("nofconsonantsfunc\n");
	int i, count=0;
	for(i=0;s[i]!='\0';i++){
		if(tolower(s[i])>='a' && tolower(s[i])<='z'){
			if(!(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i] == 'u'))
				count++;
		}
	}
	printf("%s%d\n","Number of consonants is: ", count);
	// return len - (nofBlanks(s, len) + nofDigits(s, len) + nofVowels(s, len));
}
