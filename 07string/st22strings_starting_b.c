#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 127

int main(void)
{
	char arrstr[SIZE][SIZE];
    char *searchPtr;
	int i = 0;
	
	printf("Enter string (%d to end): ", EOF);
    fgets(arrstr[i], SIZE, stdin);

    while (strtol(arrstr[i++], &searchPtr, 0) != -1 )
    {
        printf("Enter string (%d to end): ", EOF);
        fgets(arrstr[i], SIZE, stdin);
	}
	puts("");
	for(i = 0; i < SIZE; i++) {
      if( tolower((int)arrstr[i][0]) == 'b')
	 printf("%s", arrstr[i]);
	}
}
