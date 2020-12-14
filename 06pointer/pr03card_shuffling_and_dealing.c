#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
//тасовать карты
void shuffle(unsigned int wDeck[][FACES]);
//раздать карты игрокам
void deal(unsigned int wDeck[][FACES], unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int *wStart,  unsigned int *wFinish);
int fPriority(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned int *nominal);//определение приоритета карт игроков
void  sort(unsigned int wPlayer[][2],  const char *wFace[], const  char *wSuit[]);//сортировка карт, которые находятся на руках у каждого игрока
void printArray(unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int pd);//распечатать карты игрока
void takeCards(unsigned int wPlayer[][2], unsigned int *nominal, unsigned int *takeCard);//сколько еще взять карт

int main(void)
{   
    unsigned int deck[SUITS][FACES] = {0};
       
	unsigned int player1[5][2];//карты на руках у первого игрока
	unsigned int player2[5][2];//карты на руках у второго игрока
	unsigned int pl_dl = 0;//если дилер - 1, если игрок -0  
	unsigned int nominal1;
    unsigned int nominal2;
	unsigned int start = 1;
	unsigned int finish = 5;  
	unsigned int p1, p2;
	srand(time(NULL)); 
    shuffle(deck); // shuffle the deck

    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	
    const char *face[FACES] = {"Ace", "Deuce", "Three", "Four",
                                "Five", "Six", "Seven", "Eight",
                                "Nine", "Ten", "Jack", "Queen", "King"};
	
    printf("\nHand1\n\n");
	
	
	//сдать карты первому игроку с 1 по 5
	deal(deck, player1, face, suit, &start, &finish); 
	printArray(player1, face, suit, 1);
	sort(player1, face, suit);
	
	printf("\nHand2\n\n");
	//сдать карты второму игроку с 6 по 10
	finish = 5;
	deal(deck, player2, face, suit, &start, &finish);
	printArray(player2, face, suit, 0);
	printf("\nHand2_sort\n\n");
	sort(player2, face, suit);
	printArray(player2, face, suit, 0);
	
	
	p1 = fPriority(player1, face, suit, &nominal1);
	printf("\nPriority = %u\n\n", p1);
	
    takeCards(player1, &p1, &finish);
	 if(finish != 0)
	 {
		 deal(deck, player1, face, suit, &start, &finish);	 
	 }
	 
	 p1 = fPriority(player1, face, suit, &nominal1);
	printf("\nPriority = %u\n\n", p1);
}

void takeCards(unsigned int wPlayer[][2], unsigned int *prioritet, unsigned int *takeCard)
{
	unsigned int wSortPlayer[5][2] = {0};//временный массив
	unsigned int obmen = 0;//счетчик для карт, которые будут обмениваться
	unsigned int take_card = 100;//счетчик карт, которые составляют комбинацию
	
    if( *prioritet < 7 && *prioritet > 3)//если выпало 4 одинаковые карты флеш, стрит
	{
		take_card = 0;//берем 0 карт
	}
	else if(*prioritet == 0 || *prioritet == 1)//если нет комбинаций или выпала одна пара
	{
		take_card = 3;//взять 3 карты
	}
	else if(*prioritet == 3)//если выпало 3 карты
	{
		take_card = 2;//берем 2 карты
	}
	else if(*prioritet == 2)//в остальных случаях
	{
		take_card = 1;//берем 1 карту
	} 
	*takeCard = take_card;//запоминаем количество карт, которые будут взяты
    printf("\nTake %u cards!\n\n", take_card);

	 if(*prioritet < 4)//все варианты, кроме флеш, 4 карты, стрит
    {
       for( size_t i = 0; i < 5; ++i)
	   {
		    if(*prioritet == 2 && i == 0 && wPlayer[0][1] + 1 == wPlayer[1][1])
			{
				wSortPlayer[0][1] = wPlayer[4][1];
			    wSortPlayer[0][0] = wPlayer[4][0];
			
			}
			else if( wPlayer[i][1] != *prioritet )// элемент массива не равен номиналу комбинации
		    {
				//карта отправляется в начало массива
			    wSortPlayer[obmen][1] = wPlayer[i][1];
				wSortPlayer[obmen][0] = wPlayer[i][0];
			    obmen++;
		    }
			else 
		    { 
				
				wSortPlayer[take_card][1] = wPlayer[i][1];
				wSortPlayer[take_card][0] = wPlayer[i][0];
				++take_card;
		    }
	   }
	   //перезависать из временного массива карты
	   for( size_t i = 0; i < 5; ++i)
	   {
	        wPlayer[i][1]=wSortPlayer[i][1];
	        wPlayer[i][0]=wSortPlayer[i][0];
	   }
	}
}

//распечатать карты игрока
void printArray(unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int pd)
{
	for( size_t i = 0; i < 5; ++i)
    {		
	     if(pd == 0)
	     {
		     printf("%5s of %-8s\n ", wFace[ wPlayer[i][1]],  wSuit[ wPlayer[i][0]] );
	     }
	     else
	     {
             printf("%s\n","***");
	     }
    }
    printf("\n ");
}


void  sort(unsigned int wPlayer[][2],  const char *wFace[], const  char *wSuit[])
{
	void swap(unsigned int * element1Ptr, unsigned int * element2Ptr);//функция обменивающая карты в ячейках, на которые показывают указатели

	for( size_t i = 0; i < 4; ++i)
    {
		for( size_t j = 0; j < 4; ++j)
        {
			if(wPlayer[j][1] < wPlayer[j+1][1])
			{
				swap(&wPlayer[j][1], &wPlayer[j+1][1]);
			    swap(&wPlayer[j][0], &wPlayer[j+1][0]);//обмен элементов
			}			
		}
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
// сдать карты
void deal(unsigned int wDeck[][FACES], unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int *wStart,  unsigned int *wFinish)
{
	 unsigned int r = 0;//счетчик определяющий номинал и масть карт
	 *wFinish += *wStart;//определить конечную карту при раздаче
     
	 // сдать карты в указанных пределах
     for (size_t card = *wStart; card < *wFinish; ++card)
	 {
		// цикл по строкам
         for (size_t row = 0; row < SUITS; ++row)
		 {
			 // цикл по столбцам в текущей строке
             for (size_t column = 0; column < FACES; ++column)
		     {
                 if (wDeck[row][column] == card) 
				 {
					 wPlayer[r][0] = row;//запомнить масть карты, полученной игроком
					 wPlayer[r][1] = column;//запомнить номинал карты, полученной игроком
	                 //printf("%5s of %-8s\t \n", wFace[column], wSuit[row]);
					 ++r;
                 }
             }
         }
     }
	 *wStart = *wFinish;
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
