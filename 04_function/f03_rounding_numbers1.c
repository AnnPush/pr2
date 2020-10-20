#include <stdio.h>
#include <math.h>

float roundtoInteger(float);
float roundtoTenths(float);
float roundtoHundreths(float);
float roundtoThousandths(float);

int main()
{
    float number;
    
    printf("Enter number:");
    scanf("%f", &number);
    
    printf("%.0f\n", roundtoInteger(number));
    printf("%.1f\n", roundtoTenths(number));
    printf("%.2f\n", roundtoHundreths(number));
    printf("%.3f\n", roundtoThousandths(number));
}

float roundtoInteger(float integers)
{
    return floor(integers*1+.5)/1;
}
float roundtoTenths(float tenths)
{
    return floor(tenths*10+.5)/10;
}
float roundtoHundreths(float hundreths)
{
    return floor(hundreths*100+.5)/100;
}
float roundtoThousandths(float thousandths)
{
    return floor(thousandths*1000+.5)/1000;
}
