/*(Table of Decimal, Binary, Octal and Hexadecimal Equivalents) Write a program that
prints a table of the binary, octal and hexadecimal equivalents of the decimal numbers
in the range 1 through 256. If you’re not familiar with these number systems, read 
Appendix C before you attempt this exercise. [Note: You can display an integer as 
an octal or hexadecimal value with the conversion specifiers %o and %X, respectively.]
*/

#include <stdio.h>

int main(void)
{
    int ost;
    
    printf("%12s %12s %12s %18s\n", "Decimal", "Binary", "Octal", "Hexadecimal");
    for (int i = 1; i <= 256; i++)
    {
        ost = i;
        printf("%6d", i);
        printf("\t\t%s", " ");
        
        if(i == 256)
        {
            ost = ost % 128;
            printf("%s", "1");
        }
        
        if(i < 256 && i >= 128 || ost >= 128)
        {
            ost = ost % 128;
            printf("%s", "1");
        }
        else
        {
            printf("%s", "0");
        }
        
        if(i >= 64 && i < 128 || ost >= 64)
        {
            ost = ost % 64;
            printf("%s", "1");
        }
        else
        {
            printf("%s", "0");
        }
        
        if(i >= 32 && i < 64 || ost >= 32)
        {
            ost = ost % 32;
            printf("%s", "1");
        }
        else
        {
            printf("%s", "0");
        }
        
        if(i >= 16 && i < 32 ||ost >= 16)
        {
            ost = ost % 16;
            printf("%s", "1");
        }
        else
        {
            printf("%s", "0");
        }
        
        if(i >= 8 && i < 16 || ost >= 8)
        {
            ost = ost % 8;
            printf("%s", "1");
        }
        else
        {
            printf("%s", "0");
        }
        
        if(i >= 4 && i < 8 || ost >= 4)
        {
            ost = ost % 4;
            printf("%s", "1");
        }
        else
        {
            printf("%s", "0");
        }
        
        if(i >= 2 && i < 4 || ost >= 2)
        {
            ost = ost % 2;
            printf("%s", "1");
        }
        
        else
        {
            printf("%s", "0");
        }
        if(ost == 1)
        {
            printf("%s", "1");
        }
        else
        {
            printf("%s", "0");
        }
        
        printf("\t\t%s%o\t\t%X", " ", i, i);
        
        printf("%s", "\n");
    }
    
}
