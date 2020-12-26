#include <stdio.h>

void printArray(int a[], int size);
void quicksort(int a[], int start, int finish);
int dividing(int a[], int st, int fin);
void swap(int *ptr1, int *ptr2);
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
	
	int element;
	if(start == finish)
		return;
	element = dividing(a, start, finish);
	printf("%d\n", element);
	printArray(a, 11);
	if(element == start)
	{puts("\nМассивd");
		quicksort(a, element + 1, finish);
	}
	else if(element == finish)
	{puts("\nМассивdd");
		quicksort(a, start, element - 1);
	}
	else
	{puts("\nМассивddd");
		quicksort(a, element + 1, finish);
		printArray(a, 11);
		quicksort(a, start, element - 1);
		printArray(a, 11);
	}
	
}
int dividing(int a[], int st, int fin)
{	
    
    int x = 0;
    int y = fin;
	while(1)
	{
		for(;y > st; y--)
		{
			if(a[y] < a[st])
			{
				swap(&a[y], &a[st]);
			    st = y;
				puts("\nМассив1");
			    break;
			}
		}
		for(;x < st; x++)
		{
			if(a[x] > a[st])
			{
				swap(&a[x], &a[st]);
			    st = 1;
				puts("\nМассив2");
			    break;
			}
		}
		if(x == y)
			break;
	}
	return st;
}

void swap(int *ptr1, int *ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
