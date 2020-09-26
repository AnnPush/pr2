/*(Replacing switch with if…else) Rewrite the program of Fig. 4.7 by replacing the switch
statement with a nested if…else statement; be careful to deal with the default case properly. Then
rewrite this new version by replacing the nested if…else statement with a series of if statements;
here, too, be careful to deal with the default case properly (this is more difficult than in the nested
if…else version). This exercise demonstrates that switch is a convenience and that any switch
statement can be written with only single-selection statements. 
*/

#include <stdio.h>

int main(void)
{
    int grade;
    int aCount = 0;
    int bCount = 0;
    int cCount = 0;
    int dCount = 0;
    int fCount = 0;
    
    printf( "Enter the letter grades. \n" );
    printf( "Enter the EOF character to end input. \n" );
    
     while ((grade = getchar()) != EOF)
    {
    if (grade == 'A' || grade == 'a')
    {
        ++aCount;
       continue;
    }
    if (grade == 'B' || grade == 'b')
    {
        ++bCount;
       
    }
    if (grade == 'C' || grade == 'c')
    {
        ++cCount;
        
    }
    if (grade == 'D' || grade == 'd')
    {
        ++dCount;
       
    }
   if (grade == 'F' || grade == 'f')
    {
        ++fCount;
       
    }
    if(grade != '\n')
      printf("Incorrect letter grade entered.Enter a new grade.\n");
          
    }       
           
    printf("\nTotals for each letter grade are:\n");
    printf("A: %d\n", aCount);
    printf("B: %d\n", bCount);
    printf("C: %d\n", cCount);
    printf("D: %d\n", dCount);
    printf("F: %d\n", fCount);
    
    
}
