/*Напишите программу, которая выводит таблицу двоичных,
восьмеричных и шестнадцатеричных эквивалентов десятичных
чисел в диапазоне  от 1 до 256.*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	int i, j, h, p;
	char hexx;
	int bin = 0;
	int oct = 0;
	int hex = 0;
	int dec;

	puts("Dec\t\tBin\t\tOct\t\tHex\n\n");

	for( i = 1; i <= 256; ++i)
	{
		dec = i;
		bin = 0;
		for(j = 0; dec > 0; j++)
        {
           bin += (dec % 2) * pow(10.0, j);
           dec /= 2;
        }
		printf("%d\t\t%d\t\t", i, bin);

		//______________________________

		dec = i;
		oct = 0;

		for(j = 0; dec > 0; j++)
        {
			oct += (dec % 8) * pow(10.0, j);
			dec /= 8;
		}
		printf("%d\t\t", oct);

		//______________________________
		
		dec = i;
		hex = 0;
		
		
		for(j = 0; dec > 0; j++)
        {
	         hex += (dec % 16 )* pow(10.0, j);
		     dec /= 16;
	    }
	    
		dec = i;
	    h = dec % 16;

		if(dec > 9 && dec < 16 || h > 9 && h < 16)
		{
		    if(dec > 9 && dec < 16)
			{
				p = dec;
			}
			else
			{
				p = h;
			}
			
			switch(p)
			{
				case 10:
				    hexx = 'A';
				    break;
				case 11:
					hexx = 'B';
					   break;
			    case 12:
					hexx = 'C';
					break;
				case 13:
					hexx = 'D';
					break;
				case 14:
					hexx = 'E';
					break;
				case 15:
					hexx = 'F';
					   break;
		    }
			
			if(dec > 9 && dec < 16)
			{
				printf("%c\n",  hexx);
			}
			else if(h > 9 && h < 16)
			{
                printf("%d%c\n", dec / 16, hexx);
			}
				
	    }
		else
		{	  
		     printf("%d\n", hex);
		}	   
	}
}
