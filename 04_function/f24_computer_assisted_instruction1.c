/*(Computer-Assisted Instruction: Reducing Student Fatigue) One problem in CAI environments
is student fatigue. This can be reduced by varying the computer’s responses to hold the student’s
attention. Modify the program of Exercise 5.50 so that various comments are displayed for
each answer as follows:
Possible responses to a correct answer:
Very good!
Excellent!
Nice work!
Keep up the good work!
Possible responses to an incorrect answer:
No. Please try again.
Wrong. Try once more.
Don't give up!
No. Keep trying.
Use random-number generation to choose a number from 1 to 4 that will be used to select
one of the four appropriate responses to each correct or incorrect answer. Use a switch statement to
issue the responses. */

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tabl(int, int, int);

int main(void)
{
	int a, b, c;

	srand(time(NULL));

	a = 1 + rand() % 9;
	b = 1 + rand() % 9;

	printf("How much is %d times %d\n", a, b);
	scanf("%d", &c);

	while(tabl(a, b, c) != 1)
	{
		printf("\nHow much is %d times %d\n", a, b);
	    scanf("%d", &c);
	}
}

int tabl(int x, int y, int z)
{
	int t;

	if(x * y == z)
	{
		t = 1 + rand() % 4;

		switch(t)
		{
		   case 1:
			   puts("Very good!");
			break;
		   case 2:
			   puts("Excellent!");
			break;
           case 3:
			   puts("Nice work!");
			break;
		   case 4:
			   puts("Keep up the good work!");
			break;
		}

		return 1;
	}
	else
	{
		t = 1 + rand() % 4;

		switch(t)
		{
		   case 1:
			  puts("No. Please try again.");
			break;
		   case 2:
			   puts("Wrong. Try once more.");
			break;
           case 3:
			   puts("Don't give up!");
			break;
		   case 4:
			   puts("No. Keep trying.");
			break;
		}
		
		return 0;
	}
}
