#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct bitCard {                                  
   unsigned face : 4;  /* 4 bits; 0-15 */         
   unsigned suit : 2;  /* 2 bits; 0-3 */          
   unsigned color : 1; /* 1 bit; 0-1 */           
};                       

typedef struct bitCard Card; 

void fillDeck( Card * const wDeck );   
void shuffle( Card * const wDeck );   
void deal( const Card * const wDeck ); 

int main(void)
{ 
   Card deck[ 52 ]; 
srand(time(NULL)); 
   fillDeck( deck );
   shuffle(deck);
   deal( deck );
   
} 

void fillDeck( Card * const wDeck )
{ 
   int i; 

   for ( i = 0; i <= 51; i++ ) { 
      wDeck[ i ].face = i % 13; 
      wDeck[ i ].suit = i / 13; 
      wDeck[ i ].color = i / 26;
   } 

} 

void shuffle( Card * const wDeck )
{
   int i, j;

   Card temp;

   for(i = 0; i < 52; i++) {
      j = rand() % 52;
      temp = wDeck[i];
      wDeck[i] = wDeck[j];
      wDeck[j] = temp;
   }

} 

void deal(const Card * const wDeck )
 {
 // loop through wDeck
for (size_t i = 0; i < 52; ++i) {
 printf("Color:%2d  Suit:%2d  Card:%3d   %s ", wDeck[i].color, wDeck[i].face, wDeck[i].suit, (i + 1) % 4 ? " " : "\n");
 }
 }

