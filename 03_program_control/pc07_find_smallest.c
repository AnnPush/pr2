/* (Find the Smallest) Write a program that finds the smallest of several integers. Assume that
the first value read specifies the number of values remaining.*/
#include <stdio.h>


int main(void)
{
	int x, y, min = 0;
	int count = 1;
	int sum = 0;
	

	printf("%s", "Enter  integer in the range 1- 20: ");
	scanf("%d", &x);

	printf("%s", "Enter  integer: ");
	scanf("%d", &y);
	
	min = y;

	while( count < x)
	{
		printf("%s", "Enter  integer: ");
	    scanf("%d", &y);
	
		if(min > y)
		{
		   min = y;
		}
	    ++count;
	}
		printf("%d\n", min);
}
