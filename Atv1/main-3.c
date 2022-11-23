#include <stdio.h>
#include <math.h>
/*
Nome:Arthur Carvalho Oliveira
Matrícula:12211BSI220
*/
void main(void)
{
    int n;
    printf("Digite o tamanho do vetor desejado: \n");
    scanf("%d",&n);
    float arr[n];
    for(int i =0;i<n;i++)
    {
        printf("Digite o valor da %d posicao do vetor:\n",i+1);
        scanf("%f",&arr[i]);
    }
    float soma = 0;
    for(int i=0;i<n;i++)
    {
        soma += arr[i];
    }
    float s = sqrt((soma*(arr[n-1]/(n*n))));
    printf("Valor de S: %f.",s);
}