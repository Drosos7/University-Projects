#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void init_2Darray(int **p, int m, int n);
void print_2Darray(int **p,int m,int n);
int check_sparse(int **p, int m, int n);

int main()
{
	srand(time(NULL));
	//Variable declarations
	int **p;
	int m,n,i;
	
	//Input validation for dimensions
	do{
		printf("Give rows:");
		scanf("%d",&m);
	}while(m<=0);
	
	do{
		printf("Give columns:");
		scanf("%d",&n);
	}while(n<=0);
	
	p=(int**)malloc(sizeof(int*)*m);

	 if(!p)
	 {
		printf("Failed to allocate memory for row pointers");
		exit(-1);
	  }
		for(i=0;i<m;i++){
		 	p[i]=(int *)calloc(n,sizeof(int));
		 	if(!p[i])
		      {
				printf("Failed to allocate memory for row %d", i);
				exit(-1);	
				}  }
				
				//Initialization of the 2D array with random 0s and 1s
				init_2Darray(p,m,n);
				//Function call to print the 2D array
				print_2Darray(p,m,n);
				
				if(check_sparse(p,m,n))
				 	printf("\n\nMatrix is sparse!(0=>80%% stoixeiown)");
				else 
				
				printf("\n\nMatrix is not sparse!") ;
				
				//Free allocated memory
				for(i=0;i<m;i++)
				 free(p[i]);
				 free(p);
	return 0;
}

void init_2Darray(int **p, int m, int n)
{
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			p[i][j]=rand()%2;
			}
}

void print_2Darray(int **p,int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		printf("\t[");
		for(j=0 ; j<n ; j++)
		{
			printf("%d",p[i][j]);
			if(j<n-1)
			printf(" ");
		}
		printf("]\n");
	}
}

int check_sparse(int **p,int m, int n)
{
	int i,j,cnt=0,whole=1;
	whole=m*n;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		if(p[i][j]==0)
		 cnt++;
	}
	if( (cnt*100.0/whole)>=80)
	return 1;
	return 0;
}
