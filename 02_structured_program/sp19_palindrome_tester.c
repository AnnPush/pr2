/*(Palindrome Tester) A palindrome is a number or a text phrase that reads the same backward
as forward. For example, each of the following five-digit integers is a palindrome: 12321,
55555, 45554 and 11611. Write a program that reads in a five-digit integer and determines whether
or not it’s a palindrome. [Hint: Use the division and remainder operators to separate the number
into its individual digits.]*/

#include <stdio.h>


int main(void)
{
	int a;
	int b;
	int c;

	printf("%s", "Enter digit:");
	scanf("%d", &a);

	b = a / 10000;
	c = a % 10;
	if(b == c)
	{
		b = a - b * 10000;
		b = b / 1000;

		c = a / 10;
		c = c % 10;
		if(b == c)
	    {
			puts("Palindrome");
		}
		else
		{
            puts("Not palindrome");
		}
	}
	else
	{
		puts("Not palindrome");
	}

}
