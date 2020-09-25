/* Calculate the value of 2.5 raised to the power of 3 using the pow function. Print the result
with a precision of 2 in a field width of 10 positions. What is the value that prints?*/
#include <stdio.h>
#include <math.h>

int main(void)
{
	double a = 2.5;
	int b = 3;

	printf("%10.2f\n", pow(2.5, 3));
