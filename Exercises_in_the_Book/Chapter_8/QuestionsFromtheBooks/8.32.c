#include <stdio.h>
#include <string.h>
#include <ctype.h>

int *parseDate(char inp_date[]);
void printDate(char inp_date[]);
int validate(char inp_date[]);
void getStr(char [], int size);

int main(){
	char date[11];
	getStr(date, 11);
	printDate(date);
	return 0;
}


int *parseDate(char inp_date[]){
	char *tokenPtr;
	int date[3], i=0;
	
	if(validate(inp_date)){
		tokenPtr  = strtok(inp_date, "/");
		while(tokenPtr){
			date[i++] = atoi(tokenPtr);
			tokenPtr = strtok(NULL, "/");
		}
	} else 
		return 0;
	return date;
}

void printDate(char inp_date[]){
	char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int *date;
	
	if((date = parseDate(inp_date)))
		printf("%s %d, %d", months[date[0]-1], date[1], date[2]);
}

int validate(char inp_date[]){
	int i, counter=0;
	if(strlen(inp_date) != 10){
		printf("%s\n", "[ERROR] format should be MM/DD/YYYY.");
		return 0;
	}
	for(i=0;inp_date[i] != '\0';i++){
		if(isalpha(inp_date[i])){
			printf("%s\n", "[ERROR] format should be MM/DD/YYYY with digits only.");
			return 0;	
		}
		if(inp_date[i] == '/')
			++counter;
	}
	if(counter != 2){
		printf("%s\n", "[ERROR] input should content two / as delimiter.");
		return 0;
	}
	return 1;
}

void getStr(char s[], int size){
	fgets(s, size, stdin);
	s[strcspn(s, "\n")] = 0;
}

