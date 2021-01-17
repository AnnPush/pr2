#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define PHRASES 20
#define SIZE 30

int main(void)
{
	int i, j, k;
	char temp_arr[SIZE];
	char phrase[SIZE];
	const char *ptr_st;
	
	const char *const article = "the a one some any";
	const char *const noun = "boy girl dog town car";
	const char *const verb = "drove jumped ran walked skipped";
	const char *const preposition = "to from over under on";
	
	const char *const string[6] = {article, noun, verb, preposition, article, noun};
	
	srand(time(NULL));
	
	for(i = 0; i < PHRASES; ++i)
	{
		for(j = 0; j < 6; ++j)
		{
			strcpy(temp_arr, string[j]);
			ptr_st = strtok(temp_arr, " ");
			for(k = rand()%5; k && ptr_st != NULL; --k)
				ptr_st = strtok(NULL, " ");
			if(!j)
				strcpy(phrase, ptr_st);
			else
				strcat(phrase, ptr_st);
			strcat(phrase, " ");
		}
		strcat(phrase, "\0");
		phrase[0] = toupper((int)phrase[0]);
		phrase[strlen(phrase) - 1] = '.';
		printf("%2d: %s\n", i + 1, phrase);
	}
}
