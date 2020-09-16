/*Диаметр, периметр и площадь круга

Write a program that reads in the radius of a circle and prints
the circle’s diameter, circumference and area. Use the constant
 value 3.14159 for π. Perform each of these calculations inside
the printf statement(s) and use the conversion specifier %f. */

#include <stdio.h>

int main(void)
{
	int r;

	printf("%s", "Enter radius: ");
	scanf("%d", &r);

	printf("Diameter:\n d = %d\nCircumference:\nP = %f\nArea:\nS = %f\n", 2 * r, 2 * 3.14159 * r, 3.14159 * r * r );
}
