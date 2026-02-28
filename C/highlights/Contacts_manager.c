#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 80

typedef struct person{
	char *name;
	char *address;
	char *city_state;
	char  *phone_number;
}RECORD;

void read_record(RECORD *p);
void print_record(RECORD x,int n);
void init_record(RECORD *p);
void free_record(RECORD x);
void copy_record(RECORD *A,RECORD B);

int main()
{
	RECORD *records,x;
	int i,N,choice;
	char *ap[4];
	
	printf("Type number of records:");
	scanf("%d",&N);
	getchar();
	
	records=malloc(sizeof(RECORD)*N);
	if(!records)
	{
		printf("Failed to allocate memory");
		exit(0);
	}
	
	for(i=0;i<N;i++)
	init_record(&records[i]);
	init_record(&x);
	
	for(i=0;i<N;i++)
	{
	printf("%d-o atomo\n",i+1);	
	read_record(&records[i]);
     }
	  
     for(i=0;i<N;i++)
	 print_record(records[i],i);
	 printf("Epileske eggrafi gia antigrafi (0-%d):",N-1);
	 scanf("%d",&choice);
	 if(choice>=0&&choice<=N-1)
	 {
	 copy_record(&x,records[choice]);
	 printf("\nEktupwsi stigmiotupou:\n");
     printf("_________________________");
	 print_record(x,choice);
     }
	 
	for(i=0;i<N;i++)
	 free_record(records[i]);
    free_record(x);
    free(records);
	
	return 0;
}

void read_record(RECORD *p)
{
	printf("Name:");
    gets(p->name);   
	printf("Address:");
    gets(p->address);
    printf("Phone number:");
    gets(p->phone_number);
	printf("City state:");
	gets(p->city_state);
	putchar('\n');
	system("pause");

}

void print_record(RECORD x,int n)
{
	printf("\n %d record:\n",n+1);
	printf("Full name:");
	puts(x.name);
	printf("Address:");
	puts(x.address);
	printf("Phone number:");
	puts(x.phone_number);
	printf("City state:");
	puts(x.city_state);
	putchar('\n');
	
}

void init_record(RECORD *p)
{
	p->name=malloc(sizeof (char)*SIZE);
	if(!p->name)
	{
		printf("Failed to allocate memory for name");
		exit(0);
	}
	
	p->address=malloc(sizeof(char)*SIZE);
	if(!p->address)
	{
		printf("Failed to allocate memory for address");
		exit(0);
	}
	
	p->phone_number=malloc(sizeof(char)*SIZE);
		
	if(!p->phone_number)
	{
		printf("Failed to allocate memory for phone number");
		exit(0);
	}
	p->city_state=malloc(sizeof(char)*SIZE);
		if(!p->city_state)
	{
		printf("Failed to allocate memory for city state");
		exit(0);
	}

	
}

void free_record(RECORD x)
{
	free(x.name);
	free(x.address);
	free(x.phone_number);
	free(x.city_state);
}


void copy_record(RECORD *A, RECORD B)
{
	strcpy(A->name,B.name);
	strcpy(A->address,B.address);
	strcpy(A->phone_number,B.phone_number);
	strcpy(A->city_state,B.city_state);
}
