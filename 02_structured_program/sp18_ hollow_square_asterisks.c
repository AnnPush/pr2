/*(Hollow Square of Asterisks) Modify the program you wrote in Exercise 3.32 so that it
prints a hollow square. For example, if your program reads a size of 5, it should print

*****
* *
* *
* *
*****
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
			if(c == 1 || c == a || b == 1 || b == a)
			{
	            printf("%s", "*");
			}
			else
			{
				printf("%s", " ");
			}
			c++;
		}
		c = 1;
		puts("");
	  b++;
	}
}
