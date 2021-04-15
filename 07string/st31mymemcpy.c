#include <stdio.h>

void *mymemcpy(void *s1, const void *s2, size_t n);

int main(void)
{
   char strs2[] = "fghj bn bgth njm h njm";
   char strs1[40]={0};
  
   mymemcpy(strs1, strs2, 6);
   printf("memcpy(): %s\n", strs1);
}

void *mymemcpy(void *s1, const void *s2, size_t n)
{
   int i;
   char *sr1 = (char*)s1;
   char *sr2 = (char*)s2;
   for(i = 0; i < n; i++)
    sr1[i] = sr2[i];

   return s1;
} 
