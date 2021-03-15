#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double mystrtod(const char *nptr, char **endptr);//преобразование строки в тип double

int main(void)
{
   char n[] = "11537463.948abc";
   char *ptr;
   double num;
   long lnum;

   int b = 10;

   num = mystrtod(n, &ptr);
   printf("mystrtod(\"%s\", &ptr) = %.3f (ptr: %s)\n", n, num, ptr);

  
} 
double mystrtod(const char *nptr, char **endptr)
{
	
	int i, intValue, d = 0, result = 0;
	double result1, m;
	
	for(i = 0; nptr[i] >= '0' && nptr[i] <= '9'; ++i)
	{
		intValue = nptr[i] - '0';
		result = result * 10 + intValue;
	}
    
    result1 = (double)result;
    printf("  \n%f \n", result1);
    if(nptr[i] == '.')
	{
	   
	    i++;
		for(; nptr[i] >= '0' && nptr[i] <= '9'; ++i)
	    { d++;
	    
			intValue = nptr[i] - '0';
			 
			 
			m = (double)intValue / pow(10, d);
			 printf("  \n%f \n", m);
		    result1 = result1 + m;
		}
	
		endptr[0] = (char *) &nptr[i];
	}
   

   return result1;
}

