/*(De Morgan’s Laws) In this chapter, we discussed the logical operators &&, ||, and !. De
Morgan’s Laws can sometimes make it more convenient for us to express a logical expression. These
laws state that the expression !(condition1 && condition2) is logically equivalent to the expression
(!condition1 || !condition2). Also, the expression !(condition1 || condition2) is logically equivalent
to the expression (!condition1 && !condition2). Use De Morgan’s Laws to write equivalent expressions
for each of the following, and then write a program to show that both the original expression
and the new expression in each case are equivalent.
a) !(x < 5) && !(y >= 7)
b) !(a == b) || !(g != 5)
c) !((x <= 8) && (y > 4))
d) !((i > 4) || (j <= 6))
*/

#include <stdio.h>

int main(void)
{
	int x = 6;
	int y = 5;

	int a = 5;
	int b = 6;
	int g = 5;

	int i = 3;
	int j =6;

	if(!(x < 5) && !(y >= 7))
	{
		printf("%s", "A1. True\n");
	}
	else
	{
		printf("%s", "A1. False\n");
	}

	if(!(x < 5  || y >= 7))
	{
		printf("%s", "A2. True\n");
	}
	else
	{
		printf("%s", "A2. False\n");
	}

	puts("________________");

	if(!(a == b) || !(g != 5))
	{
		printf("%s", "B1. True\n");
	}
	else
	{
		printf("%s", "B1. False\n");
	}
	if(!(a == b && g != 5))
	{
		printf("%s", "B1. True\n");
	}
	else
	{
		printf("%s", "B1. False\n");
	}

	puts("________________");

	if(!(x <= 8 && y > 4))
	{
		printf("%s", "C1. True\n");
	}
	else
	{
		printf("%s", "C1. False\n");
	}

	if(!(x <= 8) || !(y > 4))
	{
		printf("%s", "C1. True\n");
	}
	else
	{
		printf("%s", "C1. False\n");
	}

	puts("________________");

	if(!(i > 4 || j <= 6))
	{
		printf("%s", "D1. True\n");
	}
	else
	{
		printf("%s", "D1. False\n");
	}

	if(!(i > 4) && !(j <= 6))
	{
		printf("%s", "D1. True\n");
	}
	else
	{
		printf("%s", "D1. False\n");
	}
}
