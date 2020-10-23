/*(Fibonacci) The Fibonacci series
0, 1, 1, 2, 3, 5, 8, 13, 21, …
begins with the terms 0 and 1 and has the property that each succeeding term is the sum of the two
preceding terms. a) Write a nonrecursive function fibonacci(n) that calculates the nth Fibonacci
number.*/

#include <stdio.h>

int fibonacci(int);

int main()
{
	int n = 5;

	printf("Fibonacci: (%d) = %d\n", n, fibonacci(n));
}

int fibonacci(int index)
{
	int digit1 = 0;
	int digit2 = 1;
	int i;

	for(i = 3; i <= index; ++i)
	{
		digit2 = digit1 + digit2;
		digit1 = digit2 - digit1;
	}
		return digit2;
}
