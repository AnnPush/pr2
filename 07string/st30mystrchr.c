#include <stdio.h>
#include <string.h>
char *mystrchr(const char *s, int c);

int main(void)
{
   char string[] = "dfgb nhyb bhmn njhb bh";
   char search = 'n';
   char *p;
  
   p = mystrchr(string, search);
   printf("mystrchr(string, search): %s\n", p);
 }

 char *mystrchr(const char *s, int c)
{
   int i;

   for(i = 0; i < (int)strlen(s); i++) {
      if(s[i] == c)
	 return (char *)&s[i];
   }

   return NULL;
}
