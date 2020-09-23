/*(Factorial) The factorial of a nonnegative integer n is written n! (pronounced “n factorial”)
and is defined as follows:
n! = n · (n - 1) · (n - 2) · … · 1 (for values of n greater than or equal to 1)
and
n! = 1 (for n = 0).
For example, 5! = 5 · 4 · 3 · 2 · 1, which is 120.
c) Write a program that computes the value of e
x by using the formula 

*/

#include <stdio.h>

int main(void)
{
	unsigned int number;
	unsigned int factorial = 1;
	int i = 1;
	float e = 1;
	int x = 2;
	int y = 1;

	puts("Enter nonnegative integer: ");
	scanf("%u", &number);

	if(number == 0)
	{
		factorial = 1;
	}
	
	else 
	{
	    while(i <= number)
	    {
		   factorial *= i;
		   y *= x;
		   e = e + y/(float)factorial;	  
		   i++;
	    }
	}
	printf("%.2f\n", e);
}
