#include <stdio.h>
/*
Nome:Arthur Carvalho Oliveira
Matrícula:12211BSI220
*/
int vetornum(int n,int arr[],int tamanhoarr);

void main(void)
{
    int arr[10];
    for(int i =0;i<10;i++)
    {
        int tmp = 0;
        printf("Digite o %d numero\n",i+1);
        scanf("%d",&tmp);
        if(vetornum(tmp,arr,10)==0)
        {
            arr[i] = tmp;
        }
        else
        {
            printf("Numero ja existe no vetor\n");
            i--;
            continue;
        }
    }
    for(int i =0;i<10;i++)
    {
        printf("arr[%d]: %d\n",i,arr[i]);
    }
}
int vetornum(int n,int arr[],int tamanhoarr)
{
    for(int i =0; i<tamanhoarr;i++)
    {
        if(n == arr[i])
        {
            return 1;
        }
    }
    return 0;
}