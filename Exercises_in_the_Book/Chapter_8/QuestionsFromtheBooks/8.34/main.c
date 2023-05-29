#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int get_first_digit(int n){
	if(n < 10) return n;
	get_first_digit(n/10);
}
int get_first_two_digit(int n){
	if(n <= 100) return n;
	get_first_two_digit(n/10);
}
int get_digit_number(int n){
	int count=0;
	while(n>0){
		++count;
		n/=10;
	}
	return count;
}

char *parse_the_number(double number, char **word_eq){
	
	int int_part = (int)number;
	int dec_part =(int)((number - int_part)*100);
	char *toTeens[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve",
					  "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char *tys[] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	while(int_part > 0){
		if(get_digit_number(int_part) == 5){
			if(int_part >= 20000){
				strcat(*word_eq, tys[get_first_digit(int_part)-2]);
				strcat(*word_eq, "-");
				int_part = int_part % (int)pow(10, 4);
			} else {
				strcat(*word_eq, toTeens[get_first_two_digit(int_part)]);
				strcat(*word_eq, " THOUSAND ");
				int_part = int_part % (int)pow(10, 3);
			}
		} else if(get_digit_number(int_part) == 4){
			strcat(*word_eq, toTeens[get_first_digit(int_part)]);
			strcat(*word_eq, " THOUSAND ");
			int_part = int_part % (int)pow(10, 3);
		} else if(get_digit_number(int_part) == 3){
			strcat(*word_eq, toTeens[get_first_digit(int_part)]);
			strcat(*word_eq, " HUNDRED ");
			int_part = int_part % (int)pow(10, 2);
		} else if(get_digit_number(int_part) == 2){
			if(int_part>=20){
				strcat(*word_eq, tys[get_first_digit(int_part)-2]);
				int_part = int_part%10;
			} else {
				strcat(*word_eq, toTeens[get_first_two_digit(int_part)]);
				int_part = int_part % 100;
			}
			strcat(*word_eq, " ");
		} else if(get_digit_number(int_part) == 1 && int_part != 0){
			strcat(*word_eq, toTeens[get_first_digit(int_part)]);
			int_part = 0;
		}
	}
	strcat(*word_eq, " DOLLAR(s)");
	if(dec_part) strcat(*word_eq, " AND ");
	while (dec_part >= 0){
		if(!dec_part){
			strcat(*word_eq, "cent");
			break;
		}
		if(dec_part < 20){
			strcat(*word_eq, toTeens[dec_part]);
			strcat(*word_eq, " ");
			dec_part = 0;
		} else {
			strcat(*word_eq, tys[get_first_digit(dec_part)-2]);
			strcat(*word_eq, " ");
			dec_part = dec_part%10;
		}
	}
}

int main(){
	char *word_eq = (char*)malloc(sizeof(char)*100);
	word_eq[0] = '\0';
	parse_the_number(345.84, &word_eq);
	printf("%s", word_eq);
	free(word_eq);
	return 0;
}

