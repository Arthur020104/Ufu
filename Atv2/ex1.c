#include <stdio.h>
#include <stdlib.h>
/*
Nome:Arthur Carvalho Oliveira
Matrícula:12211BSI220
*/

int main(){
    int M,N;
    printf("Digite a ordem das matrize A MxN\nM:");
    scanf("%d",&M);
    printf("N:");
    scanf("%d",&N);
    int **arr = (int **)malloc(M * sizeof(int*));
    for(int i = 0; i < M; i++)
    { 
        arr[i] = (int *)malloc(N * sizeof(int));
    }
    for(int i=0; i < M; i++)
    {
        for(int j=0; j < N; j++)
        {
            printf("Matriz A M%dxN%d: ",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    int X,Y;
    printf("Digite a ordem das matrize B MxN\nM:");
    scanf("%d",&X);
    printf("N:");
    scanf("%d",&Y);
    if(N != X)
    {
        printf("[ERROR:INVALID OPERATION] Impossivel mutiplicar matrizes dessas ordens.\n");
        return 1;
    }
    int **arrb = (int **)malloc(X * sizeof(int*));
    for(int i = 0; i < X; i++)
    {
        arrb[i] = (int *)malloc(Y * sizeof(int));
    }
    int **arrmult = (int **)malloc(M * sizeof(int*));
    for(int i = 0; i < M; i++)
    { 
        arrmult[i] = (int *)malloc(Y * sizeof(int));
    }

    for(int i=0; i < X; i++)
    {
        for(int j=0; j < Y; j++)
        {
            printf("Matriz B M%dxN%d: ",i+1,j+1);
            scanf("%d",&arrb[i][j]);
        }
    }

        for(int j = 0; j<M;j++)
        {
            for(int h = 0; h<Y;h++)
            {
                int soma=0;
                for(int i = 0;i<N;i++)
                {
                    soma += arr[j][i]*arrb[i][h];
                }
                arrmult[j][h] = soma;
            }
        }
    printf("\nMatriz A:\n");
    for(int i=0; i < M; i++)
    {
        for(int j=0; j < N; j++)
        {
            printf(" M%dxN%d: %d ",i+1,j+1,arr[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz B:\n");
    for(int i=0; i < X; i++)
    {
        for(int j=0; j < Y; j++)
        {
            printf(" M%dxN%d: %d ",i+1,j+1,arrb[i][j]);
        }
        printf("\n");
    }
    printf("\nProduto matricial A.B:\n");
    for(int i=0; i < M; i++)
    {
        for(int j=0; j < Y; j++)
        {
            printf(" M%dxN%d: %d ",i+1,j+1,arrmult[i][j]);
        }
        printf("\n");
    }
    free(arr);
    free(arrb);
    free(arrmult);
    return 0;
}
