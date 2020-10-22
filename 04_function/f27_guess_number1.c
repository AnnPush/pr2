/*(Guess the Number Modification) Modify the program of Exercise 5.32 to count the number
of guesses the player makes. If the number is 10 or fewer, print Either you know the secret or
you got lucky! If the player guesses the number in 10 tries, then print Ahah! You know the secret!
If the player makes more than 10 guesses, then print You should be able to do better! Why should
it take no more than 10 guesses? Well, with each “good guess” the player should be able to eliminate
half of the numbers. Now show why any number 1 to 1000 can be guessed in 10 or fewer tries.*/

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
	int count = 0;
	int t, flag;
	while(x1 != a1)
	{
		if(a1 < x1)
			{
				printf("%s\n", "Too low.");
				printf("%s\n", "Please try again.");
				scanf("%d", &t);
				a1 = t;
				count++;
			}
			else if(a1 > x1)
			{
				printf("%s\n", "Too high.");
				printf("%s\n", "Please try again.");
				scanf("%d", &t);
				a1 = t;
				count++;
			}

	}
	            if(count < 10)
				{
					printf(" Either you know the secret or you got lucky!");
				}
				else if(count == 10)
				{
					printf(" Ahah! You know the secret!");
				}
				else
				{
					printf("  You should be able to do better! ");
				}

				printf("\n%s\n", "Very good! Continue: 1, Exit: 0");
				scanf("%d", &flag);
				return flag;
				
}
