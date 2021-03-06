/*Ханойская башня
итерация
Стержни пронумерованы от 0 до 2, диски - от 0 до n -1.
Требуется перенести башню со стержня 0 на стержень 2
*/

#include <stdio.h>
#include <math.h>

void f(int);

int main()
{
    int rings;

	printf("Enter rings:\n");
	scanf("%d", &rings);

    f(rings);
}

void f( int n) // n - число дисков, start -  стержень, с которого перемещаем диски, finish - стержень, на который перемещаем диски, tmp -промежуточный стержень.
{
	int i = 1; //номер хода
	int j; //номер диска от 0 до n - 1
	int p;//переменная для подсчета номера диска
	int t;//общее число переносов текущего диска
	int d;//четное или нечетное
	double  start;//с какого стержня переносится диск
	double finish;//на какой стержень переносится диск

	
	printf("______________________________________\n");
	printf("i\tdisk\tt\tstart\tfinish\n");
	printf("______________________________________\n");

	while(i <= pow(2.0, n) - 1) //до техпор пока номер хода меньше, чем общее количество необходимых перемещений
	{
		j = 0;
		p = i;
		// Определение номера перекладываемого диска = сколько раз номер хода делится на 2 без остатка
		while(p % 2 == 0)
		{
			++j;
			p /= 2;
		}
		
		printf("%d\t%d\t", i, j);

		t = (i - pow(2.0, j)) / pow(2.0, j + 1);//рассчитать общее число переносов текущего диска

		printf("%d\t", t);

		d = pow(-1.0, n - j);
		
        start = d * t % 3;
		finish = d * (t + 1) % 3;

		if( start < 0)
		{
		    start = 3 + start;
		}
		if( finish < 0)
	    {
		   finish = 3 + finish;
	    }

		printf("%.0f\t%.0f\n",  start, finish);

		++i;
	}
	 
}

