/*(Triangle-Printing Program) Write a program that prints the following patterns separately,
one below the other. Use for loops to generate the patterns. All asterisks (*) should be printed by
a single printf statement of the form printf("%s", "*"); (this causes the asterisks to print side by
side). [Hint: The last two patterns require that each line begin with an appropriate number of
blanks.]*/

#include <stdio.h>

int main(void)
{
   int i, j, k = 1;
   
  

   for( i = 1; i <= 10; ++i)
   {
	  j = 1;

      while(j <= i)
	  {
		  printf("%s", "*");
		  ++j;
	  }
	  puts("");
   }

    puts("");

   for( i = 10; i >= 1; --i)
   {
	  j = 1;

      while(j <= i)
	  {
		  printf("%s", "*");
		  ++j;
	  }
	  puts("");
   }

   puts("");

   for( i = 10; i >= 1; --i)
   {
	  j = 1;
	  k = 1;

      while(k <= 10 - i )
	  {
		  printf("%s", " ");
	      ++k;
	  }

      while(j <= i)
	  {	  
		  printf("%s", "*");
		  ++j;
	  }
	  puts("");
   }

   puts("");

   for( i = 1; i <= 10; ++i)
   {
	  j = 1;
	  k = 1;

	  while(k <= 10 - i )
	  {
		  printf("%s", " ");
	      ++k;
	  }


      while(j <= i)
	  {
		  printf("%s", "*");
		  ++j;
	  }
	  puts("");
   }   
}
