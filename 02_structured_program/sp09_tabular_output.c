/*(Tabular Output) Write a program that uses looping to print the following table of values.
Use the tab escape sequence, \t, in the printf statement to separate the columns with tabs. 

N 10*N 100*N 1000*N
1 10 100 1000
2 20 200 2000
3 30 300 3000
4 40 400 4000
5 50 500 5000
6 60 600 6000
7 70 700 7000
8 80 800 8000
9 90 900 9000
10 100 1000 10000
*/

#include <stdio.h>

int main(void)
{
	int a = 1;

	printf("N\t\t10 * N\t\t100 * N\t\t1000 * N\n\n");

	while( a <= 10)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\n", a, a * 10, a * 100, a * 1000);
		a++;
	}
}
