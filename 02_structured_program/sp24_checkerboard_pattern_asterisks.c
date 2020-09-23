/*(Checkerboard Pattern of Asterisks) Write a program that displays the following checkerboard
pattern:

* * * * * * * *
 * * * * * * * *
* * * * * * * *
 * * * * * * * *
* * * * * * * *
 * * * * * * * *
* * * * * * * *
 * * * * * * * *

 Your program must use only three output statements, one of each of the following forms:
printf( "%s", "* " );
printf( "%s", " " );
puts( "" ); 
 */

#include <stdio.h>

int main(void)
{
	int counter = 1;
	int counter1 = 0;

	while(counter <= 64)
	{
		printf("%s", "* ");
		if(counter % 8 == 0)
		{
			puts("");
			if(counter1 % 2 == 0)
			{
			   printf("%s", " ");
			}
			++counter1;
		}
		++counter;
	}
}
