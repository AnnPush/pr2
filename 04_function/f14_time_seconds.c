/*(Time in Seconds) Write a function that takes the time as three integer arguments (for
hours, minutes, and seconds) and returns the number of seconds since the last time the clock “struck
12.” Use this function to calculate the amount of time in seconds between two times, both of which
are within one 12-hour cycle of the clock.*/

#include <stdio.h>

int isTime(int, int, int);

int main()
{
	int hours, minutes, seconds;

	printf("%s\n", "Enter three integer arguments (for hours, minutes, and seconds):");
	scanf("%d%d%d", &hours, &minutes, &seconds);

	printf("The number of seconds since the last time the clock struck 12: %d\n", isTime(hours, minutes, seconds));
}

int isTime(int h, int m, int s)
{
	return h * 3600 + m * 60 + s;
}
