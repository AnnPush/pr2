/*(Factorials) The factorial function is used frequently in probability problems. The factorial
of a positive integer n (written n! and pronounced “n factorial”) is equal to the product of the positive
integers from 1 to n. Write a program that evaluates the factorials of the integers from 1 to 5.
Print the results in tabular format. What difficulty might prevent you from calculating the factorial
of 20?*/
#include <stdio.h>


int main(void)
{
	int count = 0;
	int x, y;
	int factorial, f = 1;

	printf("%s", "Enter  integer in the range 1- 20: ");
	scanf("%d", &x);
	y = x;

	while(count < x)
	{
		factorial = y - count;
		f *= factorial;
		++count;
	}

	printf("Factorial = %d\n", f);
}
