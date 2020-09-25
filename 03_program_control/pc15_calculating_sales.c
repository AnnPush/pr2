/*(Calculating Sales) An online retailer sells five different products whose retail prices are
shown in the following table:
Product number Retail price
1 $ 2.98
2 $ 4.50
3 $ 9.98
4 $ 4.49
5 $ 6.87
Write a program that reads a series of pairs of numbers as follows:
a) Product number
b) Quantity sold for one day
Your program should use a switch statement to help determine the retail price for each product.
Your program should calculate and display the total retail value of all products sold last week.
*/

#include <stdio.h>

int main(void)
{
   int x;
   int y;
   double sum1 =0;
   double sum2 =0;
   double sum3 =0;
   double sum4 =0;
   double sum5 =0;
   
   for(int i= 1; i <= 5; i++)
   {
   printf("%s", "Enter number: ");
   scanf("%d", &x);
   printf("%s", "Enter count: ");
   scanf("%d", &y);
   
   switch(x){
       
       case 1:
          sum1 += y * 2.98;
          break;
       
       case 2:
          sum2 += y * 4.50;
          break;
       
       case 3:
          sum3 += y * 9.98;
          break;
       
       case 4:
          sum4 += y * 4.49;
          break;
       
       case 5:
          sum5 += y * 6.87;
          break;
   }
   }
   
   printf("%10.2f%10.2f%10.2f%10.2f%10.2f", sum1, sum2, sum3, sum4, sum5);
   
   printf("\n\nSum: %.2f", sum1 + sum2 + sum3 + sum4 + sum5);
}
