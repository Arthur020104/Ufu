#include <stdio.h>
#include "fila.h"
int main(void)
{
    Fila f = criaFila();
    /*for(int i = 0; i < f.sizMax; i++)
    {
        int x;
        printf("\nDigite o valor do numero %d da fila: ", i+1);
        scanf("%d", &x);
        adicionaFila(&f, x);
    }*/
    int input;
    do
    {
        printf("\n1.Adicionar a fila, 2.Remover da fila e 3.Para printar fila e remover elementos: ");
        scanf("%d",&input);
        if(input == 1)
        {
            printf("N:");
            scanf("%d",&input);
            adicionaFila(&f,input);
            input = 1;
        }
        else if( input == 2)
        {
            printf("Removeu o primeiro valor da fila n:%d",retireUm(&f));

        }
        else if( input == 3)
        {
            printFila(&f);
        }
    }
    while(input < 4 && input > 0 && !filaVazia(&f));

    return 0;
}