#include <stdio.h>

void printArray(int a[], int size);
void quicksort(int a[], int start, int finish);
int main(void)
{
	int arr[] = {37, 2, 6, 4, 89, 8, 10, 12, 68, 45};
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
    int partition(int a[], int st, int fin);
	int element; 
	
	if(start == finish)
		return;
	
	element = partition(a, start, finish);
	
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
int partition(int a[], int st, int fin)
{	
   void swap(int *ptr1, int *ptr2); 
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
			    break;
			}
		}
		for(;x < st; x++)
		{
			if(a[x] > a[st])
			{
				swap(&a[x], &a[st]);
			    st = x;
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
