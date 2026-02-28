#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Updated prototypes to accept int** (pointer to pointer)
int check_array(int n, int m1);
void init_2Darray(int **matrix, int m, int n);
void print_2Darray(int **matrix, int m, int n);
int** prod_2Darray(int **p1, int **p2, int m, int n, int m1, int n1);

int main() {
    srand(time(NULL));
    int **p1, **p2, **p_result;
    int m, n, m1, n1, i;

    while (1) {
        printf("Give rows of first matrix: ");
        scanf("%d", &m);
        printf("Give columns of first matrix: ");
        scanf("%d", &n);

        printf("\nGive rows of second matrix: ");
        scanf("%d", &m1);
        printf("Give columns of second matrix: ");
        scanf("%d", &n1);

        if (check_array(n, m1) == 0) {
            printf("Error: Cols of P1 must equal Rows of P2! Try again.\n\n");
        } else {
            break;
        }
    }

    // Allocate P1
    p1 = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        p1[i] = (int *)malloc(n * sizeof(int));
    }

    // Allocate P2
    p2 = (int **)malloc(m1 * sizeof(int *));
    for (i = 0; i < m1; i++) {
        p2[i] = (int *)malloc(n1 * sizeof(int));
    }

    init_2Darray(p1, m, n);
    init_2Darray(p2, m1, n1);

    printf("\nFIRST MATRIX:\n");
    print_2Darray(p1, m, n);

    printf("\nSECOND MATRIX:\n");
    print_2Darray(p2, m1, n1);

    // Multiplication
    p_result = prod_2Darray(p1, p2, m, n, m1, n1);

    printf("\nProduct result matrix:\n");
    print_2Darray(p_result, m, n1);

    // Free memory (Crucial for dynamic allocation)
    for(i=0; i<m; i++) free(p1[i]); free(p1);
    for(i=0; i<m1; i++) free(p2[i]); free(p2);
    for(i=0; i<m; i++) free(p_result[i]); free(p_result);

    return 0;
}

int check_array(int n, int m1) {
    return (n == m1);
}

void init_2Darray(int **matrix, int m, int n) 
{
	int i,j;
    for ( i= 0; i < m; i++) 
	{
        for ( j = 0; j < n; j++) {
            matrix[i][j] = rand() % 51; // Kept small for easier checking
        }
    }
}

void print_2Darray(int **matrix, int m, int n) 
{
	int i,j;
   for(i = 0; i < n; i++)
    {
        printf("\t[");
        for(j = 0; j < n; j++)
        {
            printf("%d", matrix[i][j]);
            if(j < n - 1) 
			printf(",");
        }
        printf("]\n");
}
}

int** prod_2Darray(int **p1, int **p2, int m, int n, int m1, int n1) {
    // Result matrix will be m x n1
    int **res = (int **)malloc(m * sizeof(int *));
    int i,j,k;
    for ( i = 0; i < m; i++) 
	{
        res[i] = (int *)calloc(n1, sizeof(int)); // calloc initializes to 0
        for ( j = 0; j < n1; j++) {
            for ( k = 0; k < n; k++) {
                res[i][j] += p1[i][k] * p2[k][j];
            }
        }
    }
    return res;
}

