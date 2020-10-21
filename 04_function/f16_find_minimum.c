/*(Find the Minimum) Write a function that returns the smallest of three floating-point
numbers.*/

# include <stdio.h>

float isMinimum(float, float, float);

int main()
{
	float i1, i2, i3;
	printf("%s", "Enter three floating-point numbers:");
	scanf("%f%f%f", &i1, &i2, &i3);

	printf("Minimum: %.2f\n", isMinimum(i1, i2, i3));
}

float isMinimum( float a, float b, float c)
{
	float min;
	
	min = a;

	if(b < min)
	   min = b;
	
	if(c < min)
		min = c;
		
	return min;
}
