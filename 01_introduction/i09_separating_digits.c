/*(Separating Digits in an Integer) Write a program that inputs one five-digit number, separates
the number into its individual digits and prints the digits separated from one another by three
spaces each. [Hint: Use combinations of integer division and the remainder operation.] For example,
if the user types in 42139, the program should print */

#include <stdio.h>

int main(void)
{
	int a;
	int b;

	printf("Enter integer:\n");
	scanf("%d", &a);
	b = a % 10000;
	a = a / 10000;
	printf("%d   ", a);
	a = b % 1000;
	b = b / 1000;
	printf("%d   ", b);
	b = a % 100;
	a = a / 100;
	printf("%d   ", a);
	a = b % 10;
	b = b / 10;
	printf("%d   ", b);
	printf("%d   \n", a);
}
