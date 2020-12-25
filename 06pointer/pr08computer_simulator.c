#include <stdio.h>
#include <stdlib.h>

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
	int instructionRegister = 0; //для хранения исполняемой команды
	int instructionCounter = 0; //хранит адрес следующей исполняемой команды
	int operationCode = 0; //переменная для хранения кода текущей исполняемой команды, т. е. левых двух цифр слова команды
	int operand = 0;//в переменной хранится адрес операнда текущей исполняемой команды(две правые цифры командного слова)
	int i;
	int err = 0;
	
	printf("*** Симплетрон приветствует вас! ***\n"
	  "*** Пожалуйста, введите вашу программу по одной команде ***\n"
	  "*** (или слову данных) за раз. Я буду выводить в качестве ***\n"
	  "*** подсказки текущий адрес и знак вопроса (?).  ***\n"
	  "*** Введенное вами слово будет размещено по указанному адресу. ***\n"
	  "*** Для прекращения ввода программы введите число -99999 ***\n");
	  
	for(i = 0; i < SIZE; ++i)
	{
		while(1)
		{
			printf("%.2d ??", i);
			scanf("%d", &memory[i]);
			  
			if(memory[i] == -99999)
			{
				memory[i] = 0;
				i = SIZE;
				break;
		    }
			if(checkword(memory[i], SIZE))
			{
			    printf("***Invalid instruction: %d\n", memory[i]);
				printf(***Please retype it or exit.\n");
			}
			else
				break;
		}
	}
	  
	printf("*** Program loading completed ***\n"
	  "*** Program execution begins ***\n");
	  
	for(i = 0; i < SIZE; ++i)
	{
		instructionRegister = memory[i];
		operationCode = instructionRegister / 100;
		operand = instructionRegister % 100;
		  
		if(operationCode >= BRANCH)
			--operand;
		  
		switch(operationCode)
		{
			case READ:
			printf("Insert a word: ");
			scanf("%d", &memory[operand]);
			break;
			  
			case  WRITE:
			printf(\nMemory location: %.2\nWord: %d\n ASCII: %c\n", operand, memory[operand], memory[operand]);
			break;
			  
			case LOAD:
			accumulator = memory[operand];
			break;
			  
			case: STORE:
			memory[operand] = accumulator;
			break;
			  
			case ADD:
			accumulator += memory[operand];
			if(accumulator > +99999 || accumulator < -99999)
				err = 1;
			break;
			  
			case SUBSTRACT:
			accumulator -= memory[operand];
			if(accumulator > +99999 || accumulator < -99999)
				err = 1;
			break;
			
			case MULTYPLY:
			accumulator *= memory[operand];
			if(accumulator > +99999 || accumulator < -99999)
				err = 1;
			break;
			
			case BRANCH:
			i = operand;
			break;
			
			case BRANCHNEG:
			if(accumulator < 0)
			i = operand;
			break;
			  
			case BRANCHZERO:
			if(!accumulator)
			i = operand;
			break;

			case HALT:
			printf("*** Simpletron execution terminated ***\n");
			dump(accumulator, i, memory);
			return 0;
			break;
			
			case 0:
			break;
			
			default:
			printf("*** Linknown error: %d\n", instructionRegister);
			exit(-1);
		}
		if(err)
		{
			switch(err)
			{
				case 1:
				printf("*** Out of the accumulator limit ***\n");
				break;
					
				case 2:
				printf("*** Attempt to divid by zero ***\n");
				break;
			}
			printf("*** Simpletron execution abnormally terminated ***\n");
			dump(accumulator, i, memory);
			exit(-1);
		}
	}
    dump(accumulator, i, memory);
    return 0;
}

int checkword(int word, int size)
{
	if(word < 0 || word > 9999 || word % 100 >= size)
	{
		return 1;
	}
	switch(word / 100)
	{
		
	}
}
