#include <stdio.h>
#include <stdlib.h>

float** ALOCA(int col,int row);

void LEITURA(float** matriz,int col,int row);

float** MULTIPLICA(float** matrizA,int colA,int rowA,float** matrizB,int colB,int rowB);

void IMPRIME(float** matriz,int col,int row);

void DESALOCA(float** matriz,int col);


void main(void)
{
    float **m1 = ALOCA(2,3);
    printf("\nMatrizA:\n");
    LEITURA(m1,2,3);

    float **m2 = ALOCA(3,4);
    printf("\nMatrizB:\n");
    LEITURA(m2,3,4);

    float **m3 = MULTIPLICA(m1,2,3,m2,3,4);

    printf("\nMatrizA:");
    IMPRIME(m1,2,3);
    printf("\nMatrizB:");
    IMPRIME(m2,3,4);
    printf("\nMatrizA.B:");
    IMPRIME(m3,2,4);

    DESALOCA(m1,2);
    DESALOCA(m2,3);
    DESALOCA(m3,2);
    return;
}

float** ALOCA(int col,int row)
{
    float **matriz = (float **)malloc(col * sizeof(float*));
    for(int i = 0; i < col; i++)
    { 
        matriz[i] = (float *)malloc(row * sizeof(float));
    }
    return matriz;
}
void LEITURA(float** matriz,int col,int row)
{
    for(int i=0; i < col; i++)
    {
        for(int j=0; j < row; j++)
        {
            printf("Matriz M%dxN%d: ",i+1,j+1);
            scanf("%f",&matriz[i][j]);
        }
    }
    printf("\n\n");
    return;
}
float** MULTIPLICA(float** matrizA,int colA,int rowA,float** matrizB,int colB,int rowB)
{
    float **matrizmult = ALOCA(colA,rowB);
    for(int j = 0; j<colA;j++)
    {
        for(int h = 0; h<rowB;h++)
        {
            float soma=0;
            for(int i = 0;i<rowA;i++)
            {
                soma += matrizA[j][i]*matrizB[i][h];
            }
            matrizmult[j][h] = soma;
        }
    }
    return matrizmult;
}

void IMPRIME(float** matriz,int col,int row)
{
    for(int i = 0;i<col;i++)
    {
        printf("\n");
        for(int j =0;j<row;j++)
        {
            printf(" M[%d][%d]: %f",i+1,j+1,matriz[i][j]);
        }
    }
    printf("\n\n");
    return;
}

void DESALOCA(float** matriz,int col)
{
    for(int i=0; i<col; i++) 
    {
        free(matriz[i]);
    }
    return;
}
