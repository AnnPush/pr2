/*(Coin Tossing) Write a program that simulates coin tossing. For each toss of the coin the
program should print Heads or Tails. Let the program toss the coin 100 times, and count the number
of times each side of the coin appears. Print the results. The program should call a separate function
flip that takes no arguments and returns 0 for tails and 1 for heads. [Note: If the program
realistically simulates the coin tossing, then each side of the coin should appear approximately half
the time for a total of approximately 50 heads and 50 tails.]*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip(void);

int main(void)
{
	int heads = 0;
	int tails = 0;
		
	srand(time(NULL));

	for(int i = 1; i <= 100; i++)
	{
	    
		if(flip() == 0)
		{
			printf("%s\n", "Heads");
			heads++;
		}
		else 
		{
			printf("%s\n", "Tails");
			tails++;
		}
	}
	printf("\nHeads: %d\nTails: %d\n ", heads, tails);
}

int flip(void)
{
	int number = rand();

	if(number % 2 == 0)
		return 0;
	else
		return 1;
}
