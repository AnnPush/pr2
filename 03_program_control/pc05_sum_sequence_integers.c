/*  (Sum a Sequence of Integers) Write a program that sums a sequence of integers. Assume that
the first integer read with scanf specifies the number of values remaining to be entered. Your program
should read only one value each time scanf is executed. A typical input sequence might be
5 100 200 300 400 500
where the 5 indicates that the subsequent five values are to be summed*/
#include <stdio.h>


int main(void)
{
	int x, y;
	int count = 1;
	int sum = 0;
	

	printf("%s", "Enter  integer in the range 1- 20: ");
	scanf("%d", &x);

	while( count <= x)
	{
		printf("%s", "Enter  integer: ");
	    scanf("%d", &y);

		sum += y;

		  ++count;
	}
	  
		printf("%d\n", sum);
}
