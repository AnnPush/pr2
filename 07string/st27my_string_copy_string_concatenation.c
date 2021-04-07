//функция strcpy версия с массивами
#include <stdio.h>
#define SIZE 50

char* mystrcpy(char* s1, const char* s2);

int main(void)
{
	char arr1[SIZE];
	char arr2[SIZE];
	
	puts("Enter first string (arr1):");
	fgets(arr1, SIZE, stdin);
	
	puts("Enter second string (arr2):");
	fgets(arr2, SIZE, stdin);
	
	puts("\nCoping second string into first...\n");
	mystrcpy(arr1, arr2);
	
	printf("arr1: %s\n", arr1);
	printf("arr2: %s\n", arr2);	
}

char* mystrcpy(char* s1, const char* s2)
{
	int i;
	for(i = 0; (s1[i] = s2[i]) != '\0'; ++i);
	return s1;
}



//функция strcpy версия с указателями
#include <stdio.h>
#define SIZE 50

char* mystrcpy(char* s1, const char* s2);

int main(void)
{
	char arr1[SIZE];
	char arr2[SIZE];
	
	puts("Enter first string (arr1):");
	fgets(arr1, SIZE, stdin);
	
	puts("Enter second string (arr2):");
	fgets(arr2, SIZE, stdin);
	
	puts("\nCoping second string into first...\n");
	mystrcpy(arr1, arr2);
	
	printf("arr1: %s\n", arr1);
	printf("arr2: %s\n", arr2);	
}

