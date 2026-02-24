#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 50
//1.
typedef struct{
	char name[N];
	float bathmos;
	float apoklish;
}Student;

void getData(Student *p , int n);	
void calculateStats(Student *p , int n, char * max_name);
float FindAverage(Student *p ,int n);
int main()
{
	//2.
	float mo=0.0;
	char max_name[N];
	int M;
	do{
	printf("Dwse plithos foithtwn:");
	scanf("%d",&M);
	}while(M<=0);
	
	Student *p;
	p=(Student *)malloc(M*sizeof(Student));
	if(!p)
	{
		fprintf(stderr,"Error allocating!");
		exit(-1);
	}
	//3.
		printf("\nEisagogh dedomenwn:\n");
		getData( p , M);
		
	
		calculateStats(p,  M, max_name );
		
		mo=FindAverage( p, M);
		
		FILE *fp;
		if(!(fp=fopen("results.dat","a")))
		{
			fprintf(stderr,"Error opening new file!");
			exit(-1);
		}
		fprintf(fp,"\nO mesos oros ths taxhs einai:%.2f . O foithths me to megalutero bathmo einai:%s", mo,max_name );
		fclose(fp);
			int i;
			
			free(p);		
	return 0;
	
}
void calculateStats (Student *p , int n ,char *max_name)
{
	int i;
	float max=-1.0;
	char new_max[N];
	for( i =0; i<n; i++)
	{
		 p[i].apoklish=fabs( p[i].bathmos-5.0);
		if( p[i].bathmos>max)
		{
			max= p[i].bathmos;
			strcpy(new_max, p[i].name);
		}
	}
		strcpy(max_name,new_max);
	
		
}
void getData(Student *p , int n)
{
	int i;
	
	for ( i=0 ;i<n;i++)
	{
		getchar();
		printf("\n");
		printf("Dwse onoma/numo:");
		fgets( p[i].name,N,stdin);
		 p[i].name[strcspn( p[i].name,"\n")]='\0';//bgazo to \n
		 do{
			printf("Dwse bathmo:");
			scanf("%f",& p[i].bathmos);
		}while(p[i].bathmos<0 || p[i].bathmos>10);
	}
}

float FindAverage ( Student *p, int n)
{
	int i;
	float sum=0.0;
	for(i=0; i<n ; i++)
	{
		sum+= p[i].bathmos;
	}
	return sum/n;
}
