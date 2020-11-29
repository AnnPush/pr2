#include <stdio.h>
#define SIZE 10

void selectSort(int a[], int size, int k);
void printArray(int a[]);

int main(void)
{
	int array[SIZE] = {23, 6, 87, 1, 567, 43, 98, 45, 7, 78};

	printArray(array);
	puts("");
	selectSort(array, SIZE, 0);
    printArray(array);
}

void printArray(int a[])
{
   for(int i = 0; i < SIZE; ++i)
	{
		printf("%5d", a[i]);
	} 
}

void selectSort(int a[], int size, int k)
{
    	int min;
    	
    	if(k < size)
	    {
	        min = a[k];
	    
	        for(int j = k; j < SIZE; ++j)
	        {
		        if(a[j] < min)
		    	min = a[j];
	        }
	
	        for(int j = k; j < SIZE; ++j)
	        {
	            if(min == a[j])
	            {
	                a[j] = a[k];
	                a[k] = min;
	            }
	        }
			selectSort(a, size, k + 1);
    	}
	
}


