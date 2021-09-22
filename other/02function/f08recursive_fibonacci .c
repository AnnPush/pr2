/ Recursive fibonacci function
#include <stdio.h>

unsigned long long int fibonacci(unsigned int n);

int main(void)
{
	unsigned int number;
	unsigned long long int result;

	printf("%s", "Enter an integer: ");
	scanf("%u", &number);

	//calculate fibonacci value for number input by user
	result = fibonacci(number);

	//display result
	printf("Fibonacci(%u) = %llu\n", number, result);
}

// Recursive definition of function fibinscci
unsigned long long int fibonacci(unsigned int n)
{
	//base case
	if (0 == n || 1 == n)
	{
		return n;
	}
	else
	{
		return fibonacci(n -1 ) + fibonacci(n - 2);
	}
}
