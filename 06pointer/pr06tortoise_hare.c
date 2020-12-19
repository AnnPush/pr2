#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 70

void printArray(const char a[], int size);
int move( char a[], int *currTortoise, int *currHare );

int main(void)
{
	char arr[ SIZE ];
	int currentTortoise = 1, currentHare = 1;
	int whoWins = 0;
	
	printf( "***---Race---***\n\n" );

    printf( "BANG!!!\nAND THEY'RE OFF!!!\n\n ");
	srand( time( NULL ) );
	
	while ( whoWins == 0 ) 
	    whoWins = move(arr, &currentTortoise, &currentHare);
	     
    puts("");	
	if(currentTortoise > currentHare)
	    printf( "TORTOISE WINS!!! YAY!!!\n\n ");
	else if(currentTortoise < currentHare)
	    printf( "HARE WINS!!! YUCH!!!\n\n ");
	else
	    printf( "HARE = TORTOISE!!!\n\n ");
}
int move( char a[], int *currTortoise, int *currHare)
{
    puts("");
	for(int i = 1; i <= SIZE; ++i)
	    a[i] = ' '; 	
	
	int step;
	int tortoise = *currTortoise;
	int hare = *currHare;
	
	step = 1 + rand() % 10;
	
	if(step < 6)
	    tortoise += 3;
	else if(step > 5 && step < 8)
		tortoise -= 6;
	else if(step > 7)
		tortoise += 1;
	
	if(tortoise < 1)
		tortoise = 1;
	else if(tortoise > 70)
		tortoise = 70;

	*currTortoise = tortoise;
	
	step = 1 + rand() % 10;
	
	if(step > 0 && step < 3)
	    ;
	else if(step >2 && step < 5)
		hare += 9;
	else if(step == 5)
		hare -= 12;
	else if(step > 5 && step < 9)
		hare += 1;
	else if(step > 8)
		hare -= 2;
	
	if(hare < 1)
		hare = 1;
	else if(hare > 70)
		hare = 70;
	
     *currHare = hare;
	 
	if(*currTortoise == *currHare)
	{
		a[*currTortoise] = 'O';
		a[*currTortoise + 1] ='U';
		a[*currTortoise + 2] ='C';
		a[*currTortoise + 3] ='H';
	}
	else 
	{
		a[*currTortoise] = 'T';
		a[*currHare] = 'H';
	}
	printArray(a, SIZE);
	if(*currTortoise  == 70 || *currHare == 70)
	    return 1;

	return 0;
}
void printArray(const char a[], int size)
{
	for(int i = 1; i <= size; ++i)
	   printf("%c  ", a[i]); 	
}
