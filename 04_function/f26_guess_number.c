/*(Guess the Number) Write a C program that plays the game of “guess the number” as follows:
Your program chooses the number to be guessed by selecting an integer at random in the range
1 to 1000. The program then types:
I have a number between 1 and 1000.
Can you guess my number?
Please type your first guess.
The player then types a first guess. The program responds with one of the following:
1. Excellent! You guessed the number!
 Would you like to play again (y or n)?
2. Too low. Try again.
3. Too high. Try again.
If the player’s guess is incorrect, your program should loop until the player finally gets the number
right. Your program should keep telling the player Too high or Too low to help the player “zero in”
on the correct answer. [Note: The searching technique employed in this problem is called binary
search. We’ll say more about this in the next problem.]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int f(int, int);

int main()
{
	int n = 1;
	int x;
	int a;

	srand(time(NULL));

	while(n == 1)
	{
		x = 1 + rand() % 1000;

		printf("%s\n", "I have a number between 1 and 1000. Can you guess my number? Please type your first guess.");
		scanf("%d", &a);

		n = f(x, a);
	}
}
int f(int x1, int a1)
{
	int t, flag;
	while(x1 != a1)
	{
		if(a1 < x1)
			{
				printf("%s\n", "Too low.");
				printf("%s\n", "Please try again.");
				scanf("%d", &t);
				a1 = t;
			}
			else if(a1 > x1)
			{
				printf("%s\n", "Too high.");
				printf("%s\n", "Please try again.");
				scanf("%d", &t);
				a1 = t;
			}

	}
	
				printf("%s\n", "Very good! Continue: 1, Exit: 0");
				scanf("%d", &flag);
				return flag;
				
}
