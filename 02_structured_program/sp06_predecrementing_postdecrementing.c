/*(Predecrementing vs. Postdecrementing) Write a program that demonstrates the difference
between predecrementing and postdecrementing using the decrement operator --.*/

#include <stdio.h>

int main(void)
{
	int a;
	int b = 2;

	printf("b ==%d\n", b);
	a = 2 * ++b;
	printf("2 * ++b = %d\n", a);

	printf("b ==%d\n", b);
	a = 3 * b++;
	printf("3 * b++ = %d\n", a);

	printf("b ==%d\n", b);
	a = 2 * --b;
	printf("2 * --b = %d\n", a);

	printf("b ==%d\n", b);
	a = 3 * b--;
	printf("3 * b-- = %d\n", a);
	printf("b ==%d\n", b);
}
