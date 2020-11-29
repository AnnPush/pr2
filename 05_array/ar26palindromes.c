#include <stdio.h>
#define SIZE 100
#define SIZE2 8

int testPalindrome(char str[], int start, int end);

int main(void)
{
	char string1[SIZE];
	char string[SIZE];
	char p[SIZE2] = {' ', ',', '.', '!', '?', ':', '-','\0'};
	int n = 0;
	int i, count = 0;

	int result;
    
    printf("%s","Enter a string:\n");
    fgets(string1, SIZE, stdin);
    fflush(stdin);
    
    
   
    for( i = 0; i < SIZE && string1[i] != '\0'; i++)
    {
		for (int j = 0; j < SIZE2 && p[j] != '\0'; ++j)
		{		  
             if( string1[i] == p[j])
			 {
               count++;
			 }
               
		}
		if(count == 0)
		{
		    string[n] = string1[i];
            printf("%c", string[n]);
            ++n;			
		}
		count = 0;
	}
    //убираем последний нулевой символ из строки, чтобы функция не сравнивала его со значением
    n = n -1;
     
	printf("\nN:%d\n", n);

    result = testPalindrome(string, 0, n - 1);

    if( result == 1)
    printf("Palindrome\n");
    else
    printf("Not palindrome\n");
}

int testPalindrome(char str[], int start, int end)
{
  
    if(end == 0)
    return 1;
    else if(start == end)
    return 1;
    
    if(str[start] != str[end])
    return 0;
    
    if(start < end + 1)
    return testPalindrome(str, start + 1, end - 1);
    
    return 1;
}
