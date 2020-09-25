/* (Calculating the Product of Odd Integers) Write a program that calculates and prints the
product of the odd integers from 1 to 15.*/
#include <stdio.h>


int main(void)
{
	int count;
	int pr = 1;

	for(count = 1; count <= 15; count += 2)
	{
		pr *= count;
	}
	printf("Pr = %d\n", pr);
}
