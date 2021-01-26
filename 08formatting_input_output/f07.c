#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int main(void)
{
	int n = 0;
	int number[SIZE];
	
	printf("%-10s%-20s\n", "Value", "Total characters");
	
	for(int i = 0; i < SIZE; ++i)
	{
		number[i] = 1 + rand() % 1000;
		n += printf("%d", number[i]);
		printf("\t  %d\n", n);
	}
	
}
