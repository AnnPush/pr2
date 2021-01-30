#include <stdio.h>

int main(void)
{
	float a, b, c;
   
    puts("Enter the value 1.2345 three times:" );
    scanf("%e%f%g", &a, &b, &c);
    
    puts("\nPrintf with %e:" );
	printf("%e %e %e\n", a, b, c);
	
	puts("\nPrintf with %f:" );
	printf("%f %f %f\n", a, b, c);
	
	puts("\nPrintf with %g:" );
	printf("%g %g %g\n", a, b, c);
	
}

/*
Enter the value 1.2345 three times:                                                                                                                                                  
1.2345 1.2345 1.2345                                                                                                                                                                 
                                                                                                                                                                                     
Printf with %e:                                                                                                                                                                      
1.234500e+00 1.234500e+00 1.234500e+00                                                                                                                                               
                                                                                                                                                                                     
Printf with %f:                                                                                                                                                                      
1.234500 1.234500 1.234500                                                                                                                                                           
                                                                                                                                                                                     
Printf with %g:                                                                                                                                                                      
1.2345 1.2345 1.2345 
*/
