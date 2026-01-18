#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef struct{
	char name[100];
	float amount;
}customer;

void getData(customer *p );
void saveToFile(customer *p, int c);
void readFromFile();

int main()
{
	customer *p;
	int c=0;
	int i;
	printf("Type number of customers to add?\n");
	scanf("%d",&c);
	p=(customer *)malloc(sizeof(customer)*c);
	if(!p)
	{
		fprintf(stderr,"Error allocating neccesary memory!");
		exit(-1);
	}
	//Sunarhsh gia arxikopoihsh tou stigmiotupoy ths domhs 
	if(c!=0)
	{
	for( i=0 ; i<c; i++)
	getData(p+i);
	//POINTER ORISMA GT THA ALLAXEI TA PERIEXOMENA!!!
	saveToFile(p,c);
	}
	printf("\nAlready added:\n");
	readFromFile();
	free(p);
	
	return 0;
}
void getData(customer *p)
{
		getchar();
		printf("Type customer's name:");
		fgets(p->name,N,stdin);
		p->name[strcspn(p->name,"\n")]='\0'; 	 //Xrhsh tou -> gia prospash sta dedoemna ths domhs suntomografia tou &(*p).name
		printf("\nType owed amount:");
		scanf("%f",&p->amount);
		
		
}
void saveToFile(customer *p, int c)
{
	FILE *fp;
	int i;
	static int cnt=0;
	if(!(fp=fopen("client.txt","a")))
	{
		fprintf(stderr,"Error occured opening file!");
		exit(-1);
	}
	
	for( i =0 ; i<c;  i++){
		cnt++;
	fprintf(fp,"Client number %d ,%s owes %.2f$\n",cnt,p[i].name,p[i].amount);
	}
	fclose(fp);
	printf("\nData saved in file client.txt");
}

void readFromFile()
{
	FILE *fp;
	char name[100];
	char line[200];
	float amt;
	
	if(!(fp=fopen("client.txt","r")))
	{
		fprintf(stderr,"Error opening File!");
		exit(1);
	}
	
	while((fgets(line,sizeof(line),fp))!=NULL)
	{
			printf("%s",line);
	}
	fclose(fp);
}
