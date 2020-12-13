#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
//тасовать карты
void shuffle(unsigned int wDeck[][FACES]);
//раздать карты игрокам
void deal(unsigned int wDeck[][FACES], unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int start,  unsigned int finish);
//оценка карт игроков
void mark(unsigned int wPlayer1[][2], unsigned int wPlayer2[][2], const char *wFace[], const  char *wSuit[], unsigned int wSortPlayer1[], unsigned int wSortPlayer2[], unsigned int *nominal1, unsigned int *nominal2);

int  printRating(unsigned int*, unsigned int*);//печать результата оценивания карт
int fPriority(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned int *nominal);//определение приоритета карт игроков
void  sort(unsigned int wPlayer[][2],  const char *wFace[], const  char *wSuit[], unsigned int wSortPlayer[]);//сортировка карт, которые находятся на руках у каждого игрока

int main(void)
{   
    unsigned int deck[SUITS][FACES] = {0};
            
	unsigned int player1[5][2];//карты на руках у первого игрока
	unsigned int player2[5][2];//карты на руках у второго игрока
	 
	unsigned int sortPlayer1[5];//сортированный массив карт на руках у первого игрока
	unsigned int sortPlayer2[5];//сортированный массив карт на руках у второго игрока
	unsigned int nominal1;
    unsigned int nominal2;
	   
	srand(time(NULL)); 
    shuffle(deck); // shuffle the deck

    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	
    const char *face[FACES] = {"Ace", "Deuce", "Three", "Four",
                                "Five", "Six", "Seven", "Eight",
                                "Nine", "Ten", "Jack", "Queen", "King"};
	
    printf("\nHand1\n\n");
	
	//сдать карты первому игроку с 1 по 5
	deal(deck, player1, face, suit, 1, 5);
	
	printf("\nHand1_sort\n\n");
	sort(player1, face, suit, sortPlayer1);
	
    printf("\nHand2\n\n");

	//сдать карты второму игроку с 6 по 10
	deal(deck, player2, face, suit, 6, 10);
	
	printf("\nHand2_sort\n\n");
	sort(player2, face, suit, sortPlayer2);
	
	//оценить карты игроков
	mark(player1, player2, face, suit, sortPlayer1, sortPlayer2, &nominal1, &nominal2);	
}

void mark(unsigned int wPlayer1[][2], unsigned int wPlayer2[][2], const char *wFace[], const  char *wSuit[], unsigned int wSortPlayer1[], unsigned int wSortPlayer2[], unsigned int *nominal1, unsigned int *nominal2)
{
	unsigned int p1, p2;
    int flag = 0;
	
	p1 = fPriority(wPlayer1, wFace, wSuit, nominal1);
	p2 = fPriority(wPlayer2, wFace, wSuit, nominal2);
	
	if(!printRating(&p1, &p2))//сравнить комбинации карт
	{
	    if(!printRating(nominal1, nominal2))//если комбинации равны, сравнить номиналы
		{
		    for(size_t i =0 ; i < 5; ++i)
			{
				if(!printRating(&wSortPlayer1[i], &wSortPlayer2[i]))//если номиналы равны, сравнение идет по сортированному массиву по старшей карте
		        {
					flag++;
				}
				else
				{
					break;
				}
				if( flag == 5)
				{
                    printf("\nHand1 = Hand2\n");//карты игроков равны
			    }
			}
		}
	} 
}

void  sort(unsigned int wPlayer[][2],  const char *wFace[], const  char *wSuit[], unsigned int wSortPlayer[])
{
	void swap(unsigned int * element1Ptr, unsigned int * element2Ptr);//функция обменивающая карты в ячейках, на которые показывают указатели

    unsigned int counter[FACES]={0};//сколько одинаковых номиналов карт на руках у игрока
    unsigned int counter1[SUITS]={0};//сколько одинаковых мастей карт на руках у игрока
    
    for(unsigned int r = 0; r < 5; ++r)
    {
        ++counter[wPlayer[r][1]];//считаем, сколько одинаковых номиналов карт на руках у игрока
        ++counter1[wPlayer[r][0]];//считаем, сколько одинаковых мастей карт на руках у игрока
		wSortPlayer[r] = wPlayer[r][1];//заполняем массив номиналов карт, которые на руках у игрока
		
    }
	for( size_t i = 0; i < 4; ++i)
    {
		for( size_t j = 0; j < 4; ++j)
        {
			if(wSortPlayer[j] < wSortPlayer[j+1])
				swap(&wSortPlayer[j], &wSortPlayer[j+1]);//обмен элементов		
		}
	}
	  
	for(unsigned int r = 0; r < 5; ++r)
    {
	    wPlayer[r][1] = wSortPlayer[r];//заполняем массив номиналов карт, которые на руках у игрока
	}
	for( size_t i = 0; i < 5; ++i)
    {	
		printf("%5s of %-8s\n ", wFace[ wPlayer[i][1]],  wSuit[ wPlayer[i][0]] );
	} 
}
//функция обменивающая карты в ячейках, на которые показывают указатели
void swap(unsigned int * element1Ptr, unsigned int * element2Ptr)
{
	unsigned int temp = * element1Ptr;
    * element1Ptr = * element2Ptr;
    * element2Ptr = temp;
}


