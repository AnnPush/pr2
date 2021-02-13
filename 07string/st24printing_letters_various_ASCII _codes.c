#include <stdio.h>

int main(void)
{
   int code;


   printf("Enter ASCII code: ");
   scanf("%d", &code);
   printf("The character is: %c\n", code);
/*
   printf("ASCII code\tASCII character\n");
   for(code = 0; code <= 255; code++) {
      printf("%.3d\t%c\n", code, code);
   }
*/
} 
