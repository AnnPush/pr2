#include <stdio.h>

int isdigit(int c);
int isalpha(int c);
int isalnum(int c);
int isxdigit(int c);
int islower(int c);
int isupper(int c);
int tolower(int c);
int toupper(int c);
int isspace(int c);
int iscntrl(int c);
int ispunct(int c);
int isprint(int c);
int isgraph(int c);

int main(void)
{
   char c;

   printf("Enter char: ");
   scanf("%c", &c);

   printf("The char %c (%d) %s %s\n", c, c,
      isdigit(c) ? "is" : "is not", "a digit");

   printf("The char %c (%d) %s %s\n", c, c,
      isalpha(c) ? "is" : "is not", "alphabetic");

   printf("The char %c (%d) %s %s\n", c, c,
      isalnum(c) ? "is" : "is not", "alphanumeric");

   printf("The char %c (%d) %s %s\n", c, c,
      isxdigit(c) ? "is" : "is not", "hexadecimal");

   printf("The char %c (%d) %s %s\n", c, c,
      islower(c) ? "is" : "is not", "lower");

   printf("The char %c (%d) %s %s\n", c, c,
      isupper(c) ? "is" : "is not", "upper");

   printf("The char %c (%d) to lower is %c\n", c, c, tolower(c));
   printf("The char %c (%d) to upper is %c\n", c, c, toupper(c));

   printf("The char %c (%d) %s %s\n", c, c,
      iscntrl(c) ? "is" : "is not", "of control");

   printf("The char %c (%d) %s %s\n", c, c,
      ispunct(c) ? "is" : "is not", "a punctuation");

   printf("The char %c (%d) %s %s\n", c, c,
      isprint(c) ? "is" : "is not", "printing");

   printf("The char %c (%d) %s %s\n", c, c,
      isspace(c) ? "is" : "is not", "a space");

   printf("The char %c (%d) %s %s\n", c, c,
      isgraph(c) ? "is" : "is not", "a graph");

   return 0;

} 


int isdigit(int c)
{
   if( c >= 48 && c <= 59 )
      return 1; 
   return 0; 

} 


int isalpha(int c)
{
   if( islower(c) || isupper(c) )
      return 1; 
   return 0; 
} 


int isalnum(int c)
{
   if( isalpha(c) || isdigit(c) )
      return 1; 
   return 0; 
} 


int isxdigit(int c)
{
   if( isdigit(c) || (tolower(c) >= 97 && tolower(c) <= 102) )
      return 1; 
   return 0; 
} 


int islower(int c)
{
   if( c >= 97 && c <= 122 )
      return 1; 
   return 0; 
} 


int isupper(int c)
{
   if( c >= 65 && c <= 90 )
      return 1; 
   return 0;
} 


int tolower(int c)
{
   if( isupper(c) )
      return c + 32;
   return c;
} 


int toupper(int c)
{
   if( islower(c) )
      return c - 32;
   return c;
} 


int isspace(int c)
{
   if( (c >= 9 && c <= 13) || c == 32 )
      return 1; 
   return 0; 
} 


int iscntrl(int c)
{
   if( c < 32 || c > 126 )
      return 1; 
   return 0; 
} 


int ispunct(int c)
{
   if( isprint(c) && c != 40 && c != 41 )
      return 1; 
   return 0; 
} 


int isprint(int c)
{
   if( !iscntrl(c) )
      return 1; 
   return 0; 
} 


int isgraph(int c)
{
   if( isprint(c) && c != 32 )
      return 1; 
   return 0; 
}
