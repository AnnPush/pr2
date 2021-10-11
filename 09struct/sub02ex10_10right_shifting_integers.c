#include <stdio.h>

void func(int n);

int main(void)
{
   int num = 90;

   printf("before(%d):\t", num);
   func(num);

   num >>= 4;
   printf("\n");

   printf("after(%d):\t", num);
   func(num);

   printf("\n");

} 


void func(int n)
{
   int i;
   unsigned mask = 1 << 31;

   for(i = 1; i <= 32; i++) {
      printf("%d", n & mask ? 1 : 0);

      if( !(i % 8) )
	 putchar(' ');

      n <<= 1;
   }

} 
