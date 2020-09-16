/*(Integer Value of a Character) Here’s a peek ahead. In this chapter you learned about integers
and the type int. C can also represent uppercase letters, lowercase letters and a considerable
variety of special symbols. C uses small integers internally to represent each different character. The
set of characters a computer uses together with the corresponding integer representations for those
characters is called that computer’s character set. You can print the integer equivalent of uppercase
A, for example, by executing the statement
printf( "%d", 'A' );
Write a C program that prints the integer equivalents of some uppercase letters, lowercase letters,
digits and special symbols. As a minimum, determine the integer equivalents of the following:
ABCabc012$*+/ and the blank character.*/

#include <stdio.h>

int main(void)
{
	printf("\'A\' = %d\n\'B\' = %d\n\'C\' = %d\n\'a\' = %d\n\'b\' = %d\n\'c\' = %d\n\'0\' = %d\n", 'A', 'B', 'C', 'a', 'b', 'c', '0');
	printf("\'1\' = %d\n\'2\' = %d\n\'$\' = %d\n\'*\' = %d\n\'+\' = %d\n\'/\' = %d\n\' \' = %d\n", '1', '2', '$', '*', '+', '/', ' ');
}
