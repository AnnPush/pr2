#include <stdio.h>
#include <stdlib.h>

struct listNode{
	char data; //каждая структура содержит единицу данных
	struct listNode* nextPtr;//указатель на следующий узел
};

typedef struct listNode ListNode;//синоним listNode
typedef ListNode* ListNodePtr;//синоним ListNode

void insert(ListNodePtr* sPtr, char value);//вставить в список новое значение в сортированном порядке
char deletef(ListNodePtr* sPtr, char value);//удалить элемент из списка
int isEmpty(ListNodePtr sPtr);//возвратить 1, если список пуст, и 0 в противном случае
void printList(ListNodePtr currentPtr);//распечатать список
void instructions(void);//вывести меню

int main(void)
{
	ListNodePtr startPtr = NULL;//вначале узлов нет
	int choice;//выбор пользователя
	char item;//введенный пользователем символ
	
	instructions();//вывести меню
	printf("?");
	scanf("%d", &choice);
	
	while(choice != 3)
	{
		switch(choice)
		{
			case 1:
			printf("Enter a character:");
			scanf("\n%c", &item);
			insert(&startPtr, item);//вставить элемент в списокprintfList(startPtr);
			printList(startPtr);
			break;
			
			case 2:
			//если список не пуст
			if(!isEmpty(startPtr)){
				printf("Enter character to be deleted:");
				scanf("\n%c", &item);
				//если символ найден, удалить его
				if(deletef(&startPtr, item)){//удалить элемент
					printf("%c deleted.\n", item);
					printList(startPtr);
				}
				else{
					printf("%c not found.\n\n", item);
				}
			}
			else{
				printf("List is empty.\n\n");
			}
			break;
			
			default:
			printf("Invalid choice.\n\n");
			instructions();
			break;
		}
		printf("?");
		scanf("%d", &choice);
	}
	printf("End of run.\n");
}

//вывести меню
void instructions()
{
	printf("Enter your choice:\n"
	"   1 to insert an element into the list.\n"
	"   2 to delete an element from the list.\n"
	"   3 to end.\n");
}
//вставить в список новое значение в сортированном порядке
void insert(ListNodePtr* sPtr, char value)
{
	ListNodePtr newPtr;
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	
	newPtr = malloc(sizeof(ListNode));//создать узел
	
	if(newPtr != NULL){//если есть место
		newPtr -> data = value;//поместить в узел значение
		newPtr -> nextPtr = NULL;//узел не связан с другим узлом
		
		previousPtr = NULL;
		currentPtr = *sPtr;
		
		//цикл для поиска новой позиции в списке
		while(currentPtr != NULL && value > currentPtr -> data){
			previousPtr = currentPtr;//перейти к ...
			currentPtr = currentPtr -> nextPtr;//...следующему узлу
		}
		
		//вставить новый узел в начало списка
		if(previousPtr == NULL){
		newPtr -> nextPtr = *sPtr;
		*sPtr = newPtr;
		}
		else{//вставить новый узел между previousPtr и currentPtr
		previousPtr -> nextPtr = newPtr;
		newPtr -> nextPtr = currentPtr;
		}
	}
	else{
		printf("%c not inserted/ No memory available.\n", value);
	}
}

//удалить элемент списка
char deletef(ListNodePtr* sPtr, char value)
{
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	ListNodePtr tempPtr;
	
	//удалить первый узел
	if(value == (*sPtr) -> data){
	tempPtr = *sPtr;//удержать удаляемый узел
	*sPtr = (*sPtr) -> nextPtr;//отсоединить узел
	free(tempPtr);//освободить отсоединенный узел
	return value;	
	}
	else{
		previousPtr =  *sPtr;
		currentPtr = (*sPtr) -> nextPtr;
		
		//цикл для поиска нужной позиции в списке
		while(currentPtr != NULL && currentPtr -> data != value){
			previousPtr = currentPtr;//перейти к ...
			currentPtr = currentPtr -> nextPtr;//...следующему узлу
		}
		
		//удалить узел в currentPtr
		if(currentPtr != NULL){
			tempPtr = currentPtr;
			previousPtr -> nextPtr = currentPtr -> nextPtr;
			free(tempPtr);
			return value;
		}
	}
}
//возвратить 1, если список пуст, и 0 в противном случае
int isEmpty(ListNodePtr sPtr){
	return sPtr == NULL;
}

//распечатать список
void printList(ListNodePtr currentPtr)
{
	if(currentPtr == NULL){
				printf("List is empty.\n\n");
	}
	else{
		printf("The list is:\n");
		
		while(currentPtr != NULL)
		{
			printf("%c -->", currentPtr -> data);
			currentPtr = currentPtr -> nextPtr;
		}
		printf("NULL\n\n");
	}
}
