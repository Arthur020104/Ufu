#include <stdio.h>
#include <stdlib.h>

/*
Nome:Arthur Carvalho Oliveira
Matrícula:12211BSI220
*/

float main(){
    printf("N:");
    int N;
    scanf("%d",&N);
    float ***cubo = (float ***)malloc(N * sizeof(float**));
    for(int i = 0; i < N; i++)
    { 
        cubo[i] = (float **)malloc(N * sizeof(float*));
        for(int j = 0;j< N;j++)
        {
            cubo[i][j] = (float *)malloc(N * sizeof(float));
            for(int h = 0;h< N;h++)
            {
                printf("Valor na posicao %dx%dx%d:",i+1,j+1,h+1);
                float n;
                scanf("%f",&n);
                cubo[i][j][h] = n;
            }
        }
    }
    int F=0;
    do
    {
        printf("\nEscolha um par:\n1-XY\n2-XZ\n3-YZ\n");
        scanf("%d",&F);
    }
    while(F <= 0 || F >= 4 );
    int X=0,Y=0,Z=0;
    float sum=0;
    if(F==1)
    {
        do
        {
            printf("X:");
            scanf("%d",&X);
            printf("Y:");
            scanf("%d",&Y);
        } while ((X <= 0 || X > N)|| (Y <= 0 || Y > N) );
        
        Y--;
        X--;
        for(Z=0;Z<N;Z++)
        {
            Z==(N-1) ? printf("%f",cubo[X][Y][Z]) : printf("%f+",cubo[X][Y][Z]);
            sum += cubo[X][Y][Z];
        }
    }
    else if(F==2)
    {
        do
        {
            printf("X:");
            scanf("%d",&X);
            printf("Z:");
            scanf("%d",&Z);
        }while((X <= 0 || X > N)|| (Z <= 0 || Z > N ));
        X--;
        Z--;
        for(Y=0;Y<N;Y++)
        {
            Y==(N-1) ? printf("%f",cubo[X][Y][Z]) : printf("%f+",cubo[X][Y][Z]);
            sum += cubo[X][Y][Z];
        }
    }
    else
    {
        do
        {
            printf("Y:");
            scanf("%d",&Y);
            printf("Z:");
            scanf("%d",&Z);
        } while ((Y <= 0 || Y > N)|| (Z <= 0 || Z > N ));
        Y--;
        Z--;
        for(X=0;X<N;X++)
        {
            X==(N-1) ? printf("%f",cubo[X][Y][Z]) : printf("%f+",cubo[X][Y][Z]);
            sum += cubo[X][Y][Z];
        }
    }

    printf("=%f",sum);
    free(cubo);
    return 0;
}
