/*(Prime Numbers) An integer is said to be prime if it’s divisible by only 1 and itself. For example,
2, 3, 5 and 7 are prime, but 4, 6, 8 and 9 are not.
a) Write a function that determines whether a number is prime.
b) Use this function in a program that determines and prints all the prime numbers between
1 and 10,000. How many of these 10,000 numbers do you really have to test before
being sure that you have found all the primes?
c) Initially you might think that n/2 is the upper limit for which you must test to see
whether a number is prime, but you need go only as high as the square root of n. Rewrite
the program, and run it both ways. Estimate the performance improvement.
*/

#include <stdio.h>
#include <math.h>
#include <time.h>

int isPrimeNumber(int);

int main()
{
    clock_t tic = clock();
    printf("%s\n", "PrimeNumbers: ");
    
    for(int i = 1; i <= 100; i++)
    {
        if(isPrimeNumber(i))
        printf("%d ", i );
    }
    
    clock_t toc = clock();

    printf("\nElapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
}

int isPrimeNumber(int number)
{
    if (number < 2)
    return 0;
    
    for(int i = 2; i <= sqrt((float)number); i++)
    {
            if(number%i == 0)
            {
                return 0;
            }
    }
     return 1;
}

/*
Если использовать в качестве верхнего предела для делителей, с которым нужно 
проверить простое число, n/2, то программа выполнится за 0,017208 секунд.
А если использовать квадратный корень из n, то выполнится программа за 0.001524 секунд. 
Это в 11 раз быстрее. Проверяют только делители от 2 до округленного значения 
квадратного корня (n). Объяснение этого принципа. Рассмотрим множители 100. 
100 = 1 × 100, 2 × 50, 4 × 25, 5 × 20, 10 × 10, 20 × 5, 25 × 4, 50 × 2, 100 × 1.
После пары множителей 10 × 10 все пары множителей повторяются 
(только множители в этих парах переставлены местами). 
Поэтому можно игнорировать делители числа n большие, чем квадратный корень (n).*/
