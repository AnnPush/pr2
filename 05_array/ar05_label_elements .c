#include <stdio.h>
#define SIZE1 3
#define SIZE2 5
int main(void)
{
	int sales[SIZE1][SIZE2];//объявляем двумерный массив
	
        //устанавливаем элементы в нуль
	for (int row = 0; row < SIZE1; row++ )
	{
		for (int column = 0; column < SIZE2; column++ )
		{
			sales[row][column] = 0;
		}
	}
        //выводим массив на экран
        for (int row = 0; row < SIZE1; row++ )
	{
		puts("");
        for (int column = 0; column < SIZE2; column++ )
		{
	        printf("[%d][%d] = %d  ", row, column, sales[row][column] );
		}
	}
}
