#include <stdio.h>

int main(void)
{
	int *ptr;
	int x = 12345;
	
	ptr = &x;
	printf("\n\nThe valuee of ptr is %p\n", ptr);
	printf("d = %d\n", ptr);
	printf("i = %i\n", ptr);
	printf("u = %u\n", ptr);
	printf("o = %o\n", ptr);
	printf("x = %x\n", ptr);
}

/*
The valuee of ptr is 0x7ffe27787e14                                                                                                                                                
d = 662208020                                                                                                                                                                      
i = 662208020                                                                                                                                                                      
u = 662208020                                                                                                                                                                      
o = 4736077024                                                                                                                                                                     
x = 27787e14    
*/
