#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 127

int main(void)
{
	char arrstr[SIZE][SIZE];
	char * searchPtr;
	int i = 0;
	int counter = 0;
	
	printf("Enter string (%d to end): ", EOF);
    fgets(arrstr[i], SIZE, stdin);

    while (strtol(arrstr[i++], &searchPtr, 0) != -1 )
    {
        printf("Enter string (%d to end): ", EOF);
        fgets(arrstr[i], SIZE, stdin);
	}
	arrstr[i - 1][0] = '\0';
	
	for(i = 0; (unsigned)i < strlen(arrstr[i]); i++) {
		searchPtr = strtok(arrstr[i], " \n");
		while(searchPtr != NULL)
		{
			++counter;
			searchPtr = strtok(NULL, " \n");
		}
   }
 
   if(!counter)
      printf("There are no words!\n");
   else
      printf("There are %d words!\n", counter); 
}
