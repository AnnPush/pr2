#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 12

#define DOWN 0
#define RIGHT 1
#define UP 2
#define LEFT 3

void printArray(char a[][SIZE], int size);
void mazeGenerator(char a[][SIZE], int posX, int posY);
int isInBounds(int posX, int posY);

int main(void)
{
    int row, col;
	char arr[SIZE][SIZE];
	srand(time(NULL));
	
	for(row = 0; row < SIZE; row++)
        for(col = 0; col < SIZE; col++)
	        arr[row][col] = '#';
			
	row = 1 + rand() % (SIZE - 2); 
    col = 0;
	arr[row][col] = 'S';
	
	mazeGenerator(arr, row, col + 1);
	int m = 0, n = 0;
	
	while(!m)
	{
		if(SIZE - 2 == n)
		{
			n--;
			int t = 1 + rand() % (SIZE - 2); 
			if(arr[t][SIZE - 3] == '.')
			{
				arr[t][SIZE - 1] = 'E';
				arr[t][SIZE - 2] = '.';
				m++;
			}
		}
		else{
	        int t = 1 + rand() % (SIZE - 2); 
			if(arr[t][SIZE - 2] == '.')
			{
				arr[t][SIZE - 1] = 'E';
				m++;
			}
		}
			n++;
	}

	printArray(arr, SIZE);
}

void mazeGenerator(char a[][SIZE], int posX, int posY)
{
	int t = 0;
	a[posX][posY] = '.';
	
	int dirs[4];
	dirs[0] = DOWN;
	dirs[1] = RIGHT;
	dirs[2] = UP;
	dirs[3] = LEFT;
	
	for(int i = 0; i < 4; ++i)
	{
		int r = rand() % 3;
		int temp = dirs[r];
		dirs[r] = dirs[i];
		dirs[i] = temp;
	}
	
	for(int i = 0; i < 4; ++i)
	{
		int dx = 0, dy = 0;
		
		switch(dirs[i])
		{
			case DOWN:  dy = -1; break;
			case RIGHT: dx =  1; break;
			case UP:    dy =  1; break;
			case LEFT:  dx = -1; break;
		}
		int x2 = posX + (dx<<1);
		int y2 = posY + (dy<<1);
		
		if(isInBounds(x2, y2))
		{
			if(a[x2][y2] == '#')
			{
				a[x2 - dx][y2 - dy] = '.';
				mazeGenerator(a, x2, y2);
			}
		}
	}
}
	
void printArray(char a[][SIZE], int size)
{   
    int i, j;
    puts("");
	for( i = 0; i < size; ++i)
	{
		for( j = 0; j < size; ++j)
		{
			printf("%c", a[i][j]);
		}
		puts("");
	}
}

int isInBounds(int posX, int posY)
{
	if(posX <= 0 || posX >= SIZE - 1) return false;
	if(posY <= 0 || posY >= SIZE - 1) return false;
	return true;
}
