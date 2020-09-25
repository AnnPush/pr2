/* Sum the odd integers between 1 and 99 using a for statement. Use the unsigned integer
variables sum and count*/
#include <stdio.h>

int main(void)
{
	unsigned int sum = 0;

	for(unsigned int count = 1; count < 100; count += 2)
	{
		sum +=count;
	}

	printf("Sum = %u", sum);

}
