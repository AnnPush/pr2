/*(Diameter, Circumference and Area of a Cirle) Write a program that reads the radius of a
circle (as a float value) and computes and prints the diameter, the circumference and the area. Use
the value 3.14159 for π.*/

#include <stdio.h>

int main(void)
{
	float r;
	float p = 3.14159;

	printf("%s\n", "Enter r:");
	scanf("%f", &r);
	
    printf("Diameter: %.2f\nCircumference: %.2f\nArea %.2f\n", 2 * r, 2 * p * r, p * r * r);
	
}
