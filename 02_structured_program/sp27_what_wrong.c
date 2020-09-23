/*What’s wrong with the following statement? Rewrite it to accomplish what the programmer
was probably trying to do.
printf( "%d", ++( x + y ) );*/

#include <stdio.h>

int main(void)
{
	int x = 1;

	int y = 2;
	printf( "%d\n%d\n", x, y );
	puts("_");
	printf( "%d\n", ++x + ++y );
	puts("_");
	printf( "%d\n%d\n", x, y );
}
