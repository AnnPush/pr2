#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[]);
void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[]);

int main(void)
{
	unsigned int deck[SUITS][FACES] = {0};
	
	srand(time(NULL));
	
	
	const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	
	const char *face[FACES] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	int card = 1;
	
		for(size_t row = 0; row < SUITS; ++row)
	    {
			for(size_t column = 0; column < FACES; ++column)
	        {
				deck[row][column] = card;
                printf("card_%d [%d][%d] %5s of %-8s\n", card, row, column, face[column], suit[row]);				
				card++;					
	        }
	    }

	shuffle(deck, face, suit);
		puts("");
	deal(deck, face, suit);
}

void shuffle(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[])
{
	for(size_t row = 0; row < SUITS; ++row)
	    {
			for(size_t column = 0; column < FACES; ++column)
	        {
				int x = rand() % SUITS;
				int y = rand() % FACES;
				int temp = wDeck[row][column];
				wDeck[row][column] = wDeck[x][y];
				wDeck[x][y] = temp;
			}
		}
	puts("");
	for(size_t row = 0; row < SUITS; ++row)
	{
	    for(size_t column = 0; column < FACES; ++column)
	    {
            printf("card_%d [%d][%d] \n", wDeck[row][column], row, column);				
	   }
	}
}

void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[])
{
	for(size_t card = 1; card <= CARDS; ++card)
	{
		for(size_t row = 0; row < SUITS; ++row)
	    {
			for(size_t column = 0; column < FACES; ++column)
	        {
				if(wDeck[row][column] == card)
                {
                    printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
                    break;
				}					
	        }
	    }
	}
}
