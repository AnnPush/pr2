#include <stdio.h>

int integerPower(int, unsigned int);

int main()
{
    int base;
	unsigned int exponent;
    
    puts("Enter base:");
    scanf("%d", &base);
    
    puts("Enter exponent:");
    scanf("%u", &exponent);
    
    if(exponent <= 0)
    {
        puts("Error");
    }
    else
    {
        printf("Result: %d\n", integerPower(base, exponent));
    }
}    

int integerPower(int b, unsigned int e)
{
    int p = 1;
	int i;
        
    for( i = 1; i <= e; i++)
    {
        p *= b;
    }
     return p;
}
