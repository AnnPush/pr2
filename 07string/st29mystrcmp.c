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
/strcmp_array

#include <stdio.h>

int mystrcmp(const char *s1, const char *s2);

int main(void)
{
  
    printf("mystrcmp(\"abc\", \"abe\") = %d\n", mystrcmp("abc", "abe") );
    
}

int mystrcmp(const char *s1, const char *s2)
{
	int i = 0;

   while(( s1[i] != '\0' && s2[i] != '\0' ) && s1[i] == s2 [i])
	   i++;
    

    if(s1[i] == s2[i])
    {
        return 0; 
    }
    else
    {
        return s1[i] - s2[i];
    }
}


//strncmp
#include <stdio.h>

int mystrncmp(const char *s1, const char *s2, size_t n);

int main(void)
{
  
    printf("mystrncmp(\"abbbbc\", \"abbbbe\") = %d\n", mystrncmp("abbbbc", "abbbbe", 3) );
    
}

int mystrncmp(const char *s1, const char *s2, size_t n)
{
for(int i = 0; i < n && ( ( *s1 != '\0' && *s2 != '\0' ) && *s1 == *s2 ); ++i)
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

//strncmp_array

#include <stdio.h>

int mystrncmp(const char *s1, const char *s2, size_t n);

int main(void)
{
  
    printf("mystrncmp(\"abbbbc\", \"abbbbe\") = %d\n", mystrncmp("abbbbc", "abbbbe", 4) );
    
}

int mystrncmp(const char *s1, const char *s2, size_t n)
{
	
	int i = 0;

   while(i < n &&( s1[i] != '\0' && s2[i] != '\0' ) && s1[i] == s2 [i])
	   i++;


     if(s1[i] == s2[i])
    {
        return 0; 
    }
    else
    {
        return s1[i] - s2[i];
    }
}
