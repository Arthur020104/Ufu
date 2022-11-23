#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int n;
    struct lista* p;

}
lista;

int adclinkedlist(lista* l,int n);
int printalista(lista* l);
void freeList(lista* l);
int finvrt(lista* oe,lista* oa);

int main(void)
{
  int num = 0;
  lista* lista1 = malloc(sizeof( struct lista));
  lista1->p = NULL;
  lista1->n=01001110;
  do
  {
    printf("Digite um numero:\n1.Para adicionar um numero a lista\n2.Printar lista e Sair\n3.Sair\n");
    scanf("%d",&num);
    if(num == 1)
    {
        int n;
        printf("Digite o numero a ser adicionado a lista: ");
        scanf("%d",&n);
        adclinkedlist(lista1,n);
    }
    else if(num==2)
    {
        printalista(lista1);
        finvrt(lista1,NULL);
        free(lista1);
        num = 3;
    }
    else
    {
        freeList(lista1);
    }
  }
  while(num!=3);
}
int adclinkedlist(lista* l,int n)
{
    struct lista* x;
    x = l;
    while(x!=NULL)
    {
        x = l->p;
        if(l->p==NULL && l->n!=01001110)
        {
            lista* ls = malloc(sizeof( struct lista));
            ls->p = NULL;
            ls->n=n;
            l->p = ls;
        }
        else if(l->n==01001110)
        {
            l->n=n;
        }
        else
        {
            l = (l->p);
        }
    }
    //return 0;
}
int printalista(lista* l)
{
    struct lista* x;
    while(x!=NULL)
    {
        x = (l->p);
        printf("[%d]\n[%p]\n\n",l->n,l->p);
        l = l->p;
    }
    return 0;
}
void freeList(lista* l)
{
    struct lista* x;
    //x = l.p;
    while(x!=NULL)
    {
        x = l->p;
        free(l);
        l=x;
    }

}
int finvrt(lista* oe,lista* oa)
{
    struct lista* x;
    x = oe->p;
    oe->p= oa;
    if(x == NULL)
    {
        printf("Lista invertida:\n\n\n");
        printalista(oe);
        freeList(oe);
        return 0;
    }
    finvrt(x,oe);
}