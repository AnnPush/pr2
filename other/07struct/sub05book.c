#include <stdio.h>
#include <string.h>

char *s_gets(char *st, int n);

#define MAXTITL 41       /*максимальная длина названия*/
#define MAXAUTL 31       /*максимальная длина имени автора*/

struct book{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};                       //конец шаблона стуктуры

int main(void)
{
	struct book library; //объявление library в качестве переменной типа book
	
	puts("Enter title book:");
	s_gets(library.title, MAXTITL); //доступ к разделу названия книги
	
	puts("Enter author book:");
	s_gets(library.author, MAXAUTL);
	
	puts("Enter price book:");
	scanf("%f", &library.value);
	
	
}
