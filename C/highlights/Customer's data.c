#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct{
	char name[100];
	float amount;
}customer;

void getData(customer *p);
void saveToFile(customer *p);

int main()
{
	customer *p;
	//	Dynamic memory allocation for one customer structure
	p=(customer *)malloc(sizeof(customer)*1);
	if(!p)
	{
		fprintf(stderr,"Error allocating neccesary memory!");
		exit(-1);
	}
	//Funcion call to get data from user and save it in the structure that p points to
	getData(p);
	//careful: pointer as an argument because the variable's value is to be changed in the function and we want to save the changes in the main function
	saveToFile( p);
	
	free(p);
	
	return 0;
}

void getData(customer *p)
{
	printf("Type customer's name:");
	fgets(p->name, N, stdin); 	 //Using the -> operator to access the name field of the structure pointed to by p it is equal as (*p).name but it is more convenient and readable to use the -> operator when dealing with pointers to structures. 	
	printf("\nType owed amount:");
	scanf("%f",&p->amount);
}
void saveToFile(customer *p)
{
	FILE *fp;
	static int i=0;
	if(!(fp=fopen("client.txt","a")))
	{
		fprintf(stderr,"Error occured opening file!");
		exit(-1);
	}
	i++;
	fprintf(fp,"Client number %d ,%s owes %.2f",i,p->name,p->amount);
	fclose(fp);
	printf("\nData saved in file client.txt");
}
