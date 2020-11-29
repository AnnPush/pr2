#include <stdio.h>

void stringReverse(char a[], char size, int i);

int main(void)
{
	char array[] = {'d', 'y', 'n', 'o', 'j', 'l', 'p', 'r', 'y', '\0'};
	for(int i = 0;  array[i] != '\0'; ++i)
	{
		printf("%5c", array[i]);
	}
	puts("");
	stringReverse(array, '\0', 0);
}

void stringReverse(char a[], char size, int i)
{
	if(a[i] != size)
	{
		stringReverse(a, size, i + 1);
		printf("%5c", a[i]);
		
	}
}
