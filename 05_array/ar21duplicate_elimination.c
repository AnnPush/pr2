#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int main()
{
    int num[SIZE];
    int duplicate[SIZE];
    int i,j,k,count=0;
	int t = 0;
	
	srand(time(NULL));
	
	printf("\n%s\n", "Array: ");
    for(i = 0; i < SIZE; i++)
    {
        num[i] = rand() % SIZE;
		printf("%d  ", num[i]);
		
    }
	puts("");
  
    for(i = 0;i < SIZE;i++)
    {
        for(j=0;j<i;j++)
        {
            int test=0;
            if(num[ i ] == num[ j ]) 
            {
                for(k=0;k<count;k++) 
                {
                    if(duplicate[ k ] == num[ i ])
                    test=1;
                }
                if(test==0)
                {
                    duplicate[ count ] = num[ i ];
                    count++;
                }
            }
        }
    }
	printf("\n%s\n", "New array: ");
	
	 for(i=0;i<SIZE;i++)
    {
		for(j=0;j<count;j++)
        {
		    if(num[i] == duplicate[ j ])
			t++;   
	    }
	    if( t == 0)
	    {
		    printf("%d  ",num[ i ]);	    
	    }
		t = 0;
    }
}
