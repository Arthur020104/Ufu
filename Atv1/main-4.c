#include <stdio.h>
/*
Nome:Arthur Carvalho Oliveira
Matrícula:12211BSI220
*/
void main(void)
{
    int n;
    printf("Digite o tamanho do vetor desejado:\n");
    scanf("%d",&n);
    float arr[n];

    float soma = 0;

    for(int i=0;i<n;i++)
    {
        printf("Digite o valor do %d numero:\n",i+1);
        scanf("%f",&arr[i]);

        soma +=arr[i];
    }
    float media = soma/n;
    float d =0;
    for(int i=0;i<n;i++)
    {
        float amostrai =(1/(n-1.0)) *(soma)*((arr[i]-media)*(arr[i]-media));
        d+=amostrai;
    }
    float varm=d/n;
    printf("\n%f\n",varm);
}