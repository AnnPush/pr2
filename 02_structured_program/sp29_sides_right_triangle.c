/*(Sides of a Right Triangle) Write a program that reads three nonzero integers and determines
and prints whether they could be the sides of a right triangle.
*/

#include <stdio.h>

int main(void)
{
	int a, b, c;
	int max;
	int x1, x2;

	puts("Enter three nonzero integers:");
	scanf("%d%d%d", &a, &b, &c);
	
	if(a > b)
	{
		max = a;
		x1 = b;
	}
	else
	{
		max = b;
		x1 = a;
	}
	if(c > max)
	{
		x2=max;
		max = c;
	}
	else
	{
		x2=c;
	}
	

	if(max * max == x1 * x1 + x2 * x2)
	{
		printf("%s", "Right Triangle\n");
	}
	else
	{
		printf("%s", "Not Right Triangle\n");
	}
}
