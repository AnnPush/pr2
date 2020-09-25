/*Assume i = 1, j = 2, k = 3 and m = 2. What does each of the following statements print?
a) printf("%d", i == 1);
b) printf("%d", j == 3);
c) printf("%d", i >= 1 && j < 4);
d) printf("%d", m < = 99 && k < m);
e) printf("%d", j >= i || k == m);
f) printf("%d", k + m < j || 3 - j >= k);
g) printf("%d", !m);
h) printf("%d", !(j - m));
i) printf("%d", !(k > m));
j) printf("%d", !(j > k));

*/

#include <stdio.h>

int main(void)
{
   int i = 1;
   printf("%d\n", i == 1);
   
   int j = 2;
   printf("%d\n", j == 3);
   
   printf("%d\n", i >= 1 && j < 4);
   
   int k = 3;
   int m = 2;
   
   printf("%d\n", m <= 99 && k < m);
   
   printf("%d\n", j >=i || k == m);
   
   printf("%d\n", k + m < j || 3 - j >= k);
   
   printf("%d\n", !m);
   
   printf("%d\n", !(j-m));
   
   printf("%d\n", !(k>m));
   
   printf("%d\n", !(j>m));  
}
