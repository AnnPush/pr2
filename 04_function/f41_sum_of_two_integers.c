/*Сумма двух целых(рекурсия)*/
#include <stdio.h>

int sum(int a, int b);

int main(void)
{
	int x, y;

	printf("Enter two integers:\n");
	scanf("%d%d", &x, &y);

	printf("The result is %d\n", sum(x, y));
}

int sum(int a, int b)
{
	if(a == 0)
	{
		return b;
	}
	else 
	{
		return mystery(a - 1, b + 1);
	}
	
}
