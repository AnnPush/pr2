/*(Recursive Exponentiation) Write a recursive function power(base, exponent) that when
invoked returns
baseexponent
For example, power(3, 4) = 3 * 3 * 3 * 3. Assume that exponent is an integer greater than or equal
to 1. Hint: The recursion step would use the relationship
baseexponent = base * baseexponent–1
and the terminating condition occurs when exponent is equal to 1 because
base1 = base*/

#include <stdio.h>

int power(int, int);

int main()
{
	int base, exponent;

	printf("%s", "Enter base:");
	scanf("%d", &base);

	printf("%s", "Enter exponent:");
	scanf("%d", &exponent);

	if(exponent <= 0)
	{
		printf("%s", "Error!");
	}
	else
	{
		printf("Result: %d\n", power(base, exponent));
	}
}

int power(int b, int e)
{
	if( e == 1)
		return b;
	else
		return b *power(b, e - 1);
}
