#include <stdio.h>

void printArray(int a[], int size);
void quicksort(int a[], int start, int finish);

int main(void)
{
	int arr[] = {5, 87, 432, 3, 8, 45, 98756,321, 90, 789, 6};
	int sizes = sizeof(arr) / sizeof(int);
	puts("\nМассив до сортировки.");
	printArray(arr, sizes);
	
	puts("\n\nМассив после сортировки.");
	printArray(arr, sizes);
}

void printArray(int a[], int size)
{
	puts("");
	for(int i = 0; i < size; ++i)
	{
		printf("%8d", a[i]);
	}
}

void quicksort(int a[], int start, int finish)
{
	int dividing(int a[], int x, int y);
	
	if(start == finish)
		return;
}
int dividing(int a[], int x, int y)
{	
	while(1)
	{
		for(;y > x; y--)
		{
			if(a[y] < a[x])
			{
				swap(&a[y], &a[x]);
			    x = y;
			    break;
			}
		}
		for(;x > y; x++)
		{
			if(a[y] < a[x])
			{
				swap(&a[x], &a[x]);
			    x = y;
			    break;
			}
		}
	}
}
