/*(Table of Squares and Cubes) Using only the techniques you learned in this chapter, write
a program that calculates the squares and cubes of the numbers from 0 to 10 and uses tabs to print
the following table of values:*/

#include <stdio.h>

int main(void)
{
	int x = 0;

	printf("number\t\tsquare\t\tcube\n");
	printf("%d\t\t%d\t\t%d\n", x, x * x, x * x * x);
	x = x + 1;
	printf("%d\t\t%d\t\t%d\n", x, x * x, x * x * x);
	x = x + 1;
	printf("%d\t\t%d\t\t%d\n", x, x * x, x * x * x);
	x = x + 1;
	printf("%d\t\t%d\t\t%d\n", x, x * x, x * x * x);
	x = x + 1;
	printf("%d\t\t%d\t\t%d\n", x, x * x, x * x * x);
	x = x + 1;
	printf("%d\t\t%d\t\t%d\n", x, x * x, x * x * x);
	x = x + 1;
	printf("%d\t\t%d\t\t%d\n", x, x * x, x * x * x);
	x = x + 1;
	printf("%d\t\t%d\t\t%d\n", x, x * x, x * x * x);
	x = x + 1;
	printf("%d\t\t%d\t\t%d\n", x, x * x, x * x * x);
	x = x + 1;
	printf("%d\t\t%d\t\t%d\n", x, x * x, x * x * x);
	x = x + 1;
	printf("%d\t\t%d\t\t%d\n", x, x * x, x * x * x);
}