char* mystrcpy(char* s1, const char* s2)
{
	char* start = s1;
	while(*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	
	return start;
}
/*2-ой вариант

char* mystrcpy(char* s1, const char* s2)
{
	int i;
	for(i = 0; (*(s1 + i) = *(s2 + i)) != '\0'; ++i);
	*s1 = '\0';
	return s1;
}

*/


//функция strncpy версия с массивами
#include <stdio.h>
#define SIZE 50

char* mystrncpy(char* s1, const char* s2, size_t n);

int main(void)
{
	char arr1[SIZE];
	char arr2[SIZE];
	size_t count;
	
	puts("Enter first string (arr1):");
	fgets(arr1, SIZE, stdin);
	
	puts("Enter second string (arr2):");
	fgets(arr2, SIZE, stdin);
	
	puts("Enter count simbol:");
	scanf("%u", &count);
	
	puts("\nCoping second string into first...\n");
	mystrncpy(arr1, arr2, count);
	
	printf("arr1: %s\n", arr1);
	printf("arr2: %s\n", arr2);	
}

char* mystrncpy(char* s1, const char* s2, size_t n)
{
	int i;
	for(i = 0; i < (int)n; ++i)
	if((s1[i] = s2[i]) == '\0')
		break;
	s1[n] = '\0';
	return s1;
}



//функция strncpy версия с указателями
#include <stdio.h>
#define SIZE 50

char* mystrncpy(char* s1, const char* s2, size_t n);

int main(void)
{
	char arr1[SIZE];
	char arr2[SIZE];
	size_t count;
	
	puts("Enter first string (arr1):");
	fgets(arr1, SIZE, stdin);
	
	puts("Enter second string (arr2):");
	fgets(arr2, SIZE, stdin);
	
	puts("Enter count simbol:");
	scanf("%u", &count);
	
	puts("\nCoping second string into first...\n");
	mystrncpy(arr1, arr2, count);
	
	printf("arr1: %s\n", arr1);
	printf("arr2: %s\n", arr2);	
}

char* mystrncpy(char* s1, const char* s2, size_t n)
{
	int i;
	for(i = 0; i < (int)n; ++i)
	if((*(s1 + i) = *(s2 + i)) == '\0')
		break;
		*(s1 + n) = '\0';
	return s1;
}

//функция strcat версия с массивами
#include <stdio.h>
#include <string.h>

#define SIZE 50

char* mystrcat(char* s1, const char* s2);

int main(void)
{
	char arr1[SIZE];
	char arr2[SIZE];
	char* ptr;
	
	puts("Enter first string (arr1):");
	fgets(arr1, SIZE, stdin);
	
	ptr = strchr(arr1, '\n');
	if(ptr != NULL)
		*ptr = '\0';
	
	puts("Enter second string (arr2):");
	fgets(arr2, SIZE, stdin);

	mystrcat(arr1, arr2);
	
	printf("arr1: %s\n", arr1);
	printf("arr2: %s\n", arr2);	
}

char* mystrcat(char* s1, const char* s2)
{
	int i, j;
	
	j = (int)strlen(s1);
	
	for(i = 0; (s1[j + i] = s2[i]) != '\0'; ++i);
	
	return s1;
}


//функция strcat версия с указателями
#include <stdio.h>
#include <string.h>

#define SIZE 50

char* mystrcat(char* s1, const char* s2);

int main(void)
{
	char arr1[SIZE];
	char arr2[SIZE];
	char* ptr;
	
	puts("Enter first string (arr1):");
	fgets(arr1, SIZE, stdin);
	
	ptr = strchr(arr1, '\n');
	if(ptr != NULL)
		*ptr = '\0';
	
	puts("Enter second string (arr2):");
	fgets(arr2, SIZE, stdin);

	mystrcat(arr1, arr2);
	
	printf("arr1: %s\n", arr1);
	printf("arr2: %s\n", arr2);	
}

char* mystrcat(char* s1, const char* s2)
{
	int i, j;
	
	j = (int)strlen(s1);
	
	for(i = 0; (*(s1 +j + i) = *(s2 + i)) != '\0'; ++i);
	
	return s1;
}

//функция strncat версия с массивами
#include <stdio.h>
#include <string.h>

#define SIZE 50

char* mystrncat(char* s1, const char* s2, size_t n);

int main(void)
{
	char arr1[SIZE];
	char arr2[SIZE];
	size_t count;
	char* ptr;

	puts("Enter first string (arr1):");
	fgets(arr1, SIZE, stdin);
	
	ptr = strchr(arr1, '\n');
	if(ptr != NULL)
		*ptr = '\0';
	
	puts("Enter second string (arr2):");
	fgets(arr2, SIZE, stdin);
	
	
	puts("Enter count simbol:");
	scanf("%u", &count);
	
	mystrncat(arr1, arr2, count);
	
	printf("arr1: %s\n", arr1);
	printf("arr2: %s\n", arr2);	
}

char* mystrncat(char* s1, const char* s2, size_t n)
{
	int i, j;
	
	j = (int)strlen(s1);
	for(i = 0; i < (int)n; i++)
	 if((s1[i + j] = s2[i]) == '\0')
        break;		 
	s1[j + n] = '\0';
	return s1;
}

//функция strncat версия с указателями
#include <stdio.h>
#include <string.h>

#define SIZE 50

char* mystrncat(char* s1, const char* s2, size_t n);

int main(void)
{
	char arr1[SIZE];
	char arr2[SIZE];
	size_t count;
	char* ptr;

	puts("Enter first string (arr1):");
	fgets(arr1, SIZE, stdin);
	
	ptr = strchr(arr1, '\n');
	if(ptr != NULL)
		*ptr = '\0';
	
	puts("Enter second string (arr2):");
	fgets(arr2, SIZE, stdin);
	
	
	puts("Enter count simbol:");
	scanf("%u", &count);
	
	mystrncat(arr1, arr2, count);
	
	printf("arr1: %s\n", arr1);
	printf("arr2: %s\n", arr2);	
}

char* mystrncat(char* s1, const char* s2, size_t n)
{
	int i, j;
	
	j = (int)strlen(s1);
	for(i = 0; i < (int)n; i++)
	 if((*(s1 + i + j) = *(s2 + i)) == '\0')
        break;		 
	*(s1 + j + n) = '\0';
	return s1;
}
