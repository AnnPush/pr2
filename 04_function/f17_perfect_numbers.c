/*(Perfect Numbers) An integer number is said to be a perfect number if its factors, including
1 (but not the number itself), sum to the number. For example, 6 is a perfect number because 6 =
1 + 2 + 3. Write a function isPerfect that determines whether parameter number is a perfect number.
Use this function in a program that determines and prints all the perfect numbers between 1
and 1000. Print the factors of each perfect number to confirm that the number is indeed perfect.
Challenge the power of your computer by testing numbers much larger than 1000.*/

#include <stdio.h>
int isPerfect(int);

int main()
{
	for(int i = 1; i <= 10000; i++)
	{
		if(isPerfect(i) == 1)
		{
			printf("%d factors: ", i);
			for(int j = 1; j <= i; j++)
			{
				if(i%j == 0 && i != j)
					printf("%d ", j);
			}
			printf("%s", "\n");
		}
	}
}

int isPerfect(int a)
{
    	int sum = 0;
		for( int j = 1; j < a; j++)
		{
			if(a%j == 0)
			sum += j;
		}
		if( sum == a)
			return 1;
		else
			return 0;
}
