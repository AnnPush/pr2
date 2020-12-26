#include <stdio.h>

void printArray(int a[], int size);
void quicksort(int a[], int start, int finish);

int main(void)
{
	int arr[] = {5, 87, 432, 3, 8, 45, 98756,321, 90, 789, 6};
	int sizes = sizeof(arr) / sizeof(int);
	puts("\nМассив до сортировки.");
	printArray(arr, sizes);
	quicksort(arr, 0, sizes - 1);
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
	int dividing(int a[], int beginning, int end);
	int element;
	if(start == finish)
		return;
	element = dividing(a, start, finish);
	if(element == start)
		quicksort(a, element + 1, finish);
	else if(element == finish)
		quicksort(a, start, element - 1);
	else
	{
		quicksort(a, element + 1, finish);
		quicksort(a, start, element - 1);
	}
}
int dividing(int a[], int beginning, int end)
{	
    void swap(int *ptr1, int *ptr2);
    int x = 0; int y = end;
	while(1)
	{
		for(;y > beginning; y--)
		{
			if(a[y] < a[beginning])
			{
				swap(&a[y], &a[beginning]);
			    beginning = y;
			    break;
			}
		}
		for(;x < beginning; x++)
		{
			if(a[x] > a[beginning])
			{
				swap(&a[x], &a[beginning]);
			    beginning = 1;
			    break;
			}
		}
		if(x == y)
			break;
	}
	return beginning;
}

void swap(int *ptr1, int *ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
