#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8


void printArray(int b[][SIZE]);//печать доски
void setQueen(int b[][SIZE], int v[], int h[], int x, int y);


int main(void)
{
	int board[SIZE][SIZE] = {0};//доска
	int t, p = 0;
	int i, j;
	//движение ферзя
	int horizontal[SIZE] = {1,  1,  0, -1, -1, -1, 0, 1};
	int vertical[SIZE]   = {0, -1, -1, -1,  0,  1, 1, 1};
	
	
	srand(time(NULL));
	//пробуем установить 8 ферзей
	for(size_t k = 0; k < SIZE; ++k)
	{
		t = 1;
		
		while( t != 0 && p < 64)
		{
		   p++;
		   i = rand() % SIZE;
		   j = rand() % SIZE;
		
		   if(board[i][j] == 0)
		   {
			   t = 0;
		   }
		}		
		setQueen(board, horizontal, vertical, i, j);
	}
    printArray(board);
}
//end main

void printArray( int b[][SIZE])
{
	for(int i = 0; i < SIZE; i++)
	{
		puts(" ");
		for(int j = 0; j < SIZE; j++)
		{
		    
			if(b[i][j] == 1)
			{
				printf("%4s", "Q");
			}
			else
			{
				printf("%4s", ".");
			}
		}
	}
}
//end printArray

void setQueen(int b[][SIZE], int v[], int h[], int x, int y)
{
	if(x >= 0 && x < SIZE && y >= 0 && y < SIZE && b[x][y] == 0)
	{
		b[x][y] = 1;
		for(size_t i = 0; i < SIZE; ++i)
		{
		    for(size_t j = 0; j < SIZE; ++j)
		    {
				int movH = x + h[i] * (j + 1);
				int movV = y + v[i] * (j + 1);
				if(movH >= 0 && movH < SIZE && movV >= 0 && movV < SIZE)
				{
				    b[movH][movV] = -1;
				}
			}
		}
	}
}
