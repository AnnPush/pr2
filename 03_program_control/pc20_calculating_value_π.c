/*6 (Calculating the Value of π) Calculate the value of π from the infinite series
Print a table that shows the value of π approximated by one term of this series, by two terms, by
three terms, and so on. How many terms of this series do you have to use before you first get 3.14?
3.141? 3.1415? 3.14159?
*/

#include <stdio.h>

int main(void)
{
    float pi = 0;
    int flag = 1;
    int n = 0;
    int f1, f2, f3, f4;
    
    f1 = f2 = f3 = f4 = 0;
   
    for(int i = 1; i < 1000000; i += 2)
    {
        if(flag == 0)
        {
            pi -= 4/(float)i;
            flag = 1;
        }
        else
        {
            pi += 4/(float)i;
            flag = 0;
        }
        
        if(f1 == 0)
        {
        if(pi >= 3.14 && pi < 3.15)
        {
           printf("%d: %s\n", n, "3.14");
           
         f1++;
        }
        }
        if(f2 == 0)
        {
        if(pi >= 3.141 && pi < 3.142)
        {
           printf("%d: %.3f\n", n, pi); 
         f2++;
        }
        }
        if(f3 == 0)
        {
        if(pi >= 3.1415 && pi < 3.1416)
        {
           printf("%d: %.4f\n", n, pi);
         f3++;
        }
        }
        if(f4 == 0)
        {
        if(pi >= 3.14159 && pi < 3.14160)
        {
           printf("%d: %.5f\n", n, pi);
         f4++;
        }
        }
           n++;
    }
}
