/*(Card Shuffling and Dealing) Modify the program:*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

//prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], unsigned int wHand[][2], const char *wFace[], const char *wSuit[], unsigned int start,  unsigned int finish); // dealing doesn't modify the arrays
void mark();
int printRating(unsigned int*, unsigned int*);//печать результата оценивания карт

int oneOfPair(unsigned int wHand[][2], const char *wFace[]);
int twoOfPair(unsigned int wHand[][2],  const char *wFace[]);
int treeOfCard(unsigned int wHand[][2],  const char *wFace[]);
int fourOfCard(unsigned int wHand[][2],  const char *wFace[]);
int flashOfCard(unsigned int wHand[][2],  const char *wSuit[]);
int straighOfCard(unsigned int wHand[][2], const char *wFace[]);

int main(void)
{   
	 // initialize deck array
     unsigned int deck[SUITS][FACES] = {0};
     // represents hand
	 unsigned int player1[5][2];//карты на руках у первого игрока
	 unsigned int player2[5][2];//карты на руках у второго игрока
	// unsigned int hand[5][2];

	 srand(time(NULL)); // seed random-number generator
     shuffle(deck); // shuffle the deck

	 // initialize suit array
     const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	 // initialize face array
     const char *face[FACES] = {"Ace", "Deuce", "Three", "Four",
                                "Five", "Six", "Seven", "Eight",
                                "Nine", "Ten", "Jack", "Queen", "King"};

    printf("\nHand1\n\n");

	 //сдать карты первому игроку с 0 по 4
	 deal(deck, player1, face, suit, 1, 5); 
	 //найти комбинацию карт первого игрока
	// combination1 = rating(player1, face, suit, &nominal1, sortPlayer1);


     printf("\nHand2\n\n");

	 //сдать карты второму игроку с 5 по 9
	 deal(deck, player2, face, suit, 5, 9); 
	 //найти комбинацию карт второго игрока
	 //combination2 = rating(player2, face, suit, &nominal2, sortPlayer2);

	/*deal(deck, hand, face, suit); // deal the deck
     oneOfPair(hand, face);
     twoOfPair(hand, face);
	 treeOfCard(hand, face);
	 fourOfCard(hand, face);
	 flashOfCard(hand, suit);
	 straighOfCard(hand, face);*/
}
int printRating(unsigned int* ptr1, unsigned int* ptr2)
{
	if(*ptr1 > *ptr2)
	 {
		 printf("\nHand1 is the better hand\n");
		 return 1;
	 }
	 else if(*ptr1 < *ptr2)
	 {
         printf("\nHand2 is the better hand\n");
		 return 1;
	 }
   return 0;
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
void deal(unsigned int wDeck[][FACES], unsigned int wHand[][2], const char *wFace[], const char *wSuit[], unsigned int start,  unsigned int finish)
{
	 unsigned int r = 0;
     // deal each of the cards
     for (size_t card = start; card <= finish; ++card)
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

void mark()
{
	if(!printRating(&combination1, &combination2))//сравнить комбинации карт
	 {
		 if(!printRating(&nominal1, &nominal2))//если комбинации равны, сравнить номиналы
		 {
			 for(size_t i =0 ; i < 5; ++i)
			 {
				 if(!printRating(&sortPlayer1[i], &sortPlayer2[i]))//если номиналы равны, сравнение идет по сортированному массиву по старшей карте
		         {
					 flag++;
				 }
				 if( flag == 5)
				 {
                     printf("\nHand1 = Hand2\n");//карты игроков равны
			     }
			 }
		}
	}  
}



int oneOfPair(unsigned int wHand[][2],  const char *wFace[])
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
		return 1;
	 }
	 return 0;
}

int twoOfPair(unsigned int wHand[][2],  const char *wFace[])
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
			 return 2;
		 }
     }  
	 return 0;
}

int treeOfCard(unsigned int wHand[][2],  const char *wFace[])
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
			 return 3;
		 }
     }
return 0;	 
}
int fourOfCard(unsigned int wHand[][2],  const char *wFace[])
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
			 return 6;
		 }
     } 
return 0;	 
}

int flashOfCard(unsigned int wHand[][2],  const char *wSuit[])
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
			 return 5;
		 }
     } 
return 0;	 
}

int straighOfCard(unsigned int wHand[][2],  const char *wFace[])
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
		return 4;
	}	
    return 0;	
}

priority
