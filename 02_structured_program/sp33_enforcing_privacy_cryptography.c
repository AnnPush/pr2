/*(Enforcing Privacy with Cryptography) The explosive growth of Internet communications
and data storage on Internet-connected computers has greatly increased privacy concerns. The field
of cryptography is concerned with coding data to make it difficult (and hopefully—with the most
advanced schemes—impossible) for unauthorized users to read. In this exercise you’ll investigate a
simple scheme for encrypting and decrypting data. A company that wants to send data over the Internet
has asked you to write a program that will encrypt it so that it may be transmitted more securely.
All the data is transmitted as four-digit integers. Your application should read a four-digit
integer entered by the user and encrypt it as follows: Replace each digit with the result of adding 7
to the digit and getting the remainder after dividing the new value by 10. Then swap the first digit
with the third, and swap the second digit with the fourth. Then print the encrypted integer.*/

#include <stdio.h>

int main(void)
{
    int number;
	int i = 10;
	int counter = 1;
	int new_digit;

	puts("Enter our-digit integer:");
	scanf("%d", &number);

	while(counter <= 4)
	{	
		if(counter == 2)
		{
			new_digit = (number % 10 + 7) %10;
			i = 1000;
		}
		else
		{
			new_digit = (number / i + 7) %10;
			if(counter == 3)
			{
				i  = 100;
			}			
		}
		printf("%d", new_digit);
		
		++counter;
	}
	puts("");
}
