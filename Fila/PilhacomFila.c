#include <stdio.h>
#include "fila.h"
int nx = 0;
void adicionaPilha(Fila* f1,Fila* f2,int n);
int tiraDaPilha(Fila* f1,Fila* f2);
int main(void)
{
    Fila f1 = criaFila();
    Fila f2 = criaFila();
    int input;
    do
    {
        printf("1.Para adicionar a Pilha\n2.Remover da Pilha\n");
        scanf("%d",&input);
        if(input == 1)
        {
            int n;
            printf("Digite o n que deseja adcionar a pilha\n");
            scanf("%d",&n);
            adicionaPilha(&f1,&f2,n);
        }
        else if(input==2)
        {
            int n = tiraDaPilha(&f1,&f2);
            printf("N:%d\n",n);
        }
        else
        {
            printf("Fila1\n");
            printFila(f1);
            printf("Fila2\n");
            printFila(f2);
        }
    }while(input > 0 && input <4);

}
void adicionaPilha(Fila* f1,Fila* f2,int n)
{
    if(f1->sizCons <=1 && nx==0 )
    {
        adicionaFila(f1,n);
        if(f1->sizCons > 1)
        {
            adicionaFila(f2,retireUm(f1));
        }
        
    }
    else if(f2->sizCons <= 1 && nx ==1)
    {
        adicionaFila(f2,n);
        if(f2->sizCons > 1)
        {
            adicionaFila(f1,retireUm(f1));
        }
        
    }
    //
}
int tiraDaPilha(Fila* f1,Fila* f2)
{
    if(f1->sizCons < f2->sizCons && f2->sizCons != 1 || ((f1->sizCons == f2->sizCons)&&nx==0 ))
    {
        nx = 1;
        int n = retireUm(f1);
        if(f1->sizCons ==0)
        {
            while(f2->sizCons != 1)
            {
                adicionaFila(f1,retireUm(f2));

            }
        }
        return n;
    }
    else if(f1->sizCons > f2->sizCons && f1->sizCons != 1 ||((f1->sizCons == f2->sizCons)&&nx==1))
    {
        nx =0;
       int n = retireUm(f2);
        if(f2->sizCons ==0)
        {
            while(f1->sizCons != 1)
            {
                adicionaFila(f2,retireUm(f1));

            }
        }
        return n;
    }
    else
    {
        if(f1->sizCons > 0)
        {
            return retireUm(f1);
        }
        else
        {
            return retireUm(f2);
        }
    }
}