#include <stdio.h>

int main(void)
{
	int a, b, c, d, f;
    
    puts("Enter a number 437 five times:" );
    scanf("%d%i%o%u%x", &a, &b, &c, &d, &f);
    
    
    puts("\nPrintf with %d:" );
	printf("%d %d %d %d %d\n", a, b, c, d, f);
	
	puts("\nPrintf with %i:" );
	printf("%i %i %i %i %i\n", a, b, c, d, f);
	
	puts("\nPrintf with %o:" );
	printf("%o %o %o %o %o\n", a, b, c, d, f);
	
	puts("\nPrintf with %u:" );
	printf("%u %u %u %u %u\n", a, b, c, d, f);
	
	puts("\nPrintf with %x:" );
	printf("%x %x %x %x %x\n", a, b, c, d, f);
}

/*
Enter a number 437 five times:                                                                                                                                                       
437 437 437 437 437                                                                                                                                                                  
                                                                                                                                                                                     
Printf with %d:                                                                                                                                                                      
437 437 287 437 1079                                                                                                                                                                 
                                                                                                                                                                                     
Printf with %i:                                                                                                                                                                      
437 437 287 437 1079                                                                                                                                                                 
                                                                                                                                                                                     
Printf with %o:                                                                                                                                                                      
665 665 437 665 2067                                                                                                                                                                 
                                                                                                                                                                                     
Printf with %u:                                                                                                                                                                      
437 437 287 437 1079                                                                                                                                                                 
                                                                                                                                                                                     
Printf with %x:                                                                                                                                                                      
1b5 1b5 11f 1b5 437 
*/
