#include <stdio.h>
#include <math.h>

double work(double x);

int main(void)
{
    double y;
    printf("%s", " Number digit, -1 to end:");
    scanf("%lf", &y);

	while(y != -1)
	{
        printf("%.1f\n", work(y));
		printf("%s", " Number digit, -1 to end:");
        scanf("%lf", &y);
	} 
}

double work(double x)
{
    return floor(x + 0.5);
}
