#include <stdio.h>

int main(void)
{
	float f = 9876.12345;
	
	for(int i = 1; i <= 9; ++i)
	{
	    printf("%.*g\n", i, f);
	}
}

/*

1e+04                                                                                                                                                                              
9.9e+03                                                                                                                                                                            
9.88e+03                                                                                                                                                                           
9876                                                                                                                                                                               
9876.1                                                                                                                                                                             
9876.12                                                                                                                                                                            
9876.123                                                                                                                                                                           
9876.123                                                                                                                                                                           
9876.12305
*/
