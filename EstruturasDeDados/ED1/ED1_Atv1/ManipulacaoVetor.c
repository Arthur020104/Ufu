#include <stdio.h>
#include <stdlib.h>

void PrintValArr(int  *arr);
int MaiorValArr(int *arr);
void DoisMaioresNoArr(int *arr,int *maior1,int *maior2);
float MediaArr(int *arr);
int ValoresIguais(int *arr);
void PrintarArrInvert(int *arr);
int ValNumImp(int *arr);
int ARR_LEN = 10;

void main(void)
{
    int arr[ARR_LEN];
    for(int i =0; i < ARR_LEN;i++)
    {
        scanf("%d",&arr[i]);
    }
    PrintValArr(arr);
    int maior =MaiorValArr(arr);
    printf("\nMaior:%d",maior);
    int maior1,maior2; 
    DoisMaioresNoArr(arr,&maior1,&maior2);
    printf("\nMaior: %d,Segundo Maior: %d",maior1, maior2);

    float mediaArr = MediaArr(arr);
    printf("\nMedia:%f",mediaArr);
    int valIgual = ValoresIguais(arr);
    if(valIgual == 1)
    {
        printf("\nExistem valores iguais no vetor");
    }
    else
    {
        printf("\nNao existem valores iguais no vetor");
    }

    PrintarArrInvert(arr);

    int quantValImp = ValNumImp(arr);
    printf("\nO vetor tem %d valores impares",quantValImp);
}

void PrintValArr(int  *arr)
{
   for(int i =0; i < ARR_LEN;i++)
   {
        printf("\n%d",arr[i]);
   }
}

int MaiorValArr(int *arr)
{
    int maior = 0;
    for(int i =0; i < ARR_LEN;i++)
   {
        if(arr[i] > maior)
        {
            maior = arr[i];
        }
   }
   return maior;
}

void DoisMaioresNoArr(int *arr,int *maior1,int *maior2)
{
    int doisMaiores[2] = {0,0};
    for(int i =0; i < ARR_LEN;i++)
   {
        if(arr[i] > doisMaiores[0])
        {
            doisMaiores[0] = arr[i];
        }
        else if(arr[i] > doisMaiores[1] && arr[i] != doisMaiores[0])
        {
            doisMaiores[1] = arr[i];
        }
   }
    *maior1 = doisMaiores[0];
    *maior2 = doisMaiores[1];
}

float MediaArr(int *arr)
{
    int sum =0;
    for(int i =0; i < ARR_LEN;i++)
    {
        sum += arr[i];
    }
    return ((float)sum/(float)ARR_LEN);
}
int ValoresIguais(int *arr)
{
    int valIgual = 0;
    for(int i =0; i < ARR_LEN;i++)
    {
        for(int j =0; j < ARR_LEN;j++)
        {
            if(i==j)
            {
                continue;
            }
            else if(arr[i] == arr[j])
            {
                int valIgual = 1;
            }
        }
    }
    return valIgual;
}

void PrintarArrInvert(int *arr)
{
    for(int i =(ARR_LEN-1); i >= 0;i--)
    {
        printf("\n%d",arr[i]);
    }
}
int ValNumImp(int *arr)
{
    int impVal = 0;
    for(int i =0; i < ARR_LEN;i++)
    {
        if((arr[i] % 2) != 0)
        {
            impVal ++;
        }
    }
    return impVal;
}