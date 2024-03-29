#include <stdio.h>

typedef unsigned u_int;

void pbits(u_int n);
u_int reverseBits(u_int num);

int main(void)
{
   u_int num;

   printf("Give me a number: ");
   scanf("%u", &num);

   printf("before:\t");
   pbits(num);
   putchar('\n');

   printf("after:\t");
   pbits( reverseBits(num) );
   putchar('\n');

   
} 


void pbits(u_int n)
{
   u_int mask = 1 << 31;
   int i;

   for(i = 1; i <= 32; i++) {
      printf("%u", n & mask ? 1 : 0);

      if( !(i % 8) )
         putchar(' ');

      n <<= 1;
   }

} 


u_int reverseBits(u_int num)
{
   return ~num;
} 
