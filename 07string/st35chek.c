#include <stdio.h>
#include <string.h>

#define SIZE 9

int main(void)
{
   char sum[SIZE] = { 0 };
   int t = SIZE;

   printf("Enter sum: ");
   fgets(sum, SIZE, stdin);
   while( (int)strlen(sum) > SIZE ) {
      printf("Error: too many numbers\n");
      printf("Enter sum: ");
      fgets(sum, SIZE, stdin);;
   }

   printf("Protect number: ");
   t -= (int)strlen(sum);
   while(t--)
      printf("*");

   printf("%s\n", sum);
}
