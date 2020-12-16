#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
#define SIZE 5

//тасовать карты
void shuffle(unsigned int wDeck[][FACES]);
//раздать карты игрокам
void deal(unsigned int wDeck[][FACES], unsigned int wPlayer[][2], unsigned int *wStart,  unsigned int *wFinish);
int fPriority(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned int *nominal, unsigned int pd);//определение приоритета карт игроков
void  sort(unsigned int wPlayer[][2],  const char *wFace[], const  char *wSuit[]);//сортировка карт, которые находятся на руках у каждого игрока
void printArray(unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int pd);//распечатать карты игрока
void takeCards(unsigned int wPlayer[][2], unsigned int *prioritet, unsigned int *takeCard, unsigned int *nominal);//сколько еще взять карт
void swap(unsigned int * element1Ptr, unsigned int * element2Ptr);//функция обменивающая карты в ячейках, на которые показывают указатели
//оценка карт игроков
void mark(unsigned int wPlayer1[][2], unsigned int wPlayer2[][2], const char *wFace[], const  char *wSuit[], unsigned int *nominal1, unsigned int *nominal2, unsigned int *p1, unsigned int *p2);
int  printRating(unsigned int*, unsigned int*);//печать результата оценивания карт

int main(void)
{    //1_ инициализация колоды карт нулями
	 //unsigned int deck[SUITS][FACES] = {0};

	 //2_ инициализация колоды карт_нет комбинаций_у_игроков
     //unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21,  5, 17, 19, 11, 20, 26, 37,  9, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10,  3, 27, 16, 18, 23, 25, 34, 35, 36,  6, 38, 39, 40, 41, 14, 42, 43, 44, 45, 46,  4, 48, 49,  7, 51, 52};
     //массив_по_порядку
	 //unsigned int deck[SUITS][FACES] = { 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52};
	 
	 //3_ инициализация колоды карт_комбинация_1_ПАРА_у_первого_игрока
     //unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21,  5, 17, 19, 11, 20, 26, 37,  9, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10, 27,  3, 16, 18, 23, 25, 34, 35, 36,  6, 38, 39, 40, 41, 14, 42, 43, 44, 45, 46,  4, 48, 49,  7, 51, 52};
     
	 //4_ инициализация колоды карт_комбинация_2_ПАРЫ_у_первого_игрока
	 //unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21,  5, 17, 19, 11, 20, 26, 37,  9, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10, 27,  3, 16, 18, 23, 25, 34, 35, 36,  6, 38, 39, 40, 41, 14, 42, 43, 44, 45, 46, 49, 48,  4,  7, 51, 52};
     
	 //5_ инициализация колоды карт_комбинация_3_КАРТЫ_у_первого_игрока
     //unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21,  5, 17, 19, 11, 20, 26, 37,  9, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10, 27,  3, 16, 18, 23, 25, 34, 35, 36,  6, 38, 39, 40, 41,  4, 42, 43, 44, 45, 46, 49, 48, 14,  7, 51, 52};
    
     //6_ инициализация колоды карт_комбинация_4_КАРТЫ_у_первого_игрока
     //unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21, 37, 17, 19, 11, 20, 26,  5,  9, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10, 27,  3, 16, 18, 23, 25, 34, 35, 36,  6, 38, 39, 40, 41,  4, 42, 43, 44, 45, 46, 49, 48, 14,  7, 51, 52};
     
     //7_ инициализация колоды карт_комбинация_ФЛЕШ_у_первого_игрока
     //unsigned int deck[SUITS][FACES] = { 4,  1, 13, 31,  2, 33,  3, 21,  5, 17, 19, 11, 20, 26, 37,  9, 50, 12, 30, 22, 24, 47, 32, 29, 15, 10, 27,  8, 16, 18, 23, 25, 34, 35, 36,  6, 38, 39, 40, 41, 28, 42, 43, 44, 45, 46, 49, 48, 14,  7, 51, 52};
     
	 //8_ инициализация колоды карт_комбинация_СТРИТ_у_первого_игрока
     //unsigned int deck[SUITS][FACES] = {25,  1, 13, 31,  5, 33, 50, 21, 42, 17, 19, 11, 20, 26, 37,  9,  3, 12, 30, 22, 24, 47, 32, 29, 15, 10, 27,  8, 16, 18, 23,  4, 34, 35, 36,  6, 38, 39, 40, 41, 28,  2, 43, 44, 45, 46, 49, 48, 14,  7, 51, 52};
     
     //9_ инициализация колоды карт_ФЛЕШ_ДРО_у_первого_игрока
     //unsigned int deck[SUITS][FACES] = { 4,  1, 13, 31, 48, 33,  3, 21,  5, 17, 19, 11, 20, 26, 37,  9, 50, 12, 30, 22, 24, 47, 32, 29, 15, 10, 27,  8, 16, 18, 23, 25, 34, 35, 36,  6, 38, 39, 40, 41, 28, 42, 43, 44, 45, 46, 49,  2, 14,  7, 51, 52};
     
	 //10_ инициализация колоды карт_СТРИТ_ДРО_у_первого_игрока
     //unsigned int deck[SUITS][FACES] = {25, 38, 13, 31,  5, 33, 50, 21, 42, 17, 19, 11, 20, 26, 37,  9,  3, 12, 30, 22, 24, 47, 32, 29, 15, 10, 27,  8, 16, 18, 23,  4, 34, 35, 36,  6,  1, 39, 40, 41, 28,  2, 43, 44, 45, 46, 49, 48, 14,  7, 51, 52};
     
     //11_ инициализация колоды карт_КОМБО_ДРО_у_первого_игрока
     //unsigned int deck[SUITS][FACES] = {25,  1, 13, 31, 48, 33, 50, 21, 42, 17, 19, 11, 20, 26, 37,  9, 14, 12, 30, 22, 24, 47, 32, 29, 15, 10, 27,  8, 16, 18, 23, 46, 34, 35, 36,  6, 38, 39, 40, 41, 28, 49, 43, 44, 45,  4,  2,  5,  3,  7, 51, 52};
     
	 //12_ инициализация колоды карт_комбинация_1_ПАРА_у_двух_игроков
     //unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21,  5, 17, 19, 11, 20, 26, 37,  9, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10, 27,  3, 16, 18, 23, 25, 34, 35, 36, 40, 38, 39,  6, 41, 14, 42, 43, 44, 45, 46,  4, 48, 49,  7, 51, 52};
    
	 //13_ инициализация колоды карт_комбинация_2_ПАРЫ_у_двух_игроков
     //unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21,  5, 17,  9, 11, 20, 26, 37, 49, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10, 27,  3, 16, 18, 23, 25, 34, 35, 36, 40, 38, 39,  6, 41, 14, 42, 43, 44, 45, 46, 19, 48,  4,  7, 51, 52};
    
	 //14_ инициализация колоды карт_комбинация_3_КАРТЫ_у_двух_игроков
     //unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21,  5, 17, 19, 11,  9, 26, 37, 20, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10, 27,  3, 16, 18, 23, 25, 34, 35, 36, 40, 38, 39,  6, 41,  4, 42, 43, 44, 45, 46, 49, 48, 14,  7, 51, 52};
    
     //15_ инициализация колоды карт_комбинация_4_КАРТЫ_у_двух_игроков
     //unsigned int deck[SUITS][FACES] = { 6,  1, 13, 31, 32, 33, 41, 21, 37, 17, 19, 11, 20,  7,  5, 28, 50, 12, 30, 22, 24, 47,  2, 29, 15, 27, 10,  3, 16, 18, 23, 25, 34, 35, 36,  9, 38, 39, 40,  8,  4, 42, 43, 44, 45, 46, 49, 48, 14, 26, 51, 52};
     
     //16_ инициализация колоды карт_комбинация_ФЛЕШ_у_двух_игроков
     //unsigned int deck[SUITS][FACES] = { 4,  1, 13, 31,  2, 33,  3, 21,  5, 17, 19, 11, 20, 26,  8, 16, 50, 12,  6, 22, 24, 10, 32,  7, 15,  9, 27, 37, 47, 18, 23, 25, 34, 35, 36, 30, 38, 39, 40, 41, 28, 42, 43, 44, 45, 46, 49, 48, 14, 29, 51, 52};
     
	 //17_ инициализация колоды карт_комбинация_СТРИТ_у_двух_игроков
     //unsigned int deck[SUITS][FACES] = {25,  1, 13, 10,  5, 33, 50, 21, 42, 17, 19, 11, 20, 26, 37,  8,  3, 12, 30, 22, 24, 47, 32, 29, 15, 31,  6, 28, 16, 18, 23,  4, 34, 35, 36, 27, 38, 39, 40, 41,  9,  2, 43,  7, 45, 46, 49, 48, 14, 44, 51, 52};
    
     //18_ инициализация колоды карт_ФЛЕШ_ДРО_у_первого_двух_игроков
     //unsigned int deck[SUITS][FACES] = { 4,  1, 13, 31, 48, 33,  3, 21,  5, 17, 19, 37, 20, 26,  8, 16, 50, 12, 30, 22, 24, 10, 32,  7, 15,  9, 27, 11, 47, 18, 23, 25, 34, 35, 36, 44, 38, 39, 40, 41, 28, 42, 43,  6, 45, 46, 49,  2, 14, 29, 51, 52};
     
	 //19_ инициализация колоды карт_СРИТ_ДРО_у_первого_двух_игроков
     //unsigned int deck[SUITS][FACES] = {25, 38, 13, 10,  5, 33, 50, 21, 42, 17, 19, 11, 20, 26, 37,  8,  3, 12, 52, 22, 24, 47, 32, 29, 15, 31,  6, 28, 16, 18, 23,  4, 34, 35, 36, 27,  1, 39, 40, 41,  9,  2, 43, 44, 45, 46, 49, 48, 14, 30, 51,  7};
      
     //20_ инициализация колоды карт_КОМБО_ДРО_у_первого_двух_игроков
     //unsigned int deck[SUITS][FACES] = {25,  1, 13, 31, 48, 33, 50, 21, 42, 17, 19, 11, 20, 26, 37, 47, 14, 12,  7,  6,  8,  9, 32, 29, 15, 27, 10, 24, 16, 18, 23, 46, 34, 35, 36, 22, 38, 39, 40, 41, 28, 49, 43, 44, 45,  4,  2,  5,  3, 30, 51, 52};
     
     //21_ инициализация колоды карт_ФЛЕШ_у_первого_игрока_4_КАРТЫ_у_второго_игрока
     //unsigned int deck[SUITS][FACES] = { 6,  1, 13, 31,  2, 33,  3, 21,  5, 17, 19, 11,  4,  7, 37, 20, 50, 12, 30, 22, 24, 47, 32, 29, 15, 27, 10, 41, 16, 18, 23, 25, 34, 35, 36,  9, 38, 39, 40,  8, 28, 42, 43, 44, 45, 46, 49, 48, 14, 26, 51, 52};
      
     //22_ инициализация колоды карт_СТРИТ_у_первого_игрока_3_КАРТЫ_у_второго_игрока
     //unsigned int deck[SUITS][FACES] = {25,  1, 13, 31,  5, 33,  8, 21, 42, 17, 19, 11,  9, 26, 37, 20,  3, 12, 30, 22, 24, 47, 32, 29, 15, 10, 27, 50, 16, 18, 23,  4, 34, 35, 36, 40, 38, 39,  6, 41, 28,  2, 43, 44, 45, 46, 49, 48, 14,  7, 51, 52};
      
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
	deal(deck, player1, &start, &finish); 
	printArray(player1, face, suit, 1);
	//printf("\nHand1_sort\n\n");
	sort(player1, face, suit);
	//printArray(player1, face, suit, 0);
	
	printf("\nHand2\n\n");
	//сдать карты второму игроку с 6 по 10
	finish = 5;
	deal(deck, player2, &start, &finish);
	printArray(player2, face, suit, 0);
	printf("\nHand2_sort\n\n");
	sort(player2, face, suit);
	printArray(player2, face, suit, 0);
	
	
	p1 = fPriority(player1, face, suit, &nominal1, 1);
	//printf("\nPriority_1 = %u\n\n", p1);
	
    takeCards(player1, &p1, &finish, &nominal1);
	 printf("\nTake %u cards!\n\n",finish);
	 if(finish != 0)
	 {
		 deal(deck, player1,  &start, &finish);	 
		 //printf("\nNew_array_1\n");
		 //printArray(player1, face, suit, 0);
		 
		 //printf("\nHand1_sort_new\n\n");
	sort(player1, face, suit);
	//printArray(player1, face, suit, 0);
	 }
	 
	 p1 = fPriority(player1, face, suit, &nominal1, 1);
	//printf("\nPriority_1_new = %u\n\n", p1);
	
	

	 printf("\nHand2-------------------\n\n");
	 
	 p2 = fPriority(player2, face, suit, &nominal2, 0);
	printf("\nPriority_2 = %u\n\n", p2);
	
	 takeCards(player2, &p2, &finish, &nominal2);
	 printf("\nHow many cards do you want to take?\n\n");
	 scanf("%u", &finish);
	 	 if(finish != 0)
	 {
		 deal(deck, player2, &start, &finish);
	
		 printf("\nNew_array_2\n");
		 printArray(player2, face, suit, 0);
		 printf("\nHand2_sort_new\n\n");
	sort(player2, face, suit);
	printArray(player2, face, suit, 0);
	 }
	 p2 = fPriority(player2, face, suit, &nominal2, 0);
	printf("\nPriority_2_new = %u\n\n", p2);
	
	printf("\nMark\n\n");
	printf("\nHand1\n\n");
	printArray(player1, face, suit, 0);
	printf("\nHand2\n\n");
	printArray(player2, face, suit, 0);
	//оценить карты игроков
	mark(player1, player2, face, suit, &nominal1, &nominal2, &p1, &p2);	
	
	
}
void mark(unsigned int wPlayer1[][2], unsigned int wPlayer2[][2], const char *wFace[], const  char *wSuit[], unsigned int *nominal1, unsigned int *nominal2, unsigned int *p1, unsigned int *p2)
{
	
    int flag = 0;
	
	
	
	if(!printRating(p1, p2))//сравнить комбинации карт
	{
	    if(!printRating(nominal1, nominal2))//если комбинации равны, сравнить номиналы
		{
		    for(size_t i = 5 ; i > 0; --i)
			{
				if(!printRating(&wPlayer1[i][1], &wPlayer2[i][1]))//если номиналы равны, сравнение идет по сортированному массиву по старшей карте
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

int printRating(unsigned  int* ptr1, unsigned  int* ptr2)
{
	if(*ptr1 > *ptr2)
	{
		printf("\nDEALER is the better hand\n");
		return 1;
	}
	 else if(*ptr1 < *ptr2)
	{
        printf("\nPLAYER is the better hand\n");
		return 1;
	}
    return 0;
}

void takeCards(unsigned int wPlayer[][2], unsigned int *prioritet, unsigned int *takeCard, unsigned int *nominal)
{
	unsigned int wSortPlayer[5][2] = {0};//временный массив
	unsigned int obmen = 0;//счетчик для карт, которые будут обмениваться
	unsigned int take_card = 0;//счетчик карт, которые составляют комбинацию
	
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
	else if(*prioritet == 2)//если выпало 2 карты
	{
		take_card = 1;//берем 1 карту
	} 
	*takeCard = take_card;//запоминаем количество карт, которые будут взяты
   
if(*prioritet == 2 )
			{
				if(wPlayer[3][1] != wPlayer[4][1])
			{
				swap(&wPlayer[0][1], &wPlayer[4][1]);
				swap(&wPlayer[0][0], &wPlayer[4][0]);
				swap(&wPlayer[1][1], &wPlayer[3][1]);
				swap(&wPlayer[1][0], &wPlayer[3][0]);
			
			}
			else if( wPlayer[2][1] != wPlayer[1][1])
			{
				swap(&wPlayer[0][1], &wPlayer[2][1]);
				swap(&wPlayer[0][0], &wPlayer[2][0]);
				
			}
			}
	else if(*prioritet != 2 && *prioritet < 4)//все варианты, кроме флеш, 4 карты, стрит
    {
       for( size_t i = 0; i < 5; ++i)
	   {
		    
			if(wPlayer[i][1] != *nominal )// элемент массива не равен номиналу комбинации
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
	

	for( size_t i = 0; i < 4; ++i)
    {
		for( size_t j = 0; j < 4; ++j)
        {
			if(wPlayer[j][1] > wPlayer[j+1][1])
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


int fPriority(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned  int *nominal, unsigned int pd)
{
	int oneOfPair(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned int *nominal, unsigned int pd);
    int twoOfPair(unsigned int wPlayer[][2],  const char *wFace[],  const char *wSuit[], unsigned int *nominal, unsigned int pd);
    int treeOfCard(unsigned int wPlayer[][2],  const char *wFace[],  const char *wSuit[], unsigned int *nominal, unsigned int pd);
    int fourOfCard(unsigned int wPlayer[][2],  const char *wFace[],  const char *wSuit[], unsigned int *nominal, unsigned int pd);
    int flashOfCard(unsigned int wPlayer[][2],  const char *wFace[], const char *wSuit[], unsigned int *nominal, unsigned int pd);
    int straighOfCard(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned int *nominal, unsigned int pd);

    int (*ptr_f[6])(unsigned int [][2], const char* [], const char* [], unsigned int *, unsigned int) = {oneOfPair, twoOfPair, treeOfCard, straighOfCard, flashOfCard, fourOfCard};

    unsigned int priority;
	
	for(int i = 0; i < 6; ++i)
	{
		priority =(*ptr_f[i])(wPlayer, wFace, wSuit, nominal, pd);
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
void deal(unsigned int wDeck[][FACES], unsigned int wPlayer[][2],  unsigned int *wStart,  unsigned int *wFinish)
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

int oneOfPair(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned int *nominal, unsigned int pd)
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
		 if(pd == 0)
		 {
        printf("\nThe hand contains a pair %s\n", wFace[*nominal] );
		 }
		return 1;
	 }
	 return 0;
}

int twoOfPair(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned int *nominal, unsigned int pd)
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
		   if(pd == 0)
           printf("\nThe hand contains a 2 %s \n", wFace[i]);
		}		 	
    } 
    if(n == 2)
	{
	    return 2;
	}
	return 0;
}

int treeOfCard(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned int *nominal, unsigned int pd)
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
			if(pd == 0)
            printf("\nThe hand contains a 3 card %s\n", wFace[i] );
			return 3;
		}
    }
    return 0;	 
}

int fourOfCard(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[],  unsigned int *nominal, unsigned int pd)
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
			if(pd == 0)
            printf("\nThe hand contains a 4 card %s\n", wFace[i] );
			return 6;
		}
    } 
    return 0;	 
}

int flashOfCard(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned int *nominal, unsigned int pd)
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
			if(pd == 0)
            printf("\nThe hand contains a FLASH card %s\n", wSuit[i] );
			return 5;
		}
    } 
    return 0;	 
}

int straighOfCard(unsigned int wPlayer[][2], const char *wFace[],  const char *wSuit[], unsigned int *nominal, unsigned int pd)
{ 
    size_t i;
     
    for( i = 0; i < 5; ++i)
    {
		*nominal += wPlayer[i][1];
    }
     
	if(wPlayer[4][1] - 1 == wPlayer[3][1] && wPlayer[3][1] - 1 == wPlayer[2][1] && wPlayer[2][1] - 1 == wPlayer[1][1] && wPlayer[1][1] - 1 == wPlayer[0][1])
	{
		if(pd == 0)
		printf("\nThe hand contains a STRAIGHT from %s to %s\n", wFace[wPlayer[4][1]], wFace[wPlayer[0][1]]);
		return 4;
	}	
    return 0;	
}
