#include <stdio.h>
#include <stdio.h>
#include <string.h>

char *s_gets(char *st, int n);

#define MAXTITL 41       /*максимальная длина названия*/
#define MAXAUTL 31       /*максимальная длина имени автора*/

struct book{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};                       //конец шаблона структуры

int main(void)
{
	struct book library; //объявление library в качестве переменной типа book
	
	puts("Enter title book:");
	s_gets(library.title, MAXTITL); //доступ к разделу названия книги
	
	puts("Enter author book:");
	s_gets(library.author, MAXAUTL);
	
	puts("Enter price book:");
	scanf("%f", &library.value);
	
	printf("%s author %s: $%.2f\n", library.title, library.author, library.value);
	printf("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find=strchr(st, '\n');//поиск новой строки
		if(find)//если адрес не равен NULL
		*find = '\0';//поместить туда нулевой символ
	else
	while(getchar()!='\n')
	continue;//отбросить остаток строки
	}
	return ret_val;
}
