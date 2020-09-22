/*(Find the Two Largest Numbers) Using an approach similar to Exercise 3.23, find the two
largest values of the 10 numbers. [Note: You may input each number only once.]
*/

#include <stdio.h>

int main(void)
{
	int counter = 1;
	int number;
	int largest1 = 0;
	int largest2 = 0;


	while( counter <= 10)
	{
	   printf("Enter digit:\n");
	   scanf("%d", &number);

	   
	   if(number >= largest2)
	   {
		   largest1 = largest2;
		   largest2 = number;
		   
	   }
	   else if(number > largest1)
	   {
		   largest1 = number;
	   }	  
	    counter++;
	}
	printf("largest1 = %d\n", largest1);
	printf("largest2 = %d\n", largest2);
}
		
