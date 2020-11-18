//сумма_элементов_массива
#include <stdio.h>
#define SIZE 10

 int sum(const int b[], int p); 

 
 int main(void)
 {
 int x; 

 
int a[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

 x = sum(a, SIZE);

 printf("Result is %d\n", x);
 }

 
 int sum(const int b[], int p)
 {

 if (1 == p) {
 return b[0];
 } 
else { 

 return b[p - 1] + sum(b, p - 1);
 
 }
 } 
