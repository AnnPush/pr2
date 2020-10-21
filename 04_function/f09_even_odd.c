/*(Even or Odd) Write a program that inputs a series of integers and passes them one at a time
to function isEven, which uses the remainder operator to determine whether an integer is even. The
function should take an integer argument and return 1 if the integer is even and 0 otherwise. */

#include <stdio.h>

int isEven(int);

int main()
{
	int number;

	puts("Enter number:(Exit: 0)");
	scanf("%d", &number);

	while (number != 0)
	{
		if(isEven(number) == 1)
		{
			puts("Even");
		}
		else
		{
                        puts("Odd");
		}
		puts("Enter number:(Exit: 0)");
	        scanf("%d", &number);
	}
}

int isEven(int n)
{
	int t;
	float z;
	z = n % 2;

	if(z == 0)
	{
		t = 1;
	}
	else
	{
		t = 0;
	}
	return t;
}
