#include <stdio.h>
#define SIZE 10

int minArray(int a[], int size, int min, int i);

int main(void)
{
	int array1[SIZE] = {56, 8, 63, 234, 8, 5, 87, 6, 95, 65};
	
	printf("Min: %d\n", minArray(array1, SIZE, array1[0], 0));	
}

int minArray( int a[], int size, int min, int i )
{
    if( i < size)
    {
        if( a[ i ] < min )
            min = a[ i ];
        i++;
        return minArray( a, size, min, i);
    }
    else
        return min;
}

