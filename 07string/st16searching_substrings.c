#include <stdio.h>
#include <string.h>

#define SIZE 100

int main(void)
{
	char arrstr[SIZE];
	char searchstr[SIZE];
    char *searchPtr;
	char *s;
	
	puts("Enter string: ");
	fgets(arrstr, SIZE, stdin);
	
    puts("Enter search string: ");
	fgets(searchstr, SIZE, stdin);
	s = strchr(searchstr, '\n');
	if(s != NULL)
		*s = '\0';
	
	
	searchPtr = strstr(arrstr, searchstr);
	if(searchPtr == NULL)
	{
		puts("String not");
	}
	else
	{
	printf("String1: %s\n", searchPtr);
	}
	searchPtr = strstr(searchPtr + 1, searchstr);
	if(searchPtr == NULL)
	{
		puts("String not");
	}
	else{
	printf("String2: %s\n", searchPtr);
	}
}
