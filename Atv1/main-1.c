#include <stdio.h>
/*
Nome:Arthur Carvalho Oliveira
Matrícula:12211BSI220
*/
void main(void)
{
    float arr[20];
    for(int i =0; i < 20; i++)
    {
        printf("Digite o %d numero do vetor:\n",i+1);
        scanf("%f",&arr[i]);
    }
    for(int i =0; i < 20; i++)
    {
        printf("arr[%d]: %f",i,arr[i]);
    }
    for(int i =0;i < 20; i++)
    {
        for(int j =(20-1);j >= i; j--)
        {
            if(arr[j] > arr[j+1])
            {
                float tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    for(int i =0; i < 20; i++)
    {
        printf("arr[%d]: %f\n",i,arr[i]);
    }
}