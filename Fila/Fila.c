#include <stdio.h>
#include <stdlib.h>

typedef struct Fila
{
    int frst, lst, sizCons, sizMax;
    int values[6];
} Fila;

void printFila(struct Fila *x);
int proxPosFila(struct Fila *x, int n);
void adicionaFila(struct Fila *f, int val);
int filaCheia(struct Fila *f);
int filaVazia(struct Fila *f);
int retireUm(struct Fila *x);

int main(void)
{
    Fila f;
    f.frst = 0;
    f.lst = -1;
    f.sizMax = 5;
    f.sizCons = 0;
    for(int i = 0; i < f.sizMax; i++)
    {
        int x;
        printf("\nDigite o valor do numero %d da fila: ", i+1);
        scanf("%d", &x);
        adicionaFila(&f, x);
    }
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

void printFila(struct Fila *x)
{
    if(filaVazia(x))
    {
        printf("\nFila vazia.\n");
    }
    else
    {
        (x->sizCons > 1) ? printf("%d->",retireUm(x)) : printf("%d",retireUm(x));
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
