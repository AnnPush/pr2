#include <stdio.h>

void mystery1(char *s1, const char *s2);

int main(void)
{
	char string1[80];
	char string2[80];
	
	printf("Enter two strings: ");
	scanf("%s%s", string1, string2);
	
	mystery1(string1, string2);
	printf("%s", string1);
}

void mystery1(char *s1, const char *s2)
{
	while(*s1 != '\0')
	{
		s1++;
	}
	for(; *s1 = *s2; s1++, s2++)
	{
		;
	}
}

/*
Добавляет к первой строке вторую
Enter two strings: qwerty                                                                                                                                                          
asdfgh                                                                                                                                                                             
qwertyasdfgh  
*/
