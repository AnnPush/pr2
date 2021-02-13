#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

int main(void)
{
	char arrstr[SIZE][SIZE];
	char searchstr;
    char *searchPtr;
	
	int i = 0;
	int counter = 0;
	
	printf("Enter string (%d to end): ", EOF);
    fgets(arrstr[i], SIZE, stdin);

    while (strtol(arrstr[i++], &searchPtr, 0) != -1 )
    {
        printf("Enter string (%d to end): ", EOF);
        fgets(arrstr[i], SIZE, stdin);
	}
	
    puts("Enter search char: ");
	searchstr = getchar();
	
	
	
	for(int j = 0; j < SIZE; j++) 
	{
        searchPtr = strchr(arrstr[j], searchstr);
        while( searchPtr != NULL )
		{
	        searchPtr = strchr(searchPtr + 1, searchstr);
	        ++counter;
        }
   }

   if(!counter)
      printf("No match found!\n");
   else
      printf("Found %d matches!\n", counter);
}


