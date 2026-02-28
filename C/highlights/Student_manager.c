#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 50
//1.
typedef struct{
	char name[N];
	float grade;
	float deviation;
}Student;

void getData(Student *p , int n);	
void calculateStats(Student *p , int n, char * max_name);
float FindAverage(Student *p ,int n);
int main()
{
	//2.
	float average=0.0;
	char max_name[N];
	int M;
	do{
	printf("Number of students:");
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
		printf("\nInput data:\n");
		getData( p , M);
		
	
		calculateStats(p,  M, max_name );
		
		average=FindAverage( p, M);
		
		FILE *fp;
		if(!(fp=fopen("results.dat","a")))
		{
			fprintf(stderr,"Error opening new file!");
			exit(-1);
		}
		fprintf(fp,"\nClass average is:%.2f.The student with the highest grade is:%s", average,max_name );
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
	//Calculate deviation for each student and find the student with the highest grade
	for( i =0; i<n; i++)
	{
		 p[i].deviation=fabs( p[i].grade-5.0);
		if( p[i].grade>max)
		{
			max= p[i].grade;
			strcpy(new_max, p[i].name);
		}
	}
		strcpy(max_name,new_max);
	
		
}
void getData(Student *p , int n)
{
	int i;
	//Initialisation of student's data structure 
	for ( i=0 ;i<n;i++)
	{
		getchar();
		printf("\n");
		printf("Student's name:");
		fgets( p[i].name,N,stdin);
		 p[i].name[strcspn( p[i].name,"\n")]='\0';//Remove newline character from the end of the name
		 do{
			printf("Student's grade:");
			scanf("%f",& p[i].grade);
		}while(p[i].grade<0 || p[i].grade>10);
	}
}

float FindAverage ( Student *p, int n)
{
	//Calculate the average grade of the class
	int i;
	float sum=0.0;
	for(i=0; i<n ; i++)
	{
		sum+= p[i].grade;
	}
	return sum/n;
}
