#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 127

void sortarray(char *string[]);

int main(void)
{
	char arrstr[SIZE][SIZE]={{0}};
	char *searchPtr;
	char *ptr[SIZE]={0};
	int i = 0, j = 0;
	
	printf("Enter string (%d to end): ", EOF);
    fgets(arrstr[i], SIZE, stdin);

    while (strtol(arrstr[i++], &searchPtr, 0) != -1 )
    {
        printf("Enter string (%d to end): ", EOF);
        fgets(arrstr[i], SIZE, stdin);
	}
	
	arrstr[i - 1][0] = '\0';
	
	for(i = 0; i < SIZE; i++)
       ptr[i] = arrstr[i];
   
	sortarray(ptr);
	
	for(i = 0; i < SIZE; i++)
	{
        if( strlen(ptr[i]) )
           printf("%s\n", ptr[i]);
    }	
}


void sortarray(char *string[])
{
    int i, j;
    char *tmp;

    for(i = 1; i < SIZE; i++)
	{
        for(j = 0; j < SIZE - 2; j++)
		{
            if( strcmp(string[j], string[j + 1]) > 0 )
			{   
	            tmp = string[j];
	            string[j] = string[j + 1];
	            string[j + 1] = tmp;
	        }
        }
    }
} 
