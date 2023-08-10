#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


Fila criaFila()
{
    Fila f;
    f.frst = 0;
    f.lst = -1;
    f.sizMax = 5;
    f.sizCons = 0;
    return f;
}
void adicionaFila(struct Fila *f, int val)
{
    if(!filaCheia(f))
    {
        f->sizCons ++;
        f->lst = proxPosFila(f,f->lst);
        f->values[f->lst] = val;
        return;
    }
    else
    {
        printf("Erro: fila cheia.\n");
    }
}

int filaCheia(struct Fila *f)
{
    return (f->sizCons == f->sizMax);
}

int filaVazia(struct Fila *f)
{
    return (f->sizCons <= 0);
}

void printFila(struct Fila x)
{
    if(filaVazia(&x))
    {
        printf("\nFila vazia.\n");
    }
    else
    {
        (x.sizCons > 1) ? printf("%d->",retireUm(&x)) : printf("%d",retireUm(&x));
        printFila(x);

    }
        
}

int retireUm(struct Fila *x)
{
    int value = x->values[x->frst];
    x->frst= proxPosFila(x, x->frst);
    x->sizCons--;
    return value;
}
int proxPosFila(struct Fila *x,int n)
{
    if( filaVazia(x))
    {
        printf("Fila VAZIA");
        return -1;
    }
    if(n == x->sizMax-1)
    {
        return 0;
    }
    else
    {
        return n+1;
    }
}
