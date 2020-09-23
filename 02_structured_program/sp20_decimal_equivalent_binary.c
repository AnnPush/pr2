/*(Printing the Decimal Equivalent of a Binary Number) Input an integer (5 digits or fewer)
containing only 0s and 1s (i.e., a “binary” integer) and print its decimal equivalent. [Hint: Use the remainder
and division operators to pick off the “binary” number’s digits one at a time from right to left.
Just as in the decimal number system, in which the rightmost digit has a positional value of 1, and the
next digit left has a positional value of 10, then 100, then 1000, and so on, in the binary number system
the rightmost digit has a positional value of 1, the next digit left has a positional value of 2, then
4, then 8, and so on. Thus the decimal number 234 can be interpreted as 4 * 1 + 3 * 10 + 2 * 100.
The decimal equivalent of binary 1101 is 1 * 1 + 0 * 2 + 1 * 4 + 1 * 8 or 1 + 0 + 4 + 8 or 13.]*/

#include <stdio.h>

int main(void)
{
    int digit;
	int b = 1;
	int counter = 1;
	int x;
	int i = 1;
	int sum = 0;
	int c;
	int n = 1;

	printf("%s\n", "Enter digit:");
	scanf("%d", &digit);

	while(b != digit)
    {
        x = i*10;
        b = digit % x;
        c = b / i;
        sum += c * n;
        n *= 2;
        i *= 10;
    }
    printf("%d\n", sum);
}
