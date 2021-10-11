#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{
	char mas[10][21];
	int i;
	int x = 10, y = 5;
	char key;

	int cx, cy;

	int ax = 5, ay = 3;
	srand(time(NULL));

	do
	{
	sprintf(mas[0], "####################");
	for(i = 1; i < 9; i++)
	{
		sprintf(mas[i], "#                  #");
	}
	sprintf(mas[9], "####################");
	
	mas[y][x] = '@';
	mas[ay][ax] = '*';

	system("cls");

	for(i = 0; i < 10; i++)
	{
		printf("%s\n", mas[i]);
	}

	key = getch();
	cx = x;
	cy = y;

	if(key == 'w') y--;
	if(key == 's') y++;
	if(key == 'a') x--;
	if(key == 'd') x++;

	if(mas[y][x] == '#')
	{
		x = cx;
		y = cy;
	}

	if((x == ax) && (y == ay))
	{
		ax = rand() * 1.0 / RAND_MAX * 18 + 1;
		ay = rand() * 1.0 / RAND_MAX * 8 + 1;
	}
	}
	while(key != 'e');
}
