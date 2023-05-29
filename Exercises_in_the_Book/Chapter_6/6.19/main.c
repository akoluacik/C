#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define FACE 6
#define OCCURENCES 13

int main(){
	int dice1;
	int dice2;
	int total; 
	int faces[FACE][FACE] = {0};
	int occs[OCCURENCES] = {0};
	
	total = 0;
	srand(time(NULL));
	for(unsigned int roll = 1; roll <= 36000; roll++){
		dice1 = 1 + rand() % 6;
		dice2 = 1 + rand() % 6;
		++occs[dice1 + dice2];
		total = dice1 + dice2;
	}
	printf("%3s%10s%11s\n", "Sum", "Frequency", "Percentage");
	for(unsigned int i = 0; i < OCCURENCES-2; i++)
		printf("%2d%8d%13lf\n", i + 2, occs[i+2], 100.0 * (occs[i + 2] / 36000.0));
}
