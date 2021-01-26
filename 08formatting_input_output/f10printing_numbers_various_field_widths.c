#include <stdio.h>

int main(void)
{
	int x = 12345;
	float y = 1.2345;
	
	printf("x = %3d\n", x);
	printf("y = %3f\n", y);
	
	printf("x = %1d\n", x);
	printf("y = %1f\n", y);
	
	printf("x = %10d\n", x);
	printf("y = %10f\n", y);
}

/*
x = 12345                                                                                                                                                                          
y = 1.234500                                                                                                                                                                       
x = 12345                                                                                                                                                                          
y = 1.234500                                                                                                                                                                       
x =      12345                                                                                                                                                                     
y =   1.234500
*/
