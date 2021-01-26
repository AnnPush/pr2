#include <stdio.h>
#include <string.h>

int main(void)
{
	char y[20];
	
	//scanf("%s", y);
	fgets(y, 20, stdin);
	int n = strlen(y);
	printf("n = %d\n%*s\n", n, 2 * n, y);

}

/*
asd fg                                                                                                                                                                             
n = 7                                                                                                                                                                              
       asd fg 
*/
