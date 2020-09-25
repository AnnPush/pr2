/*Print the value 333.546372 in a field width of 15 characters with precisions of 1, 2, 3, 4
and 5. Left justify the output. What are the five values that print*/

#include <stdio.h>

int main(void)
{
	float number = 333.546372;

	printf("%-15.1f\n", number);
	printf("%-15.2f\n", number);
	printf("%-15.3f\n", number);
	printf("%-15.4f\n", number);
	printf("%-15.5f\n", number);
}
