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

int main(void)
{ //4_ инициализация колоды карт_комбинация_2_ПАРЫ_у_первого_игрока
	 unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21,  5, 17, 19, 11, 20, 26, 37,  9, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10, 27,  3, 16, 18, 23, 25, 34, 35, 36,  6, 38, 39, 40, 41, 14, 42, 43, 44, 45, 46, 49, 48,  4,  7, 51, 52};
     
	 // initialize deck array
    // unsigned int deck[SUITS][FACES] = {0};
     // represents hand
	 unsigned int hand[5][2];

	 srand(time(NULL)); // seed random-number generator
     //shuffle(deck); // shuffle the deck

	 // initialize suit array
     const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	 // initialize face array
     const char *face[FACES] = {"Ace", "Deuce", "Three", "Four",
                                "Five", "Six", "Seven", "Eight",
                                "Nine", "Ten", "Jack", "Queen", "King"};

     deal(deck, hand, face, suit); // deal the deck
     oneOfPair(hand, face);
     twoOfPair(hand, face);
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
             printf("\nThe hand contains a pair %s\n", wFace[i] );
		 }
     }  
}
