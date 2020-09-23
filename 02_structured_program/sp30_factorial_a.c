/*(Factorial) The factorial of a nonnegative integer n is written n! (pronounced “n factorial”)
and is defined as follows:
n! = n · (n - 1) · (n - 2) · … · 1 (for values of n greater than or equal to 1)
and
n! = 1 (for n = 0).
For example, 5! = 5 · 4 · 3 · 2 · 1, which is 120.
a) Write a program that reads a nonnegative integer and computes and prints its factorial.

*/

#include <stdio.h>

int main(void)
{
	unsigned int number;
	unsigned int factorial = 1;
	int i = 1;
	int t = 1;
	int n;

	puts("Enter nonnegative integer: ");
	scanf("%u", &number);

	n = number;

	if(number == 0)
	{
		factorial = 1;
	}
	
	else 
	{
	    while(i <= number)
	    {
		   factorial *= n;
		   n -= 1;
		   i++;
	    }
	}
	printf("%d\n", factorial);
