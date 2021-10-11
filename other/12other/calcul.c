#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float x, y;
	int i;
	
	
	printf("Input x = ");
	scanf("%f", &x);
	
	printf("Input y = ");
	scanf("%f", &y);
	
	printf("oper:  \n1 = *\n2 = +\n3 = /\n2 = -\nselect code = ");
	scanf("%d ", &i);
	
	
	if( i == 1)
		printf("%g * %g = %g", x, y, x * y);
	
	if( i == 2)
		printf("%g + %g = %g", x, y, x + y);
	
	if( i == 3)
		printf("%g / %g = %g", x, y, x / y);
	
	if( i == 4)
		printf("%g - %g = %g", x, y, x - y);
}
