#include <stdio.h>

#define SIZE 100

#define READ 10
#define WRITE 11

#define LOAD 20
#define STORE 21

#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTYPLY 33

#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

int checkword(int word, int size);
void dump(int acc, int icounter, int mem[]);

int main(void)
{
	int memory[SIZE] = {0};//модель памяти в качестве одномерного массива из 100 элементов
	int accumulator = 0;//представляет аккумулятор
	int instructionCounter = 0; //хранит адрес следующей исполняемой команды
	
	printf("*** Симплетрон приветствует вас! ***\n"
	  "*** Пожалуйста, введите вашу программу по одной команде ***\n"
	  "*** (или слову данных) за раз. Я буду выводить в качестве ***\n"
	  "*** подсказки текущий адрес и знак вопроса (?).  ***\n"
	  "*** Введенное вами слово будет размещено по указанному адресу. ***\n"
	  "*** Для прекращения ввода программы введите число -99999 ***\n");
}
