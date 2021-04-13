#include <stdio.h>
#define SIZE 30

unsigned int mystrlen(char *ptr);

int main(void)
{
	int len;
	char array[SIZE];
	printf("Enter string: ");
	fgets(array, SIZE, stdin);
	
	len = mystrlen(array);
	printf(" In string %s has %d characters in it", array, len);
}

unsigned int mystrlen(char* ptr)
{
	unsigned int n = 0;
	
	while(*ptr != '\0')
	{
		n++;
	    ptr++;
	}
	return n - 1;	
}

#include <stdio.h>
#define SIZE 30

unsigned int mystrlen(char *ptr);

int main(void)
{
	int len;
	char array[SIZE];
	printf("Enter string: ");
	fgets(array, SIZE, stdin);
	
	len = mystrlen(array);
	printf(" In string %s has %d characters in it", array, len);
}

unsigned int mystrlen(char* ptr)
{
	unsigned int n = 0;
	
	while(ptr[n] != '\0')
	{
		n++;
	    
	}
	return n - 1;	
}
