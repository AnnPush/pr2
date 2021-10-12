#include <stdio.h>

typedef union integer {
   char c;
   short s;
   int i;
   long b;
} Tinteder;

int main(void)
{
   Tinteder tinteger;

   printf("Char short int long: ");
   scanf("%c%hi%d%ld", &tinteger.c, &tinteger.s, &tinteger.i, &tinteger.b);

   printf("Char: %c\nShort: %hi\nInt: %d\nLong: %ld\n",
      tinteger.c, tinteger.s, tinteger.i, tinteger.b);
}
