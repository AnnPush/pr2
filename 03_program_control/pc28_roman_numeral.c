/*(Roman-Numeral Equivalent of Decimal Values) Write a program that prints a table of all
the Roman-numeral equivalents of the decimal numbers in the range 1 to 100. */

#include <stdio.h>

int main (void)
{


  for (int i = 1; i <= 100; i++)
    {
        //---------------------------
         if (i == 100)
	        printf ("%s", "C");

        //--------------------------------
        
       
         if (i / 50 > 0 && i < 90)
	    {
	        printf ("%s", "L");
    	}
	
	    else if (i >= 40 && i < 50)
        {
	        printf ("%s", "XL");
	       
    	}
    	else if (i/10 == 9)
        {
	        printf ("%s", "XC");
	       
    	}
    	//--------------------------------
    	
      if (i / 10 >= 1)
	{

	    if (i/10 != 4 && i/10 != 5  && i != 100 )
	    {
	        if(i/10 > 5 && i/10 < 9)
            {
	            for (int j = 1; j <= i / 10 - 5; j++)
	        	{
		            printf ("%s", "X");
	        	}
            }
	    	else if( i/10 < 9)
		    {
	            for (int j = 1; j <= i / 10; j++)
		        {
		           printf ("%s", "X");
		        }
		
	        }
	    }
	}
	//-------------------------------------------
      if (i == 9 || i % 10 == 9)
	  {
	      printf ("%s", "IX");
	  }
	  else if( i == 4 || i%10 == 4)
	  {
	      printf ("%s", "IV");
	  }
	  else if (!(i % 10 == 0) && i%10 > 4)
	  {
	       printf ("%s", "V");
	  }
	
	//---------------------------------
       if (i != 4 && i !=9 && i%5 != 4 && i%5 != 9 && i%10 != 0)
	   {
	      for (int j = 1; j <= i%5; j++)
	      {
	          printf ("%s", "I");
	      }
	   }
	  
	
       if (i % 10 != 0)
	      printf ("%s", "\t");
	   else
	      printf ("%s", "\n");
    }
}
