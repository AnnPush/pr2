#include <stdio.h>

int main(void)
{
	int fahrenheit;
	float celcius;
	
	printf("%10s%10s\n", "Fahrenheit", "Celcius");
	
	for(fahrenheit = 1; fahrenheit <= 212; ++fahrenheit)
	{
		celcius = 5.0 / 9.0 * ( (float)fahrenheit - 32.0);
		printf("%10d%+10.3f\n", fahrenheit, celcius);
	}
	
}
