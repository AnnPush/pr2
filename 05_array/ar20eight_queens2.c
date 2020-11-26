#include <stdio.h>

#define SIZE 8

void resetQ(int b[][SIZE], int i, int j);
void setQ(int b[][SIZE], int i, int j);
int tryQ(int b[][SIZE], int i);
void printArray(int b[][SIZE]);

int main()
{
	int board[SIZE][SIZE] = {0};//доска
    tryQ(board, 0);
	printArray(board);
}

void printArray(int b[][SIZE])
{
    for(int i = 0; i < SIZE; ++i)
    {
        for(int j = 0; j < SIZE; ++j)
        {
            if (b[i][j] == -1)
			{
                printf("%4s", "Q");
			}
            else 
			{
                printf("%4s", ".");
            }
        }
        puts("");
    }
}
 
void resetQ(int b[][SIZE], int i, int j)
{
    for(int x = 0; x < SIZE; ++x)
    {
        --b[x][j];
        --b[i][x];
        int k;
        k = j - i + x;
        if (k >= 0 && k < SIZE)
		{
            --b[x][k];
		}
        k = j + i - x;
        if (k >= 0 && k < SIZE)
		{
            --b[x][k];
		}
    }
    b[i][j] = 0;
}
 
void setQ(int b[][SIZE], int i, int j)
{
    for(int x = 0; x < SIZE; ++x)
        {
        ++b[x][j];
        ++b[i][x];
        int k;
        k = j - i + x;
        if (k >= 0 && k < SIZE)
		{
            ++b[x][k];
		}
        k = j + i - x;
        if (k >= 0 && k < SIZE)
		{
            ++b[x][k];
		}
    }
    b[i][j] = -1;
}
 
int tryQ(int b[][SIZE], int i)
{
    int result = 0;
    for (int j = 0; j < SIZE; ++j)
    {
        if (b[i][j] == 0)
        {
            setQ(b, i, j);
            if(i == 7)
			{
                result = 1;
			}
            else
            {
                if(!(result = tryQ(b, i + 1)))
                    resetQ(b, i, j);
            }
        }
    if(result)
        break;
    }
    return result;
 }
