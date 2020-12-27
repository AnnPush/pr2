#include <stdio.h>

#define SIZE 12

#define DOWN 0
#define RIGHT 1
#define UP 3
#define LEFT 3

void printArray(char a[][SIZE], int size);
void mazeTraversal(char a[][SIZE], int posX, int posY, int pos);

int main(void)
{
	
	char arr[SIZE][SIZE] = {
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
		{'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
		{'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
		{'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
		{'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
	};
	
	mazeTraversal(arr, 2, 0, RIGHT);
	printArray(arr, SIZE);
		
}
void printArray(char a[][SIZE], int size)
{puts("");
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			printf("%c", a[i][j]);
		}
		puts("");
	}
}

void mazeTraversal(char a[][SIZE], int posX, int posY, int pos)
{
	int position = 0;
	
	a[posX][posY] = 'x';
	
	printArray(a, SIZE);
	
}
