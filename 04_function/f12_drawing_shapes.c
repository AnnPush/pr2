#include <stdio.h>

void isRectSquare( char);
void isTriangle( char);

int main()
{
    int var;
	char fillCharacter;

    printf("%s", "Enter fillCharacter:\n");
    scanf("%c", &fillCharacter);
    
	printf("%s", "Enter Square - 1:\nEnter Rectangle - 2:\nEnter Triangle - 3:\n");
	scanf("%d", &var);

    switch(var)
	{
		case 1:
		case 2:
			isRectSquare(fillCharacter);
		    break;
		case 3:
			isTriangle(fillCharacter);
			break;
		case '\n':
		case ' ':
		case '\t':
		    break;
		default:
		    printf("%s", "Incorrect letter entered./\nEnter a new integer.\n");
		    break;
		
	}
}

void isRectSquare( char fillChar)
{
    int side1;
    int side2;
    
	printf("%s","Enter side1 and side2:");
	scanf("%d%d", &side1, &side2);

    for(int i = 1; i <= side1; i ++)
    {
        for(int j = 1; j <= side2; j ++)
        {
            if(j == side2)
            printf("%c\n", fillChar);
            else
            printf("%c", fillChar);
        }
    }  
}

void isTriangle( char fillChar)
{
	int height;
	
	printf("%s","Enter height:");
	scanf("%d", &height);

    for(int i = 1; i <= height; i ++)
    {
        for(int j = 1; j <= height - i; j ++)
        {
            printf("%s", " ");
        }
        
        for(int j = 1; j <= i*2 - 1; j ++)
        {
            printf("%c", fillChar);
        }
        printf("%s", "\n");
    }    
        
}
