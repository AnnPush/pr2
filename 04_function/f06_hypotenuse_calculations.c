#include <stdio.h>
#include <math.h>

double hypotenuse(double side1, double side2);

int main(void)
{
	double a = 2;
	double b = 3;
	int i;

	for(i = 1; i <= 3; ++i)
	{
		a += i;
		
		if( i == 2)
		{
			b = (b + i) *2;
		}
		else
		{
			b +=i;
		}

		printf("Hypotenuse %d: %.2f\n", i, hypotenuse(a, b));
	}
}

double hypotenuse(double side1, double side2)
{
	return sqrt(side1 *side1 + side2 * side2);
}
