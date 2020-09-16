/*(Odd or Even) Write a program that reads an integer and determines and prints whether
it’s odd or even. [Hint: Use the remainder operator. An even number is a multiple of two. Any multiple
of two leaves a remainder of zero when divided by 2.*/

#include <stdio.h>

int main(void)
{
	int a, b;
	
	scanf("%d", &a);

	b = a % 2;

	if(b == 0)
	{
		printf("Inteder a = %d is even.\n", a);
	}
	else
	{
		printf("Inteder a = %d is odd.\n", a);
	}
}
