/*(Calculating the Compound Interest with Integers) Modify the program of Fig. 4.6 so that
it uses only integers to calculate the compound interest. [Hint: Treat all monetary amounts as integral
numbers of pennies. Then “break” the result into its dollar portion and cents portion by using
the division and remainder operations, respectively. Insert a period.]
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
  unsigned int principal = 100000;
   unsigned int rate = 105;
   unsigned int amount = 1;
   unsigned int n = 1;
   unsigned int year;
   unsigned int a = 1;
   unsigned int t;

   printf("%4s%21s\n", "Year", "Amount on deposit");

   for( year = 1; year <= 10; ++year)
   {
	  n = 1;
      amount = 1 * principal;

	  while(n <= year)
	  {
	     amount *= rate;
		  while ( amount >= 9999999 )
         {
            amount /= 10;
         }
		 ++n;
	  }
	 if(amount < 10000)
	 {
		 a = amount % 10 * 10;
		 amount /= 10;
		 printf("%4u%21u.%u\n", year, amount, a);
	 } 
	 else
	 {
		 t = amount % 1000 %10;
		 if(t > 4)
		 {
		    a = (amount % 1000 - amount % 1000 %10 ) / 10 +1;
		 }
		 else
		 {
			 a = (amount % 1000 - amount % 1000 %10)/ 10;
		 }
		 amount /= 1000;
		 printf("%4u%21u.%u\n", year, amount, a);
	 }
	  
	  
   }
}
