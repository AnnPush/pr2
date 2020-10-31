/*Печать ввода с клавиатуры в обратном порядке*/
#include <stdio.h>

int main(void)
{
	int c;

	if((c = getchar()) != EOF)
	{
		main();
		printf("%c", c);
	}
}
