#include <stdio.h>
#include <math.h>
#define SIZE 10

void bucketSort(int b[][SIZE], int a[], int yy);
void printArray(int a[]);

int main(void)
{
	int array1[SIZE] = {123, 34, 85, 4, 95, 986, 71, 6, 543, 1234};//массив значений, которые нужно отсортировать
	int block[SIZE][SIZE];//вспомогательный массив для сортировки
	
	int max;//наибольшее число в массиве
	int y = 0;//количество разрядов в наибольшем числе массива
	
	printArray(array1);//вывести неотсортированный массив
	
	puts("");
	
	//поиск наибольшего элемента в массиве
	for(int k = 0; k < SIZE; ++k)
	{
		max = array1[0];
		if(array1[k] > max)
			max = array1[k];
	}
	//определить количество разрядов в наибольшем числе массива
	while(max % 10 != 0)
	{
	    max = (max - max % 10) / 10;
		y++;	
	}
	//вызвать функцию для блочной сортировки массива
	bucketSort(block, array1, y);
	//вывести отсортированный массив
	printArray(array1);
}
//функция печати массива
void printArray(int a[])
{
	for(int k = 0; k < SIZE; ++k)
	{
		printf("%d ", a[k]);
	}
}

//функция блочной сортировки
void bucketSort(int b[][SIZE], int  a[], int yy)
{
	int m = 0; //проход по разрядам чисел
	int t = 0; //разряд числа
	int p = 0; //переменная для отслеживания элементов основного массива
	
	while(m < yy)
	{
		//после каждого прохода обнулить все элементы вспомогательного массива
		for(int i = 0; i < SIZE; ++i)
	    {
	    	for(int j = 0; j < SIZE; ++j)
	        {
		       b[i][j] = 0;
		    }
	    }
	
	
	    for(int k = 0; k < SIZE; ++k)
	    {
	        //найти разряд числа
			if( m == 0)
	        {
	            t = a[k] % 10;
	        }
	        else
	        {
	           
			    t = (a[k] - a[k] % (int)pow(10.0, m )) / (int)pow(10.0, m ) % 10;
			   
	        }
	        
	        //поместить число в нужную ячейку вспомогательного массива
	        for(int i = 0; i < SIZE; ++i)
	        {
		        for(int j = 0; j < SIZE; ++j)
	            { 
			        if(t == i && j == k)
			        {
		                b[i][j] = a[k];
			        }
	        
	            }
	        }
	    }
	  
	p = 0;
	
	//перезапись чисел в основной массив на определенном этапе сортировки
	for(int i = 0; i < SIZE; ++i)
	{
		for(int j = 0; j < SIZE; ++j)
	    {
			if(b[i][j] != 0 )
			{
		       a[p] = b[i][j];
		       p++;
			}
	    }
	}
	
	m++;
		
	}
}
