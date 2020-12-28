#include <stdio.h>

#define SIZE 12

#define DOWN 0
#define RIGHT 1
#define UP 2
#define LEFT 3

void printArray(char a[][SIZE], int size);//печать массива
void mazeTraversal(char a[][SIZE], int posX, int posY, int pos);//движение по лабиринту


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

void mazeTraversal(char a[][SIZE], int posX, int posY, int pos)
{
	int edge(int x, int y);//проверка(край массива), тогда игра окончена
	int validMove(char a[][SIZE], int x, int y);// проверка, можно ли в ячейку записывать данные(это не стена)
	//стартовая позиция
	int firstX = 2;
	int firstY = 0;
	int position = 0;
	
	if(a[posX][posY] == 'x')//если мы были уже в ячейке, то поставить заглавную букву, чтобы легче было отслеживать путь по лабиринту
	{
	a[posX][posY] = 'X';
	}
	else
	{
		a[posX][posY] = 'x';
	}
	
	printArray(a, SIZE);//печать после каждого шага, чтобы отслеживать движение по лабиринту
	
	//выхода из лабиринта не существует, поэтому игрок вернулся в точку входа(стартовую позицию)
	if(posX == firstX && posY == firstY && position == 1)
	{
		printf("\n%s\n", "***Starting position***");
		return;
	}
	//игра окончена, так как игрок находится на краю лабиринта, но это не стартовая точка
    else if((edge(posX, posY) && posX != firstX) && posY != firstY)
	{
		printf("\n%s\n", "***Done***");
		return;
	}
	//иначе делаем следующий ход
	else
	{
		int i, next;
		position = 1;
		
		for(i = 0, next = pos; i < 4; ++i, ++next, next %= 4)//возможен ход в одном из четырех направлений
		{
			switch(next)
			{
				case RIGHT:
				if(validMove(a, posX, posY + 1))
				{
					mazeTraversal( a, posX, posY + 1, DOWN);
					
	
					return;
				} 
				break;
				
				case LEFT:
				if(validMove(a, posX, posY - 1))
				{
					mazeTraversal( a, posX, posY - 1, UP);
					return;
				} 
				break;
				
				case UP:
				if(validMove(a, posX - 1, posY))
				{
					mazeTraversal( a, posX - 1, posY, RIGHT);
					return;
				} 
				break;
				
				case DOWN:
				if(validMove(a, posX + 1, posY))
				{
					mazeTraversal( a, posX + 1, posY, LEFT);
					return;
				} 
				break;
			}
		}
	}
	
}

int edge(int x, int y)
{
	int ed;
	if((x == 0 || x == 11) && (y >= 0 && y <= 11) || (x >= 0 && x <= 11) && (y == 0 || y == 11))
		ed = 1;
	else
		ed = 0;
	return ed;
	
}

int validMove(char a[][SIZE], int x, int y)
{
	return(x >= 0 && x <= 11 && y >= 0 && y <= 11 && a[x][y] != '#');
}
