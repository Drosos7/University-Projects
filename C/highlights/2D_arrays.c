//Difference between static and dynamic 2D arrays in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  N 20
int main()
{
    int A[N][N],i, j, n;
    int **B;
    srand(time(NULL));

    do {
        printf("Give dimension (5-20): ");
        scanf("%d", &n);
    } while(n < 5 || n > 20);

    printf("\nMatrix initialization completed\n");

    for(i = 0; i < n; i++){
        for(j = 0; j <=i; j++)
            A[i][j] = 1 + rand() % 9;
        for(j=i+1;j<n;j++)
                A[i][j] = 0;
            }

    printf("Static matrix A :\n");
    for(i = 0; i < n; i++)
    {
        printf("\t[");
        for(j = 0; j < n; j++)
        {
            printf("%d", A[i][j]);
            if(j < n - 1) 
			printf(",");
        }
        printf("]\n");
        
        
    }
    
    B= (int**)malloc(n * sizeof(int*));
    if(!B)
	{ printf("Failed to allocate memory !");
	 exit(0);
     }

    for(i = 0; i<n; i++)
    {
        B[i] = malloc((i+1) * sizeof(int));
        if(!B[i])
		{
			printf("Failed to allocate memory for row %d", i);
			exit(0);
		} 
    }

    
    for(i = 0; i < n; i++)
        for(j = 0; j <=i; j++)
            B[i][j] = A[i][j];


    printf("\nDynamic matrix  B:\n");
     for(i = 0; i < n; i++)
    {
        printf("\t[");
        for(j = 0; j <= i; j++)
        {
            printf("%d", B[i][j]);
            if(j<n-1)
            printf(",");
        }
        for(j=i+1;j<n;j++){
         printf("0");
         if(j<n-1)
          printf(",");
		  }
         
        printf("]\n");
    }
  

    for(i = 0; i < n; i++)
        free(B[i]);
    free(B);

   return 0;
}

