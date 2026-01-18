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
	p=(customer *)malloc(sizeof(customer)*1);
	if(!p)
	{
		fprintf(stderr,"Error allocating neccesary memory!");
		exit(-1);
	}
	//Sunarhsh gia arxikopoihsh tou stigmiotupoy ths domhs 
	getData(p);
	//POINTER ORISMA GT THA ALLAXEI TA PERIEXOMENA!!!

	saveToFile( p);
	
	free(p);
	
	return 0;
}
void getData(customer *p)
{
	printf("Type customer's name:");
	scanf("%s",p->name); 	 //Xrhsh tou -> gia prospash sta dedoemna ths domhs suntomografia tou &(*p).name
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
	printf("\nData saved in file clinet.txt");
}
