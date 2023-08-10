#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Nome:Arthur Carvalho Oliveira
Matrícula:12211BSI220
*/
void main(void)
{
    char M[100] = "The quick brown fox jumps over the lazy dog";
    char N[100] = "A ligeira raposa marrom saltou sobre o cachorro preguicoso";
    char R[100];

    //1) imprimir o tamanho das strings M e N

    int lenM;
    for(lenM=0;lenM<100;lenM++)
    {
        if(M[lenM]=='\0')
        {
            //lenM--;
            break;
        }
    }
    printf("\nTamanho da string M: %d",lenM);
    int lenN;
    for(lenN=0;lenN<100;lenN++)
    {
        if(N[lenN]=='\0')
        {
            //lenN--;
            break;
        }
    }
    printf("\nTamanho da string N:%d ",lenN);

    // 2) copiar M para R
    for(int j = 0;j< lenM;j++)
    {
        R[j]=M[j];
        if(j == (lenM-1))
        {
            R[j+1]='\0';
        }
    }
    printf("\n%s",R);

    // 3) concatenar N em R
    for(int i = 0;i<lenN;i++)
    {
        R[lenM+i] = N[i];
    }
     printf("\n%s",R);
}
