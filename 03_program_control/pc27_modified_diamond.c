/*(Modified Diamond-Printing Program) Modify the program you wrote in Exercise 4.31 to
read an odd number in the range 1 to 19 to specify the number of rows in the diamond. Your program
should then display a diamond of the appropriate size.*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
	int i, j;
    int m;

	puts("Enter odd number:\n");
	scanf("%d", &n);

	m = (n-1)/2;
    
    for( i = 0; i < n; i ++)
    {
        
        for(  j = 0; j < n; j ++)
        {
            if((abs(j - m) + abs(i - m)) <= m)
            {
               printf("%s", "*"); 
            }
            else
            {
            printf("%s", " ");
            }
            
        }
        printf("%s", "\n");
    }
}
