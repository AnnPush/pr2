#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define width 65
#define height 25

char mas[height][width + 1];

void init()
{
	int i;
	
	for(i = 0; i < width; i++)
		mas[0][i] = '#';
	
	mas[0][width] = '\0';
	
	for(i = 1; i < height; i++)
		strncpy(mas[i], mas[0], width + 1);
}

void show()
{
	int i;
	for(i = 0; i < height; i++)
	printf("%s\n", mas[i]);
}

int main(void)
{
	init();
	show();
}
