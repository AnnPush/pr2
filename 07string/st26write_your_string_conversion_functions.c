#include <stdio.h>
#include <string.h>
#include <ctype.h>


double strtod(const char *nptr, char **endptr);
long strtol(const char *nptr, char **endptr, int base);
unsigned long strtoul(const char *nptr, char **endptr, int base);

int main(void)
{
   char n[] = "11537463.948abc", *strp;
   double num;
   long lnum;

   int b = 10;


   num = strtod(n, &strp);
   printf("strtod(\"%s\", &strp) = %f (strp: %s)\n", n, num, strp);

   lnum = strtol(n, &strp, b);
   printf("strtol(\"%s\", &strp, %d) = %ld (strp: %s)\n", n, b, lnum, strp);

   lnum = strtoul(n, &strp, b);
   printf("strtoul(\"%s\", &strp, %d) = %lu (strp: %s)\n", n, b, lnum, strp);

  
} 



double strtod(const char *nptr, char **endptr)
{
   double ret, d = 1;
   int i, n = atoi(nptr), p_val = 1;
   char *c;

   /* Calculate the positional value */
   for(p_val = 1; p_val < n; p_val *= 10)
      ; /* Empty body */

   p_val /= 10; /* Toggle the latest (exceded) value */

   /* Calculate the decimal numbers */
   for(ret = 0, i = 0; i < (int)strlen(nptr); i++) {
      if( !isdigit((int)nptr[i]) ) {
	 ++i; /* Go to.. */
	 c = (char *) &nptr[i]; /* ..the next position */
	 break;
      }

      ret += (int)(nptr[i] - '0') * p_val;
      p_val /= 10;
   }

   n = atoi(c); /* To be continue.. :-) */

   /* Calculate the floating point numbers */
   for(i = 0; i < (int)strlen(c); i++) {
      if( !isdigit((int)c[i]) ) {
	 break;
      }

      d *= 0.1;
   }
   endptr[0] = (char *) &c[i];

   ret += n * d; /* Add the floating point numbers */

   return ret;
}


/* Convert ASCII string to long */
long strtol(const char *nptr, char **endptr, int base)
{
   long ret;
   int i, n = atoi(nptr), p_val = 1;

   /* Skip all numbers <= 5 */
   if(base <= 5) {
      endptr[0] = (char *) nptr;
      return 0;
   }

   /* Calculate the positional value */
   for(p_val = 1; p_val < n; p_val *= base)
      ; /* Empty body */

   if(base <= 7) p_val /= base; /* A little fix */

   /* Calculate the decimal numbers */
   for(ret = 0, i = 0; i < (int)strlen(nptr); i++) {
      if( !isdigit((int)nptr[i]) ) {
	 break;
      }

      ret += (nptr[i] - '0') * p_val;
      p_val /= base;
   }
   ret /= base; /* Toggle a zero */

   endptr[0] = (char *) &nptr[i];

   return ret;
} /* eof strtol() */

/* Convert ASCII string to unsigned long */
unsigned long strtoul(const char *nptr, char **endptr, int base)
{
   unsigned long ret;
   int i, p_val = 1, n = atoi(nptr);

   /* Skip all numbers <= 5 */
   if(base <= 5) {
      endptr[0] = (char *) nptr;
      return 0;
   }

   /* Calculate the positional value */
   for(p_val = 1; p_val < n; p_val *= base)
      ; /* Empty body */

   if(base <= 7) p_val /= base; /* A little fix */

   /* Calculate the decimal numbers */
   for(ret = 0, i = 0; i < (int)strlen(nptr); i++) {
      if( !isdigit((int)nptr[i]) ) {
	 break;
      }

      ret += (nptr[i] - '0') * p_val;
      p_val /= base;
   }
   ret /= base; /* Toggle a zero */

   endptr[0] = (char *) &nptr[i];

   return ret;
} /* eof strtol() */
