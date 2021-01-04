#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 15
#define HEIGHT 11

#define DOWN 0
#define RIGHT 1
#define UP 2
#define LEFT 3

void printArray(char a[][HEIGHT]);
void mazeGenerator(char a[][HEIGHT], int posX, int posY);
int isInBounds(int posX, int posY);
void mazeTraversal(char a[][HEIGHT], int posX, int posY, int pos, int *fX, int *fY);

int main(void)
{
    int row, col;
	int firstposX;
	int firstposY;
	char arr[WIDTH][HEIGHT];
	srand(time(NULL));
	
	for(row = 0; row < WIDTH; row++)
        for(col = 0; col < HEIGHT; col++)
	        arr[row][col] = '#';
			
	row = 1 + rand() % (WIDTH - 2); 
    col = 0;
	arr[row][col] = 'S';
	firstposX = row;
	firstposY = col;
	
	mazeGenerator(arr, row, col + 1);
	int m = 0, n = 0;
	
	while(!m)
	{
		if(HEIGHT - 2 == n)
		{
			n--;
			int t = 1 + rand() % (WIDTH - 2); 
			if(arr[t][HEIGHT - 3] == '.')
			{
				arr[t][HEIGHT - 1] = 'E';
				arr[t][HEIGHT - 2] = '.';
				m++;
			}
		}
		else{
	        int t = 1 + rand() % (WIDTH - 2); 
			if(arr[t][HEIGHT - 2] == '.')
			{
				arr[t][HEIGHT - 1] = 'E';
				m++;
			}
		}
			n++;
	}

	printArray(arr);
	
	mazeTraversal(arr, row, col + 1, RIGHT, &firstposX, &firstposY);
	
	printArray(arr);
}

void mazeGenerator(char a[][HEIGHT], int posX, int posY)
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
	
void printArray(char a[][HEIGHT])
{   
    int i, j;
    puts("");
	for( i = 0; i < WIDTH; ++i)
	{
		for( j = 0; j < HEIGHT; ++j)
		{
			printf("%c", a[i][j]);
		}
		puts("");
	}
}

int isInBounds(int posX, int posY)
{
	if(posX <= 0 || posX >= WIDTH - 1) return false;
	if(posY <= 0 || posY >= HEIGHT - 1) return false;
	return true;
}

void mazeTraversal(char a[][HEIGHT], int posX, int posY, int pos, int *fX, int *fY)
{
	int edge(int x, int y);//проверка(край массива), тогда игра окончена
	int validMove(char a[][HEIGHT], int x, int y);// проверка, можно ли в ячейку записывать данные(это не стена)
	//стартовая позиция
	int firstX = *fX;
	int firstY = *fY;
	int position = 0;
	
	if(a[posX][posY] == 'x')//если мы были уже в ячейке, то поставить заглавную букву, чтобы легче было отслеживать путь по лабиринту
	{
	a[posX][posY] = 'X';
	}
	else
	{
		a[posX][posY] = 'x';
	}
	
	//печать после каждого шага, чтобы отслеживать движение по лабиринту
	
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
					mazeTraversal( a, posX, posY + 1, DOWN, fX, fY);
					
	
					return;
				} 
				break;
				
				case LEFT:
				if(validMove(a, posX, posY - 1))
				{
					mazeTraversal( a, posX, posY - 1, UP, fX, fY);
					return;
				} 
				break;
				
				case UP:
				if(validMove(a, posX - 1, posY))
				{
					mazeTraversal( a, posX - 1, posY, RIGHT, fX, fY);
					return;
				} 
				break;
				
				case DOWN:
				if(validMove(a, posX + 1, posY))
				{
					mazeTraversal( a, posX + 1, posY, LEFT, fX, fY);
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
	if((x == 0 || x == WIDTH -1) && (y >= 0 && y < HEIGHT) || (x >= 0 && x < WIDTH) && (y == 0 || y == HEIGHT - 1))
		ed = 1;
	else
		ed = 0;
	return ed;
	
}

int validMove(char a[][HEIGHT], int x, int y)
{
	return(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && a[x][y] != '#');
}
