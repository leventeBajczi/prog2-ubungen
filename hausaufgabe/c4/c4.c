#include <stdio.h>
#include <stdlib.h>

int ist_quadratisch(int);
int matrix_berechnen(int, char**);
int skalarprodukt(int**, int, int, int);

int main(int argc, char** argv)
{
    int n;
    if(!(n = ist_quadratisch(argc-1)))
    {
        printf("Error: input is not a square matrix\n");
        return 0;
    }
    return matrix_berechnen(n, argv+1);
}

int ist_quadratisch(int i)
{
    int j = 0;
    while(j*j<i)j++;
    if(j*j == i)return j;
    return 0;
}

int matrix_berechnen(int n, char** e)
{
    int** matrix = (int**)malloc(sizeof(int*) * n);
    int** ergebnis_matrix = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i<n; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int) * n);
        ergebnis_matrix[i] = (int*)malloc(sizeof(int) * n);
        for(int j = 0; j<n; j++)
        {
            matrix[i][j] = atoi(e[i*n+j]);
        }
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            ergebnis_matrix[i][j] = skalarprodukt(matrix, i, j, n);
            printf("%4d", ergebnis_matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i<n;i++)
    {
        free(matrix[i]);
        free(ergebnis_matrix[i]);
    }
    free(matrix);
    free(ergebnis_matrix);

    return 0;
}

int skalarprodukt(int** matrix, int i, int j, int n)
{
    int sum = 0;
    for(int k= 0; k<n;k++)
    {
        sum+=matrix[i][k]*matrix[k][j];
    }
    return sum;
}