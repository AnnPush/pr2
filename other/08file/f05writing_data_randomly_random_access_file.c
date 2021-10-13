#include <stdio.h>


struct clientData{
	int accNum;
	char lastName[15];
	char firstName[10];
	double balance;
};

int main(void)
{
	FILE* cfPtr;
	
	struct clientData client = {0, "", "", 0.0};
	
	if((cfPtr = fopen("credit.txt", "rb+")) == NULL)
	{
		printf("File could not be opened.\n");
	}
	else
	{
		printf("Enter account number"
		"(1 to 100, 0 to end input)\n?");
		scanf("%d", &client.accNum);
		
		while(client.accNum != 0)
		{
			printf("Enter lastname, firstname, balance\n?");
			
			fscanf(stdin, "%s%s%lf", client.lastName, client.firstName, &client.balance);
			
			fseek(cfPtr, (client.accNum - 1) * sizeof(struct clientData), SEEK_SET);
			
			fwrite(&client, sizeof(struct clientData), 1, cfPtr);
			
			printf("Enter account number\n?");
			scanf("%d", &client.accNum);
		}
		fclose(cfPtr);
	}
}
