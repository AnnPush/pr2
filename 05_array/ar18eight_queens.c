#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8


void printArray(int b[][SIZE]);//печать доски
int acessibilityHeuristic(int b[][SIZE], int v[], int h[], int x, int y);//функция высчитывает, сколько клеток будет бить ферзь, установленный на данную клетку доски
void setQueen(int b[][SIZE], int v[], int h[], int x, int y);


int main(void)
{
	int board[SIZE][SIZE] = {0};//доска
    int accessibility[SIZE][SIZE] = {0};//инициализация массива таблицы эвристики доступности клетки нулями
	
	//движение ферзя
	int horizontal[SIZE] = {1,  1,  0, -1, -1, -1, 0, 1};
	int vertical[SIZE]   = {0, -1, -1, -1,  0,  1, 1, 1};
	
	int pos[SIZE][2];//координаты установленных ферзей
	
	//пробуем установить 8 ферзей
	for(size_t k = 0; k < SIZE; ++k)
	{
		//рассматриваем все клетки доски
		for(size_t i = 0; i < SIZE; ++i)
		{
			for(size_t j = 0; j < SIZE; ++j)
			{
				accessibility[i][j] = acessibilityHeuristic(board, horizontal, vertical, i, j);
			}
		}
		
		//находим ячейку массива accessibility с минимальным значением, записываем координаты в массив pos
		int counter = 0;
		int min = 100;
		int n = 0;
		int m = 0;
		
		//ищем наименьшие элементы и одновременно считываем их количество, при этом пропускаем элементы = 0
		for(size_t i = 0; i < SIZE; ++i)
		{
			for(size_t j = 0; j < SIZE; ++j)
			{
				if(accessibility[i][j] < min && accessibility[i][j] > 1 )
				{
					min = accessibility[i][j];
					n = i;
					m = j;
					counter = 1;
				}
				else if(accessibility[i][j] == min)
				{
					++counter;
				}
			}
				
		}	
			
				if(counter != 0)
				{
					srand(time(NULL));
					counter = rand() % counter;
					
					//определяем координаты клетки, соответствующей выбранному ходу
					for(size_t i = 0; i < SIZE; ++i)
		            {
		            	for(size_t j = 0; j < SIZE; ++j)
			            {
							if(accessibility[i][j] == min && counter == 0)
							{
								n = i;
								m = j;
							}
							if(accessibility[i][j] == min)
							{
								--counter;
							}
						}
							
					}
					pos[k][0] = n;
							pos[k][1] = m;
					
				}
		
			
				
		setQueen(board, horizontal, vertical, pos[k][0], pos[k][1]);
		 
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

int acessibilityHeuristic(int b[][SIZE], int v[], int h[], int x, int y)
{
	int count = 1;
	
	if(x >= 0 && x < SIZE && y >= 0 && y < SIZE && b[x][y] == 0 )
	{
		for(size_t i = 0; i < SIZE; ++i)
		{
		    for(size_t j = 0; j < SIZE; ++j)
		    {
				int movH = x + h[i] * (j + 1);
                int movV = y + v[i] * (j + 1);	

                if(movH >= 0 && movH < SIZE && movV >= 0 && movV < SIZE && b[movH][movV] == 0 )
                {
                    count++;					
                }	
		    }
	    }
	}
	else if(x >= 0 && x < SIZE && y >= 0 && y < SIZE && b[x][y] != 0 )
	{
	    count = b[x][y];
	}
	

	return count;
}
//end acessibilityHeuristic

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
