#include <stdio.h>
#define SIZE 5

void printArray(int a[], int size, int i);

int main(void)
{
	int array[SIZE] = {1, 7, 45, 34, 2};
	printArray(array, SIZE, 0);
}

void printArray(int a[], int size, int i)
{
	if(i < size)
	{
	    printf("%5d", a[i]);
		printArray(a, size, i + 1);
		
	}
}

