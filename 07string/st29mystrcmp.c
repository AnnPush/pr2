#include<stdio.h>

int mystrcmp(const char *s1, const char *s2);

int main(void)
{
  
    printf("strcmp(\"abc\", \"abe\") = %d\n", mystrcmp("abc", "abe") );
    
}

int mystrcmp(const char *s1, const char *s2)
{

    while( ( *s1 != '\0' && *s2 != '\0' ) && *s1 == *s2 )
    {
        s1++;
        s2++;
    }

    if(*s1 == *s2)
    {
        return 0; 
    }
    else
    {
        return *s1 - *s2;
    }
}
