/*Произведение двух целых(рекурсия). Изменить, чтобы числа могли быть и отрицательными*/
#include <stdio.h>

int mystery(int a, int b);

int main(void)
{
	int x, y;

	printf("Enter two integers:\n");
	scanf("%d%d", &x, &y);

	printf("The result is %d\n", mystery(x, y));
}

int mystery(int a, int b)
{
	if(b == 0)
	{
		return 0;
	}
	else if(b > 0)
	{
		return a + mystery(a, b - 1);
	}
	else
	{
		return -a + mystery(a, b + 1);
	}
}
