/*(Square of Asterisks) Write a program that reads in the side of a square and then prints that
square out of asterisks. Your program should work for squares of all side sizes between 1 and 20. For
example, if your program reads a size of 4, it should print

****
****
****
****
*/

#include <stdio.h>

int main(void)
{
	unsigned int a;
	unsigned int b = 1;
	unsigned int c = 1;

	printf("%s", "Enter a(1-20):");
	scanf("%d", &a);

	while( b <= a)
	{
		while( c <= a)
		{
	        printf("%s", "*");
			c++;
		}
		c = 1;
		puts("");
	  b++;
	}
}
