/*  Print the integers from 1 to 20 using a while loop and the counter variable x. Print only
five integers per line. [Hint: Use the calculation x % 5. When the value of this is 0, print
a newline character, otherwise print a tab character.]*/
#include <stdio.h>
#include <math.h>

int main(void)
{
	int x = 1;

	while(x <= 20)
	{
		printf("%d\n", x);
	    if(x % 5)
	    {
		   puts("");
	    }
	    else
	    {
		   printf("%s", "\t");
	    }
	    x++;
	}
}
