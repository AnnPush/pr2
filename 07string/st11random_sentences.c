#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define SIZE 35 //длина одного предложения
#define SENTENCES 20 //количество предложений, которые нужно вывести

int main(void)
{
	int i, j, k;
	char temparr[SIZE];//временный массив
	char sentence[SIZE];//массив для предложения
	const char *stptr;//указатель на строку
	
	const char *const article = "the a one some any";//строка артиклей
	const char *const noun = "boy girl dog town car";//строка существительных
	const char *const verb = "drove jumped ran walked skipped";//строка глаголов
	const char *const preposition = "to from over under on";//строка предлогов
	
	const char *const string[6] = {article, noun, verb, preposition, article, noun};//массив указателей на строки
	
	srand(time(NULL));
	
	for(i = 0; i < SENTENCES; ++i)//вывести 20 фраз
	{
		for(j = 0; j < 6; ++j)//фраза состоит из 6 слов
		{
			strcpy(temparr, string[j]);//скопировать указанную строку во временный массив
			
			stptr = strtok(temparr, " ");//установить указатель на первый элемент временного массива
			
			for(k = rand()%5; k && stptr != NULL; --k)//получаем случайное чисо от 0 до 5
				stptr = strtok(NULL, " ");//пошагово двигаемся к нужному слову строки
			
			if(!j)//если это первое слово
				strcpy(sentence, stptr);//скопировать его в массив для предложения
			else
				strcat(sentence, stptr);//объединить слово с уже существующей записью в массиве
			strcat(sentence, " ");//объединить пробел с уже существующей записью в массиве
		}
		strcat(sentence, "\0");//добавить нуль-символ в конец предложения
		sentence[0] = toupper((int)sentence[0]);//первая буква заглавная
		sentence[strlen(sentence) - 1] = '.';//последний пробел заменить точкой
		printf("%2d: %s\n", i + 1, sentence);//вывести готовое предложение
	}
}
