/*(Largest and Smallest Integers) Write a program that reads in three integers and then determines
and prints the largest and the smallest integers in the group. Use only the programming techniques
you have learned in this chapter.*/

#include <stdio.h>

int main(void)
{
	int a, b, c, min, max;
	
	printf("Enter three digits:");
	scanf("%d%d%d", &a, &b, &c);

	if(a > b)
	{
		max = a;
		min = b;
		if(c > a)
		{
			max=c;
		}
		if(c < b)
		{
			min = c;
		}
	}
	if(a < b)
	{
		max = b;
		min = a;
		if(c > b)
		{
			max=c;
		}
		if(c < a)
		{
			min = c;
		}
	}
	printf("Max: %d\nMin: %d\n", max, min);
}
