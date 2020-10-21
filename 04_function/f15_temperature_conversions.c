/*(Temperature Conversions) Implement the following integer functions:
a) Function toCelsius returns the Celsius equivalent of a Fahrenheit temperature.
b) Function toFahrenheit returns the Fahrenheit equivalent of a Celsius temperature.
c) Use these functions to write a program that prints charts showing the Fahrenheit equivalents
of all Celsius temperatures from 0 to 100 degrees, and the Celsius equivalents of
all Fahrenheit temperatures from 32 to 212 degrees. Print the outputs in a tabular format
that minimizes the number of lines of output while remaining readable*/

#include <stdio.h>

int toCelsius(int);
int toFahrenheit(int);

int main()
{

	printf("%s\n\n", "Fahrenheit equivalents of all Celsius temperatures");
    
	for(int i = 0; i <= 100; i++)
	{
		printf("%d\t%d\n", i, toFahrenheit(i));
	}
    
	printf("%s\n\n", "\n\nThe Celsius equivalents of all Fahrenheit temperatures");

    for(int j = 32; j <= 212; j++)
	{
		printf("%d\t%d\n", j, toCelsius(j));
	}
}

int toCelsius(int f)
{
    int c;
	c = 5 * (f - 32) / 9;
	return c;
}
int toFahrenheit(int c)
{
    int f;
	f = 9 * c / 5 + 32;
	return f;
}

