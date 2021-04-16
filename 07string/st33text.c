#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STRINGS 5
#define LENGTH 254
#define ASCII 127

int main(void)
{
	char string[STRINGS][LENGTH] = { { 0 } };
    int i = 0, j;
	int counter[ASCII] = { 0 };
	char *ptr;
	long x;

   
   printf("Enter a string (%d to end): ", EOF);
   fgets(string[i], LENGTH, stdin);

   while( strtol(string[i++], &ptr, 0) != EOF ) {
      printf("Enter a string (%d to end): ", EOF);
      fgets(string[i], LENGTH, stdin);
   }
   string[i - 1][0] = '\0';//удалить -1
   
   for(i = 0; i < STRINGS; i++) {
      for(j = 0; (unsigned)j < strlen(string[i]); j++) {
	 ++counter[tolower((int)string[i][j])];
      }
   }
 printf("\nOccurrences table\n"
	  "* (NP = not printable)\n"
	  "* (SP = spaces)\n\n");
	  
	  for(i = j = 1; i < ASCII; i++) {
      if(counter[i]) {

	 if(i < 32) printf("NP: ");
	 else if(i == 32) printf("SP: ");
	 else printf("%2c: ", i);
         printf("%2d | ", counter[i]);

         if( !(j % 4) )
	    printf("\n-----------------------------------\n");
	 ++j;
      }
   }
   printf("\n\n");
}
