/* (Calculating the Sum of Even Integers) Write a program that calculates and prints the sum
of the even integers from 2 to 30.*/
#include <stdio.h>


int main(void)
{
	int count;
	int sum = 0;

	for(count = 2; count <= 30; count += 2)
	{
		sum += count;
	}
	printf("Sum = %d\n", sum);
}
