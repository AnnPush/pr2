/*(Bar-Chart Printing Program) One interesting application of computers is drawing graphs
and bar charts. Write a program that reads five numbers (each between 1 and 30). For each number
read, your program should print a line containing that number of adjacent asterisks. For example,
if your program reads the number seven, it should print ********/

#include <stdio.h>

int main(void)
{
   int x, j, i;
   
       
    for(j = 1; j <= 5; )
    {
       printf("%s", "Enter digit 1 to 30: ");
       scanf("%d", &x);
    
       if(x >= 1 && x <= 30)
       {
          for(i = 1; i <= x; i++)
          {
              printf("%s", "*");
          }
       }
       else
       {
           printf("%s", "Error! \n");
           continue;
       }
       printf("%s", "\n");
       j++;
    }
}
