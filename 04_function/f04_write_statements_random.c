#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int n, i;
	
	
	srand(time(NULL));
	for( i = 0; i < 100; ++i)
	{
	    //n = 1 + rand() % 2;
		//n = 1 + rand() % 100;
		//n = rand() % 10;
		//n = 1000 + rand() % 113;
		//n= rand() % 3 - 1;

		n = rand() % 15 - 3;
		
        printf("n = %d\n", n);
	}	
}
