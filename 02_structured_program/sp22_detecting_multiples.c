/*(Detecting Multiples of 10) Write a program that prints 100 asterisks, one at a time. After
every tenth asterisk, your program should print a newline character. [Hint: Count from 1 to 100.
Use the remainder operator to recognize each time the counter reaches a multiple of 10.]*/

#include <stdio.h>

int main(void)
{
	int counter = 1;
	int a;

	while(counter <= 100)
	{
	    printf("%s", "*");
		a = counter % 10;
		
		if(a == 0)
		{
			printf("%s", "\n");
		}
		++counter;
	}
}
