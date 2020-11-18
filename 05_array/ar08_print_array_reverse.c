#include <stdio.h>
#define SIZE 10

// function prototype
 void someFunction(const int b[], size_t startIndex, size_t size);

 // function main begins program execution
 int main(void)
 {
 int a[SIZE] = { 8, 3, 1, 2, 6, 0, 9, 7, 4, 5 }; // initialize a

 puts("Answer is:");
 someFunction(a, 0, SIZE);
 puts("");
}

 // What does this function do?
 void someFunction(const int b[], size_t startIndex, size_t size)
 {
 if (startIndex < size) {
 someFunction(b, startIndex + 1, size);
 printf("%d ", b[startIndex]);
 }
 } 
