#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 10

void shuffle(char deck[SUITS][FACES]);
void deal(char deck[SUITS][FACES], unsigned int hand1[][2], unsigned int hand2[][2], char *faces[], char *suits[]);
void sort(unsigned int hand1[][2],  unsigned int hand2[][2], char deck[SUITS][FACES], char *faces[]);

int main(){
	char *suits[] = {"Diamonds", "Clubs", "Spades", "Hearts"};
	char *faces[] = {"Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
	char deck[SUITS][FACES]={0};
	unsigned int hand1[5][2], hand2[5][2]; // zeroth columns of hands holds suit of the card, 1st column holds faces.
	srand(time(NULL));
	shuffle(deck);
	deal(deck, hand1, hand2, faces, suits);
	
	int i,j;
	for(i=0;i<5;i++){
		printf("%5s of %8s %10s of %8s\n", faces[hand1[i][1]], suits[hand1[i][0]], faces[hand2[i][1]], suits[hand2[i][0]]);
	}
	sort(hand1, hand2, deck, faces);
	return 0;
}


void shuffle(char deck[SUITS][FACES]){
	size_t row, column;
	unsigned int card;
	for(card=1;card<=CARDS;++card){
		do{
			row = rand()%SUITS;
			column = rand()%FACES;
		} while(deck[row][column]); // if that position has already been filled.
		deck[row][column] = card;
	}
}

void deal(char deck[SUITS][FACES], unsigned int hand1[][2], unsigned int hand2[][2], char *faces[], char *suits[]){
	size_t row, column, card;
	unsigned int r=0;
	int key=1;
	for(card=1;card<=CARDS;++card){
		for(row=0;row<SUITS;++row){
			for(column=0;column<FACES;++column){
				if(deck[row][column]==card){
					if(key) {
						hand1[r][0]=row;
						hand1[r][1]=column;
						//printf("r:%d %5s of %8s\t\t", r,faces[column], suits[row]); // debugging
					} else {
						hand2[r][0]=row;
						hand2[r++][1]=column;
						//printf("r:%d %5s of %8s\n", r++,faces[column], suits[row]); // debugging
					}
					key=!key; // to deal the cards in order
				}
			}
		}
	}
}


void sort(unsigned int hand1[][2], unsigned int hand2[][2], char deck[SUITS][FACES], char *faces[]){
	int sum1=0, sum2=0;
	size_t row, column, card;
	
	for(row=0;row<CARDS/2;row++){
		//printf("%d\n", hand1[row][1]); // debugging
		sum1 += hand1[row][1];
	}
	
	for(row=0;row<CARDS/2;row++){
		//printf("%d\n", hand2[row][1]); // debugging
		sum2 += hand2[row][1];
	}
	puts(" ");
	if(sum1>sum2)
		printf("%s", "Player 1 wins");
	else if(sum1<sum2)
		printf("%s", "Player 2 wins");
	else 
		printf("%s", "scoreless\n");
	puts(" ");
}
