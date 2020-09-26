/*(Calculating Weekly Pay) A company pays its employees as managers (who receive a fixed
weekly salary), hourly workers (who receive a fixed hourly wage for up to the first 40 hours they
work and “time-and-a-half”—i.e., 1.5 times their hourly wage—for overtime hours worked), commission
workers (who receive $250 plus 5.7% of their gross weekly sales), or pieceworkers (who receive
a fixed amount of money for each of the items they produce—each pieceworker in this
company works on only one type of item). Write a program to compute the weekly pay for each
employee. You do not know the number of employees in advance. Each type of employee has its
own pay code: Managers have paycode 1, hourly workers have code 2, commission workers have
code 3 and pieceworkers have code 4. Use a switch to compute each employee’s pay based on that
employee’s paycode. Within the switch, prompt the user (i.e., the payroll clerk) to enter the appropriate
facts your program needs to calculate each employee’s pay based on that employee’s paycode.
[Note: You can input values of type double using the conversion specifier %lf with scanf.]*/

#include <stdio.h>

int main(void)
{
    int code;
    float oplata = 0;
    int kol;
    int sverh;
    int i = 40;
    int det;
    
    puts("Enter code: 1 - managers, 2 - hourly workers, 3 - commission workers, 4 - pieceworkers");
        puts("Ctrl + Z exit");
    
    while((code=getchar()) != EOF)
    {
        
        
        switch(code)
        {
            case '1':
                puts("Enter weekly salary:");
                scanf("%f", &oplata);
                printf("Your weekly salary: %f", oplata);
                break;
            
            case '2':
                puts("Enter a fixed hourly wage:");
                scanf("%f", &oplata);
                puts("Enter counter hour:");
                scanf("%d", &kol);
                
                if(kol > 40)
                {
                   sverh = kol - i;
                   oplata = oplata * i + oplata * 1.5 *sverh;
                   printf("Your weekly wage: %f", oplata);
                }
                else
                {
                   oplata = oplata * (float)kol;
                   printf("Your weekly wage: %d", oplata);
                }
                break;
            
            case '3':
                puts("Enter gross weekly sales:");
                scanf("%f", &oplata);
                oplata = oplata*5.7/100 + 250;
                printf("Your weekly wage: %f", oplata);
                break;
            
            case '4':
                puts("Enter fixed amount of money:");
                scanf("%f", &oplata);
                
                puts("Enter kol_det:");
                scanf("%d", &det);
                
                oplata = oplata*(float)det;
                printf("Your weekly wage: %f", oplata);
                break;
            case '\n':
            case '\t':
            case ' ':
                break;
            default:
                puts ("Incorrect enter");
                break;
        }
    }
}
