#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetorAleatorio(int *vetor, int len);
void ordenaVetor(int *vet, int len);
void Binary(int lower,int upper,int*vet,int n);
void preencherVetorAleatorio(int *vetor, int len) 
{
    for(int i = 0; i < len; i++) 
    {
        vetor[i] = rand() % 1000;
    }
}
void ordenaVetor(int *vet, int len)
{
    for(int i= 0; i < len;i++)
    {
        for(int j = 0; j <(len-i)-1;j++)
        {
            if(vet[j] > vet[j+1])
            {
                int tmp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = tmp;
            }
        }
    }
}
void Binary(int lower,int upper,int*vet,int n)
{
    if(upper == lower||lower>upper)
    {
        printf("Nao esta no arr");
        return;
    }
    else
    {
        int index = lower+((int)((upper-lower)/2));
        if(n > vet[index])
        {
            lower = index+1;
            printf("\nupper:%d\nlower:%d\nindex:%d",upper,lower,index);
            Binary(lower,upper,vet,n);
        }
        else if(n<vet[index])
        {
            upper = index-1;
            printf("\nupper:%d\nlower:%d\nindex:%d",upper,lower,index);
            Binary(lower,upper,vet,n);
        }
        else
        {
            printf("Achou o n no index %d",index);
            //achou
            return;
        }
    }
    //10
    //5-6,7,8,9,10
}
void main(void)
{
    int len = 1000;
    int vetor[len];
    preencherVetorAleatorio(vetor,len);
    for(int i =0;i< len;i++)
    {
        printf("\nvet[%d]:%d",i,vetor[i]);
    }
    ordenaVetor(vetor,len);
    for(int i =0;i< len;i++)
    {
        printf("\n\n\nOrdenado");
        printf("\nvet[%d]:%d",i,vetor[i]);
    }
    int n;
    printf("\nQual numero voce deseja procurar no arr:");
    scanf("%d",&n);
    Binary(0,len-1,vetor,n);
}