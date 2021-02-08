#include <stdio.h>
#include <string.h>

#define SIZE 100

void strrev(char *str, char *currentLexem);

int main(void)
{
	char strtext[SIZE];
	char *firstLexem;
	
	puts("Enter string text: ");
	fgets(strtext, SIZE, stdin);
	
	firstLexem = strtok(strtext, " ");
	strrev(strtext, firstLexem);
	printf(" %s ", firstLexem);
}

void strrev(char *str, char *currentLexem)
{

	currentLexem = strtok(NULL, " \n");
	
	if(currentLexem != NULL )
	{
		strrev(str, currentLexem);
		printf("%s ", currentLexem);
	}	
}
