#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

int main(void)
{
	char arrstr[SIZE][SIZE];
	char searchstr[SIZE];
    char *searchPtr;
	char *s;
	int i = 0;
	int counter = 0;
	
	printf("Enter string (%d to end): ", EOF);
    fgets(arrstr[i], SIZE, stdin);

    while (strtol(arrstr[i++], &searchPtr, 0) != -1 )
    {
        printf("Enter string (%d to end): ", EOF);
        fgets(arrstr[i], SIZE, stdin);
	}
	
    puts("Enter search string: ");
	fgets(searchstr, SIZE, stdin);
	
	s = strchr(searchstr, '\n');
	if(s != NULL)
		*s = '\0';
	
	for(i = 0; i < STR; i++) 
	{
        searchPtr = strstr(arrstr[i], searchstr);
        while( searchPtr != NULL )
		{
	        searchPtr = strstr(searchPtr + 1, searchstr);
	        ++counter;
        }
   }

   if(!counter)
      printf("No match found!\n");
   else
      printf("Found %d matches!\n", counter);
}



