#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double mystrtod(const char *nptr, char **endptr);//преобразование строки в тип double
long mystrtol(const char *nptr, char **endptr, int base);//преобразование строки в тип long
unsigned long mystrtoul(const char *nptr, char **endptr, int base);//преобразование строки в тип unsigned long

int main(void)
{
   char n[] = "11537463.948abc";
   char *ptr;
   
   double num;
   long lnum;
   unsigned long ulnum;
   
   int b = 10;

   num = mystrtod(n, &ptr);
   printf("mystrtod(\"%s\", &ptr) = %.3f (ptr: %s)\n", n, num, ptr);
   
   lnum = mystrtol(n, &ptr, b);
   printf("\nmystrtol(\"%s\", &ptr, %d) = %ld (ptr: %s)\n", n, b, lnum, ptr);
   
   ulnum = mystrtoul(n, &ptr, b);
   printf("\nmystrtoul(\"%s\", &ptr, %d) = %lu (ptr: %s)\n", n, b, ulnum, ptr);
} 
double mystrtod(const char *nptr, char **endptr)
{
	
	int i = 0, intValue, d = 0, result = 0, k = 0;
	double result1, m;
	if(nptr[0] == '-')
	{
		k = 1;
		i++;
	}
	for(; nptr[i] >= '0' && nptr[i] <= '9'; ++i)
	{
		intValue = nptr[i] - '0';
		result = result * 10 + intValue;
	}
    
    result1 = (double)result;
   
    if(nptr[i] == '.')
	{
	   
	    i++;
		for(; nptr[i] >= '0' && nptr[i] <= '9'; ++i)
	    { d++;
	    
			intValue = nptr[i] - '0';
			 
			 
			m = (double)intValue / pow(10, d);
			 
		    result1 = result1 + m;
		}
	
		endptr[0] = (char *) &nptr[i];
	}
   if(k == 1)
	{
		result1 *= -1;
	}

   return result1;
}
long mystrtol(const char *nptr, char **endptr, int base)
{
    int k = 0, i = 0, intValue;
	long result = 0;
	if(nptr[0] == '-')
	{
		k = 1;
		i++;
	}
	
	for(; nptr[i] >= '0' && nptr[i] <= '9'; ++i)
	{
		intValue = nptr[i] - '0';
		result = result * 10 + intValue;
	}
	if(k == 1)
	{
		result *= -1;
	}
    endptr[0] = (char *) &nptr[i];
	
    return result;
}

unsigned long mystrtoul(const char *nptr, char **endptr, int base)
{
  
    int i , intValue;
	unsigned long result = 0;
	
	for(i = 0; nptr[i] >= '0' && nptr[i] <= '9'; ++i)
	{
		intValue = nptr[i] - '0';
		result = result * 10 + intValue;
	}
	
    endptr[0] = (char *) &nptr[i];
	
    return result;
} 










