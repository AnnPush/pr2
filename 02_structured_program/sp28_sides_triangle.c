/*(Sides of a Triangle) Write a program that reads three nonzero integer values and determines
and prints whether they could represent the sides of a triangle.*/

#include <stdio.h>

int main(void)

{
	int a;
	int b;
	int c;
	int sum = 0;

	puts("Enter three nonzero integer:");
	scanf("%d%d%d", &a, &b, &c);
	
	

	sum = a + b;
	
	if(sum > c)
	{
		puts("Sides of a Triangle");
	}
	else
	{
		puts("Not triangle!");
	}
}
