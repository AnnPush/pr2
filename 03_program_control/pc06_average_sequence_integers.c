/*  (Average a Sequence of Integers) Write a program that calculates and prints the average of
several integers. Assume the last value read with scanf is the sentinel 9999. A typical input sequence
might be
10 8 11 7 9 9999
indicating that the average of all the values preceding 9999 is to be calculated.*/
#include <stdio.h>


int main(void)
{
	int x;
	float y;
	int count = 0;
	int sum = 0;
	
	puts("Enter the integer in the range 1- 20:");
	puts("Enter the 9999 to end input.");
	scanf("%d", &x);
	

	while( x != 9999)
	{
		sum += x;
        ++count;
		scanf("%d", &x);
	}

	y = (float)sum / count;
	  
		printf("%.2f\n", y);
}
