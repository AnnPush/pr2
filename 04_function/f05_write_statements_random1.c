#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int n, i;
	
	srand(time(NULL));
	for( i = 0; i < 100; ++i)
	{
		//n = 2 + 2 * (rand() % 5);
		//n = 3 + 2 * (rand() % 5);
		n = 6 + 4 * (rand() % 5);

		printf("n = %d\n", n);
	}	
}
