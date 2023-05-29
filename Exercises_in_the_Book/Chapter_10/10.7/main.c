#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52

typedef struct{
	unsigned int face : 4;
	unsigned int suit : 2;
	unsigned int color : 1;
} Card;


void fillDeck(Card * const wDeck); // prototype
void shuffle(Card * const wDeck);
void deal(const Card * const wDeck); // prototype

int main(){
	
	Card deck[CARDS]; // create array of Cards
	
	srand(time(NULL));
	fillDeck(deck);
	shuffle(deck);
	deal(deck);
	
	return 0;
}

void fillDeck(Card * const wDeck){
	size_t i;
	for(i = 0; i < CARDS; ++i) {
		wDeck[i].face = i % (CARDS / 4);
		wDeck[i].suit = i / (CARDS / 4);
		wDeck[i].color = i / (CARDS / 2);
	}	
}
void shuffle(Card * const wDeck){
	size_t i;
	for(i = 0; i < CARDS; ++i){
		size_t j = rand() % CARDS;
		Card temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}
// output cards in two-column format; cards 0-25 indexed with
// k1 (colunm 1); cards 26-51 indexed with k2 (column 2)
void deal(const Card * const wDeck){
	size_t k1, k2;
	const char *face[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	const char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	for(k1 = 0, k2 = k1 + 26; k1 < CARDS / 2; ++k1, ++k2){
		printf("%-10s %s\t%s    ",
			face[wDeck[k1].face], suit[wDeck[k1].suit], wDeck[k1].color?"Red":"Black");
		printf("%-10s %s\t%s\n",
			face[wDeck[k2].face], suit[wDeck[k2].suit], wDeck[k2].color?"Red":"Black");
	}
	
}
