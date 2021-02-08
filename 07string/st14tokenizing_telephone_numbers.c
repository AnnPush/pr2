#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 15

int main(void)
{
	char telephoneNumber[SIZE];
	
	puts("Enter telephoneNumber(example: (555)555-5555): ");
	fgets(telephoneNumber, SIZE, stdin);
	
	char *currentLexem = strtok(telephoneNumber, "()-");
	
    int kod = strtod(currentLexem, 0);
	printf("kod: %d\n", kod);
	
	currentLexem = strtok(NULL, "()-");
	char *nom1 = currentLexem;
		
	currentLexem = strtok(NULL, "()-");
	char *nom2 = currentLexem;
		 
    strcat(nom1, nom2);
	
    long telephone = strtol(nom1, 0, 0);
    printf("telephone: %ld\n", telephone);	
}
