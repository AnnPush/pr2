/поиск с возвратом, находит все 92 решения задачи
#include <stdio.h>
#define SIZE 8

void showBoard(int b[][SIZE]);
int tryQueen(int b[][SIZE], int x, int y);
void setQueen(int bor[][SIZE], int a);

int main(void)
{
	int board[SIZE][SIZE] = {0};//доска
	setQueen(board, 0);
}

void showBoard(int b[][SIZE])
{
	for(size_t i = 0; i < SIZE; ++i)
	{
		for(size_t j = 0; j < SIZE; ++j)
		{
			
			printf("%4s", b[i][j]?"Q":".");
		}
		puts("");
	}
}
// Функция tryQueen() - проверяет нет ли уже установленных ферзей,
// по вертикали, диагоналям.
int tryQueen(int b[][SIZE], int x, int y)
{
	for(int i = 0; i < x; ++i)
	{
		if(b[i][y])
		{
			return 0;
		}
	}
	
	for(int i = 1; i <= x && y - i >= 0; ++i)
	{
		if(b[x - i][y - i])
		{
			return 0;
		}
	}
for(	int i = 1; i <= x && y + i < SIZE; ++i)
	{
		if(b[x - i][y + i])
		{
			return 0;
		}
	}
	return 1;
}
// Функция setQueen() - пробует найти результаты решений
void setQueen(int bor[][SIZE], int a)// a - номер очередной строки в которую нужно поставить очередного ферзя.
{
	
	if( a == SIZE)
	{
		showBoard(bor);
		puts("");
		
	}
	for(size_t i = 0; i < SIZE; ++i)
	{// Здесь проверяем, что если поставим в board[a][i] ферзя (единицу),
        // то он будет единственным в этой строке, столбце и диагоналях.
		if(tryQueen(bor, a, i) )
		{
			bor[a][i] = 1;
			setQueen(bor, a + 1);
			bor[a][i] = 0;
		}
	}
}
