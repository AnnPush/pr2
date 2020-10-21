/*(Displaying a Square of Any Character) Modify the function created in Exercise 5.19 to
form the square out of whatever character is contained in character parameter fillCharacter. Thus
if side is 5 and fillCharacter is “#”, then this function should print: */

#include <stdio.h>

void isSquare(int, char);

int main(void)
{
    int number;
	char fillCharacter;

	printf("%s", "Enter fillCharacter:\n");
    scanf("%c", &fillCharacter);

    printf("%s","Enter number:\n");
    scanf("%d", &number);

    
    
    isSquare(number, fillCharacter);
}

void isSquare(int n, char fillChar)
{
	int i, j;
    for( i = 1; i <= n; i ++)
    {
        for( j = 1; j <= n; j ++)
        {
            if(j == n)
            printf("%c\n", fillChar);
            else
            printf("%c", fillChar);
        }
    }    
        
}
