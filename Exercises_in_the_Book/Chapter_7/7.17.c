#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 70


int main(){
	
	unsigned int hare_pos[MAX]={0}, tort_pos[MAX]={0};
	printf("%s","BANG !!!!!\nAND THEY'RE OFF !!!!!\n\n");
	printf("H\tT\n");
	int tortoise_idx=0, hare_idx=0;
	int i,maxPos;
	srand(time(NULL));
	while(hare_idx<70 && tortoise_idx<70){
		hare_idx += hareMove();
		tortoise_idx += tortoiseMove();
		hare_pos[hare_idx-1]=1;
		tort_pos[tortoise_idx-1]=1;
	}
	
	maxPos = max(hare_idx, tortoise_idx);
	for(i=0;i<maxPos;i++){
		if(hare_pos[i] == tort_pos[i] && hare_pos[i] != 0) printf("OUCH!!!\t");
		if(hare_pos[i] == 1) printf("H\t"); else printf(" \t");
		if(tort_pos[i] == 1) printf("T\n"); else printf(" \n");
	}
	if(maxPos == hare_idx) printf("\nHare Wins!!!");
	else if(maxPos == tortoise_idx) printf("\nTortoise Wins!!!");
	else printf("\nTie\n");
	
	return 0;
}

int tortoiseMove(){
	int i = 1 + rand()%10;
	if(i>=1 && i<=5) return 3;
	else if(i>=6 && i<=7) return 6;
	else return 1;
}

int hareMove(){
	int i = 1 + rand()%10; 
	if(i>=1 && i<=2) return 0; // sleep
	else if(i>=3 && i<=4) return 9; // big hop
	else if(i==5) return 12; // big slip
	else if(i>=6 && i<=8) return 1; // small hop
	else return 2; // small slip;
}

int max(int number1, int number2){
	return (number1>=number2)?(number1):(number2);
}
