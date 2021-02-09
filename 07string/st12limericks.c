#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define LIMS 5 //количество куплетов в стихотворении
#define WORDS 5 //количество слов(артиклей, глаголов.../* Words for string (article, noun, etc.) */
#define SIZE 35 //длина одной строки стихотворения

int main(void)
{
    int rloop;//случайное число
    int	rhymes[5] = { 0 };
    char tmp_s[SIZE];//временный массив
	char phrase[SIZE];//массив для предложения
    const char * tokp;//указатель на строку

    const char * const article = "the a one some any";//строка артиклей
    const char * const noun = "boy girl dog town car";//строка существительных
    const char * const verb = "drove jumped ran walked skipped";//строка глаголов
    const char * const preposition = "to from over under on";//строка предлогов

    const char * const string[6] = { article, noun, verb, preposition, article, noun};//массив указателей на строки

    srand( time(NULL) );

    for(int l = 0; l < LIMS; l++)//5 куплетов 
    { 
        for(int i = 0; i < 5; i++) //пять фраз
	    {
            for(int j = 0; j < 6; j++) //6 слов в каждой фразе
		    {
                //создать фразу
	            rloop = 1 + rand() % WORDS;//случайное слово в масииве глаголов, существительных...
                strcpy(tmp_s, string[j]);//скопировать указанную строку во временный массив
	            tokp = strtok(tmp_s, " ");//установить указатель на элемент временного массива
				
                for(int k = 0; k < rloop && tokp != NULL; k++) 
				{
	                if(!k) 
					{
	                    strcpy(tmp_s, string[j]);//скопировать указанную строку во временный массив
	                    tokp = strtok(tmp_s, " ");//установить указатель на элемент временного массива
	                }
	                else tokp = strtok(NULL, " ");//пошагово двигаемся к нужному слову строки

	                if(i && j == 5) 
					{
		                //проверить рифму
	                    for(int x = 0; x < 5; x++) 
						{
	                        if(!x) 
							{
                                strcpy(tmp_s, string[j]);//скопировать указанную строку во временный массив
		                        tokp = strtok(tmp_s, " ");//установить указатель на элемент временного массива
 	  	                    }
	   	                    else tokp = strtok(NULL, " ");//пошагово двигаемся к нужному слову строки

		                    //установить рифму
		                    if(i == 1) 
							{
		                        if(tokp[strlen(tokp) - 1] == rhymes[0])//вторая строка рифмуется с первой
							    {
		                            break;
		                        }
		                    }
		                    else if(i == 2) 
							{
			                    if(tokp[strlen(tokp) - 1] != rhymes[0])//третья строка не рефмуется с первой
			                        break;
		                    }
		                    else if(i == 3)
						    {
		                        if(tokp[strlen(tokp) - 1] == rhymes[2])//четвертая строка рифмуется с третьей
  		                            break;
		                    }
		                    else if(i == 4)
							{
		                        if(tokp[strlen(tokp) - 1] == rhymes[0])//пятая строка рифмуется с первой
			                        break;
		                    }

	                    }
	                }
	            }

                //добавить маркер в фразу
                if(!j)
	                strcpy(phrase, tokp);
	            else 
				{
	                strcat(phrase, tokp);
	            }
	            strcat(phrase, " ");
            }
            rhymes[i] = phrase[strlen(phrase) - 2];
            strcat(phrase, "\0"); //добавить ноль в конце строки

            phrase[0] = toupper((int)phrase[0]);//первое слово с большой буквы
            phrase[strlen(phrase) - 1] = '.';//в конце предложения поставить точку

            printf("%2d: %s\n", i + 1, phrase);//вывести строку стихотворения на печать
        }
        puts("");
    } 
}
