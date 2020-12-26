#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffleAndDeal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[]);


int main(void)
{
	unsigned int deck[SUITS][FACES] = {0};
	
	srand(time(NULL));
	
	
	const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	
	const char *face[FACES] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	shuffleAndDeal(deck, face, suit);
	
}

void shuffleAndDeal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[])
{
	for(size_t card = 1; card <= CARDS; ++card)
	{
		size_t row;
		size_t column;
		
		do
		{
			row = rand() % SUITS;
			column = rand() % FACES;
		}while(wDeck[row][column] != 0);
		
		wDeck[row][column] = card;
		printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
	}
}



