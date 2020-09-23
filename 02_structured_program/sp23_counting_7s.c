/*(Counting 7s) Write a program that reads an integer (5 digits or fewer) and determines and
prints how many digits in the integer are 7s.*/

#include <stdio.h>

int main(void)
{
    int number;
    int i = 1;
    int next = 1;
    int a;
    int m;
    int x = 0;
    int counter = 0;
    
    printf("%s\n", "Enter number:");
	scanf("%d", &number);


    while(next != number)
    {
        m = i * 10;
        next = number % m;
       
        a = (next - x) / i;

        if(a == 7)
        {
        	++counter;
        }
        x = next;
        i *= 10;
    }
    printf("\'7\' = %d\n", counter);
}
