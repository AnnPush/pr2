#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 127

int main(void)
{
	char arrstr[SIZE][SIZE];
    char *searchPtr;
	char *s;
	int i = 0;
	
	printf("Enter string (%d to end): ", EOF);
    fgets(arrstr[i], SIZE, stdin);
	
    s = strchr(arrstr[0], '\n');
	if(s != NULL)
		*s = '\0';
	
    while (strtol(arrstr[i++], &searchPtr, 0) != -1 )
    {
        printf("Enter string (%d to end): ", EOF);
        fgets(arrstr[i], SIZE, stdin);
		
		s = strchr(arrstr[i], '\n');
	    if(s != NULL)
		   *s = '\0';
	   
		for(int j = 0; j < (int)strlen(arrstr[i]); j++)
	 arrstr[i][j] = tolower((int)arrstr[i][j]);
	}
	puts("");
	for(i = 0; i < SIZE; i++) {
      if( !strncmp( &arrstr[i][ strlen(arrstr[i]) - 2 ], "ed", 2 ) )
	 printf("%s\n", arrstr[i]);
   }
}