int fPriority(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned  int *nominal)
{
	int oneOfPair(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned int *nominal);
    int twoOfPair(unsigned int wPlayer[][2],  const char *wFace[],  const char *wSuit[], unsigned int *nominal);
    int treeOfCard(unsigned int wPlayer[][2],  const char *wFace[],  const char *wSuit[], unsigned int *nominal);
    int fourOfCard(unsigned int wPlayer[][2],  const char *wFace[],  const char *wSuit[], unsigned int *nominal);
    int flashOfCard(unsigned int wPlayer[][2],  const char *wFace[], const char *wSuit[], unsigned int *nominal);
    int straighOfCard(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned int *nominal);

    int (*ptr_f[6])(unsigned int [][2], const char* [], const char* [], unsigned int *) = {oneOfPair, twoOfPair, treeOfCard, straighOfCard, flashOfCard, fourOfCard};

    unsigned int priority;
	
	for(int i = 0; i < 6; ++i)
	{
		priority =(*ptr_f[i])(wPlayer, wFace, wSuit, nominal);
		if(priority > 0)
		{
			return priority;
		}
	}
	return 0;
}


	
int printRating(unsigned  int* ptr1, unsigned  int* ptr2)
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

void shuffle(unsigned int wDeck[][FACES])
{
    for (size_t card = 1; card <= CARDS; ++card)
	{
        size_t row;
        size_t column;

        do 
		{
            row = rand() % SUITS;
            column = rand() % FACES;
        } while(wDeck[row][column] != 0); 

        wDeck[row][column] = card;
    } 
} 

void deal(unsigned int wDeck[][FACES], unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int start,  unsigned int finish)
{
	 unsigned int r = 0;
     
     for (size_t card = start; card <= finish; ++card)
	 {
         for (size_t row = 0; row < SUITS; ++row)
		 {
             for (size_t column = 0; column < FACES; ++column)
		     {
                 if (wDeck[row][column] == card) 
				 {
					 wPlayer[r][0] = row;
					 wPlayer[r][1] = column;
	                 printf("%5s of %-8s\t \n", wFace[column], wSuit[row]);
					 ++r;
                 }
             }
         }
     }
}

int oneOfPair(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned int *nominal)
{
     unsigned int counter[FACES]={0};
     
     int  i;
	 size_t n = 0;//количество одинаковых карт на руках у игрока
     
     for( i = 0; i < 5; ++i)
     {
         ++counter[wPlayer[i][1]];
     }
     
     for( i = 0; i < FACES; ++i)
     {
         if(counter[i] == 2 )
         {
             ++n;
			 if(n == 1)
				*nominal = i;
         }
     }
     if(n == 1)
     {
        printf("\nThe hand contains a pair %s\n", wFace[*nominal] );
		return 1;
	 }
	 return 0;
}

int twoOfPair(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned int *nominal)
{
    unsigned int counter[FACES]={0};
    *nominal = 0;
	 
    size_t i;
    size_t n = 0;//количество одинаковых карт на руках у игрока
	  
    for( i = 0; i < 5; ++i)
    {
        ++counter[wPlayer[i][1]];
    }
     
    for( i = 0; i < FACES; ++i)
    {
	    if(counter[i] == 2 )
        {  
           ++n;
           *nominal += i;
           printf("\nThe hand contains a 2 %s \n", wFace[i]);
		}		 	
    } 
    if(n == 2)
	{
	    return 2;
	}
	return 0;
}

int treeOfCard(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned int *nominal)
{
    unsigned int counter[FACES]={0};
     
    size_t i;
     
    for( i = 0; i < 5; ++i)
    {
        ++counter[wPlayer[i][1]];
    }
     
    for( i = 0; i < FACES; ++i)
    {
		if(counter[i] == 3 )
        {
			*nominal = i;
            printf("\nThe hand contains a 3 card %s\n", wFace[i] );
			return 3;
		}
    }
    return 0;	 
}

int fourOfCard(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[],  unsigned int *nominal)
{
    unsigned int counter[FACES]={0};
     
    size_t i;
     
    for( i = 0; i < 5; ++i)
    {
        ++counter[wPlayer[i][1]];
    }
     
    for( i = 0; i < FACES; ++i)
    {
		if(counter[i] == 4 )
        {
			*nominal = i;
            printf("\nThe hand contains a 4 card %s\n", wFace[i] );
			return 6;
		}
    } 
    return 0;	 
}

int flashOfCard(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned int *nominal)
{
    unsigned int counter[SUITS]={0};
    size_t i;
     
    for( i = 0; i < 5; ++i)
    {
        ++counter[wPlayer[i][0]];
		*nominal += wPlayer[i][1];//вычисляем сумму номиналов карт одной масти
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

int straighOfCard(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned int *nominal)
{ 
    size_t i;
     
    for( i = 0; i < 5; ++i)
    {
		*nominal += wPlayer[i][1];
    }
     
	if(wPlayer[0][1] - 1 == wPlayer[1][1] && wPlayer[1][1] - 1 == wPlayer[2][1] && wPlayer[2][1] - 1 == wPlayer[3][1] && wPlayer[3][1] - 1 == wPlayer[4][1])
	{
		printf("\nThe hand contains a STRAIGHT from %s to %s\n", wFace[wPlayer[4][1]], wFace[wPlayer[0][1]]);
		return 4;
	}	
    return 0;	
}
