/*(Card Shuffling and Dealing) Modify the program:*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

//prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], unsigned int wHand[][2], const char *wFace[], const char *wSuit[]); // dealing doesn't modify the arrays
void oneOfPair(unsigned int wHand[][2], const char *wFace[]);
void twoOfPair(unsigned int wHand[][2],  const char *wFace[]);
void treeOfCard(unsigned int wHand[][2],  const char *wFace[]);
void fourOfCard(unsigned int wHand[][2],  const char *wFace[]);
void flashOfCard(unsigned int wHand[][2],  const char *wSuit[]);
void straighOfCard(unsigned int wHand[][2], const char *wFace[]);

int main(void)
{   
	 // initialize deck array
     unsigned int deck[SUITS][FACES] = {0};
     // represents hand
	 unsigned int hand[5][2];

	 srand(time(NULL)); // seed random-number generator
     shuffle(deck); // shuffle the deck

	 // initialize suit array
     const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	 // initialize face array
     const char *face[FACES] = {"Ace", "Deuce", "Three", "Four",
                                "Five", "Six", "Seven", "Eight",
                                "Nine", "Ten", "Jack", "Queen", "King"};

     deal(deck, hand, face, suit); // deal the deck
     oneOfPair(hand, face);
     twoOfPair(hand, face);
	 treeOfCard(hand, face);
	 fourOfCard(hand, face);
	 flashOfCard(hand, suit);
	 straighOfCard(hand, face);
}

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
     // for each of the cards, choose slot of deck randomly
     for (size_t card = 1; card <= CARDS; ++card)
	 {
         size_t row; // row number
         size_t column; // column number

         // choose new random location until unoccupied slot found
         do {
             row = rand() % SUITS;
             column = rand() % FACES;
         } while(wDeck[row][column] != 0); 

         // place card number in chosen slot of deck
         wDeck[row][column] = card;
     }
} 

// deal cards in deck
void deal(unsigned int wDeck[][FACES], unsigned int wHand[][2], const char *wFace[], const char *wSuit[])
{
	 unsigned int r = 0;
     // deal each of the cards
     for (size_t card = 1; card <= 5; ++card)
	 {
         // loop through rows of wDeck
         for (size_t row = 0; row < SUITS; ++row)
		 {
             // loop through columns of wDeck for current row
             for (size_t column = 0; column < FACES; ++column)
		     {
                 // if slot contains current card, display card
                 if (wDeck[row][column] == card) 
				 {
					 wHand[r][0] = row;
					 wHand[r][1] = column;
	                 printf("%5s of %-8s\n", wFace[column], wSuit[row]);
					 ++r;
                 }
             }
         }
     }
}

void oneOfPair(unsigned int wHand[][2],  const char *wFace[])
{
     unsigned int counter[FACES]={0};
     
     size_t i;
     size_t pair;//переменная для запоминания номинала пары
	 size_t n = 0;//количество одинаковых карт на руках у игрока
     
     for( i = 0; i < 5; ++i)
     {
         ++counter[wHand[i][1]];
     }
     
     for( i = 0; i < FACES; ++i)
     {
         if(counter[i] == 2 )
         {
             ++n;
			 if(n == 1)
				 pair = i;
         }
     }
     if(n == 1)
     {
        printf("\nThe hand contains a pair %s\n", wFace[pair] );
	 }
}

void twoOfPair(unsigned int wHand[][2],  const char *wFace[])
{
     unsigned int counter[FACES]={0};
     
     size_t i;
     
     for( i = 0; i < 5; ++i)
     {
         ++counter[wHand[i][1]];
     }
     
     for( i = 0; i < FACES; ++i)
     {
		 if(counter[i] == 2 )
         {
             printf("\nThe hand contains a 2 pair %s\n", wFace[i] );
		 }
     }  
}

void treeOfCard(unsigned int wHand[][2],  const char *wFace[])
{
     unsigned int counter[FACES]={0};
     
     size_t i;
     
     for( i = 0; i < 5; ++i)
     {
         ++counter[wHand[i][1]];
     }
     
     for( i = 0; i < FACES; ++i)
     {
		 if(counter[i] == 3 )
         {
             printf("\nThe hand contains a 3 card %s\n", wFace[i] );
		 }
     }  
}
void fourOfCard(unsigned int wHand[][2],  const char *wFace[])
{
     unsigned int counter[FACES]={0};
     
     size_t i;
     
     for( i = 0; i < 5; ++i)
     {
         ++counter[wHand[i][1]];
     }
     
     for( i = 0; i < FACES; ++i)
     {
		 if(counter[i] == 4 )
         {
             printf("\nThe hand contains a 4 card %s\n", wFace[i] );
		 }
     }  
}

void flashOfCard(unsigned int wHand[][2],  const char *wSuit[])
{
     unsigned int counter[SUITS]={0};
     
     size_t i;
     
     for( i = 0; i < 5; ++i)
     {
         ++counter[wHand[i][0]];
     }
     
     for( i = 0; i < FACES; ++i)
     {
		 if(counter[i] == 5 )
         {
             printf("\nThe hand contains a FLASH card %s\n", wSuit[i] );
		 }
     }  
}

void straighOfCard(unsigned int wHand[][2],  const char *wFace[])
{
     unsigned int counter[5]={0};
     unsigned int temp;
     size_t i, j;
     
     for( i = 0; i < 5; ++i)
     {
         counter[i] = wHand[i][1];
     }
     
     for( i = 1; i < 5; ++i)
     {
		for( j = 0; j < 4; ++j)
        {
		 if(counter[j] > counter[j + 1])
         {
			 temp = counter[j];
			 counter[j] = counter[j + 1];
			 counter[j + 1] = temp;
		 }
        } 
	 }	
    if(counter[4] - 1 == counter[3] && counter[3] - 1 == counter[2] && counter[2] - 1 == counter[1] && counter[1] - 1 == counter[0])
	{
		printf("\nThe hand contains a STRAIGHT from %s to %s\n", wFace[counter[0]], wFace[counter[4]]);
	}		
}
