/*(Multiples) Write a program that reads in two integers and determines and prints whether
the first is a multiple of the second. [Hint: Use the remainder operator.]*/

#include <stdio.h>

int main(void)
{
	int a, b;

	printf("Enter two integers:\n");

	scanf("%d%d", &a, &b);

	if(a%b == 0)
	{
		printf("\" %d \"is a multiple \" %d \"\n", a, b);
	}
	else
	{
		printf("\" %d \"is a not multiple \" %d \"\n", a, b);
	}
}
