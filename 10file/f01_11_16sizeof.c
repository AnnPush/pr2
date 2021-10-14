#include <stdio.h>

int main(void)
{
   FILE *fd;

   if( (fd = fopen("datasize.txt", "w")) == NULL) {
      printf("File could not opened\n");
   }

   fprintf(fd, "%-24s%4s\n\n", "Data type", "Size");
   fprintf(fd, "%-24s%4d\n", "char", sizeof(char));
   fprintf(fd, "%-24s%4d\n", "unsigned char", sizeof(unsigned char));
   fprintf(fd, "%-24s%4d\n", "short int", sizeof(short int));
   fprintf(fd, "%-24s%4d\n", "unsigned short int", sizeof(unsigned short int));
   fprintf(fd, "%-24s%4d\n", "int", sizeof(int));
   fprintf(fd, "%-24s%4d\n", "unsigned int", sizeof(unsigned int));
   fprintf(fd, "%-24s%4d\n", "long int", sizeof(long int));
   fprintf(fd, "%-24s%4d\n", "unsigned long int", sizeof(unsigned long int));
   fprintf(fd, "%-24s%4d\n", "float", sizeof(float));
   fprintf(fd, "%-24s%4d\n", "double", sizeof(double));
   fprintf(fd, "%-24s%4d\n", "long double", sizeof(long double));
} 
