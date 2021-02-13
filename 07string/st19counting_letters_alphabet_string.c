#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 127

int main(void)
{
	char arrstr[SIZE][SIZE];
	char * searchPtr;
	int i = 0;
	int counter[SIZE] = {0};
	
	printf("Enter string (%d to end): ", EOF);
    fgets(arrstr[i], SIZE, stdin);

    while (strtol(arrstr[i++], &searchPtr, 0) != -1 )
    {
        printf("Enter string (%d to end): ", EOF);
        fgets(arrstr[i], SIZE, stdin);
	}
	arrstr[i - 1][0] = '\0';
	
	for(i = 0; i < SIZE; i++) {
      for(int j = 0; (unsigned)j < strlen(arrstr[i]); j++) {
	 ++counter[tolower((int)arrstr[i][j])];
      }
   }
 
   for(i = 97; i < 122; i++) {
      if(counter[i]) {
         printf("%c[%d] ", i, counter[i]);
      }
   }
   puts(""); 
}
