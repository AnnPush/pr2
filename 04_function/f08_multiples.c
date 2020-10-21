/*(Multiples) Write a function isMultiple that determines for a pair of integers whether the
second integer is a multiple of the first. The function should take two integer arguments and return
1 (true) if the second is a multiple of the first, and 0 (false) otherwise. Use this function in a program
that inputs a series of pairs of integers.*/

#include <stdio.h>

int isMultiple(int, int);

int main()
{
	int integer1, integer2;
	puts("Enter integer1(Enter: (-1))");
	scanf("%d", &integer1);
	
    while(integer1 != -1)
	{
	    puts("Enter integer2");
		scanf("%d", &integer2);
		
		if(isMultiple(integer1, integer2) == 1)
		{
			puts("Integer2 is a multiple of the integer1");
		}
		else
		{
			puts("Integer2 is not a multiple of the integer1");
		}
		
		puts("Enter integer1(Enter: (-1))");
	    scanf("%d", &integer1);
	}
}

int isMultiple(int i1, int i2)
{
	int b, z;
	
	z = (i2 % i1);

	if( z == 0)
	    return 1;
	else
	    return 0;
}
