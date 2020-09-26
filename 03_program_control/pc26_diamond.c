/*1 (Diamond-Printing Program) Write a program that prints the following diamond shape.
You may use printf statements that print either a single asterisk (*) or a single blank. Maximize
your use of iteration (with nested for statements) and minimize the number of printf statements
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    int n = 9;
    int m = (n-1)/2;
    
    for( int i = 0; i < n; i ++)
    {
        
        for( int j = 0; j < n; j ++)
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
