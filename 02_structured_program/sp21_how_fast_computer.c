/*(How Fast Is Your Computer?) How can you determine how fast your own computer really
operates? Write a program with a while loop that counts from 1 to 1,000,000,000 by 1s. Every time
the count reaches a multiple of 100,000,000, print that number on the screen. Use your watch to
time how long each 100 million iterations of the loop takes.*/

#include <stdio.h>

int main(void)
{
	int counter = 0;
	int a;
	
	while(counter <= 1000000000)
	{
		counter++;
		a = counter % 100000000;
		if(a == 0)
		{
			printf("%d\n", counter);
		}
		
	}
}
