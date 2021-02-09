#include <stdio.h>
#include <string.h>

#define SIZE 100

void printPigLatin(char *ptr);

int main(void)
{
   char arr[SIZE];  
   puts("Enter text: ");
   fgets(arr, SIZE, stdin);
   
   char *arrptr;

   printf("\nEnglish:  %s\n", arr);
   printf("Pig lating:  ");

   arrptr = strtok(arr, " ");
   
   while(arrptr != NULL) 
   {
      printPigLatin(arrptr);
      arrptr = strtok(NULL, " \n");
   }
}

void printPigLatin(char *ptr)
{
   char str[SIZE];

   strcpy(str, ++ptr);

   str[strlen(str) + 1] = '\0';
   str[strlen(str)] = *(--ptr);

   strcat(str, "ay");

   printf("%s ", str);
} 


