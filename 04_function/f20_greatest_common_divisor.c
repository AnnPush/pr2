/*(Greatest Common Divisor) The greatest common divisor (GCD) of two integers is the largest
integer that evenly divides each of the two numbers. Write a function gcd that returns the greatest
common divisor of two integers*/

#include <stdio.h>

int gcd(int, int);

int main(void)
{
	int digit1, digit2;
	printf("%s\n", "Enter digits:");
	scanf("%d%d", &digit1, &digit2);

	printf("Greatest Common Divisor: %d\n", gcd(digit1, digit2));
}

int gcd(int d1, int d2)
{
	int n, i;
	int max = 1;
	if(d1 < d2)
		n = d1;
	else
		n = d2;

	for(i = 1; i <= n; ++i)
	{
		if(d1 % i == d2 % i)
	        max = i;
	}
	return max;

}
