#include <stdio.h>

int myputs(const char *);

int main(void)
{
    printf("Получилось %d символов.\n", myputs("qwer"));
  
}


int myputs(const char * string)
{
    int count = 0;
    while (*string) 
    {
        putchar(*string++);
        count++;
        printf("count: %d\n", count);
    }
    putchar('\n'); 
    count++;
    return count;
}
