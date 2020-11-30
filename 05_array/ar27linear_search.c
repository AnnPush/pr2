#include <stdio.h>
#define SIZE 10

int linearSearch(const int array[], int key, int size, int i);

int main(void)
{
    int a[SIZE];
    int x;
    int searchKey;
    int element;

    for(x = 0; x < SIZE; ++x)
    {
	    a[x] = 2 * x;
	    printf("%5d", a[x]);
    }
    
    puts("");
    
	printf("Enter integer search key:\n");
	scanf("%d", &searchKey);
	
	element = linearSearch(a, searchKey, SIZE, 0);
	
	if(element != -1)
	{
		printf("Found value in element %d\n", element);
	}
	else{
		printf("Value not found\n");
	}
}

int linearSearch(const int array[], int key, int size, int i)
{
    if(i < size)
    {
	    if(array[i] == key)
	    {
		    return i;
	    }
	    else
	    {
		    return linearSearch(array, key, size, i + 1);
	    }
    }
	return -1;
}
