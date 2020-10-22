/*(Computer-Assisted Instruction: Monitoring Student Performance) More sophisticated
computer-assisted instruction systems monitor the student’s performance over a period of time. The
decision to begin a new topic is often based on the student’s success with previous topics. Modify
the program of Exercise 5.51 to count the number of correct and incorrect responses typed by the
student. After the student types 10 answers, your program should calculate the percentage that are
correct. If the percentage is lower than 75%, display "Please ask your teacher for extra help.",
then reset the program so another student can try it. If the percentage is 75% or higher, display
"Congratulations, you are ready to go to the next level!", then reset the program so another
student can try it.*/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tabl(int, int, int);

int main(void)
{
	int a, b, c;
	int count = 0;
	int counter = 1;

	srand(time(NULL));

	a = 1 + rand() % 9;
	b = 1 + rand() % 9;

	printf("How much is %d times %d\n", a, b);
	scanf("%d", &c);

	while(counter < 10)
	{
		 counter++;
	   if(tabl(a, b, c) != 1)
	   {
		   printf("\nHow much is %d times %d\n", a, b);
	       scanf("%d", &c);
		   count++;
	   }

	   else
	   {
		a = 1 + rand() % 9;
	    b = 1 + rand() % 9;

	    printf("\nHow much is %d times %d\n", a, b);
	    scanf("%d", &c);
	   }
	}
	
	if(count*10 >= 75)
		printf("\nPlease ask your teacher for extra help!");
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
