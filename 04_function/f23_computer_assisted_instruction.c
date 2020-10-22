*(Computer-Assisted Instruction) The use of computers in education is referred to as computer-assisted
instruction (CAI). Write a program that will help an elementary school student learn
multiplication. Use the rand function to produce two positive one-digit integers. The program
should then prompt the user with a question, such as
How much is 6 times 7?
The student then inputs the answer. Next, the program checks the student’s answer. If it’s correct,
display the message "Very good!" and ask another multiplication question. If the answer is wrong,
display the message "No. Please try again." and let the student try the same question repeatedly
until the student finally gets it right. A separate function should be used to generate each new question.
This function should be called once when the application begins execution and each time the
user answers the question correctly*/

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
	if(x * y == z)
	{
		puts("Very good!");
		return 1;
	}
	else
	{
		puts("No. Please try again.");
		return 0;
	}
}
