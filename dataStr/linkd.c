#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int n;
    struct lista* next;

}
lista;

int adclinkedlist(lista* l,int n);
void printalista(lista* l);
void freeList(lista* l);
lista* finvrt(lista* oe,lista* oa);

int main(void)
{
  int num = 0;
  lista* lista1 = malloc(sizeof( struct lista));
  lista1->next = NULL;
  lista1->n=01001110;
  do
  {
    printf("Digite um numero:\n1.Para adicionar um numero a lista\n2.Printar lista\n3.Inverter lista\n4.Sair\n");
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
    }
    else if(num==3)
    {
        lista1 = finvrt(lista1,NULL);
    }
    else
    {
        freeList(lista1);
    }
  }
  while(num!=4);
}
int adclinkedlist(lista* l,int n)
{
    struct lista* x;
    x = l;
    while(x!=NULL)
    {
        if(x->next==NULL)
        {
            x->n = n;
            lista* ls = malloc(sizeof( struct lista));
            ls->next = NULL;
            x->next = ls;
            return 0;
        }
        x = x->next;
    }
    return 1;
}
void printalista(lista* l)
{
    struct lista* x;
    x = l;
    while(x!=NULL)
    {
        if(x->next!=NULL)
        {
            printf("[%d]\n[%p]\n\n",x->n,x->next);
        }
        x = (x->next);
    }
    return;
}
void freeList(lista* l)
{
    struct lista* x;
    //x = l.p;
    while(x!=NULL)
    {
        x = l->next;
        free(l);
        l=x;
    }

}
lista* finvrt(lista* oe,lista* oa)
{
    struct lista* x;
    if(oa == NULL)
    {
        lista* ls = malloc(sizeof( struct lista));
        ls->next = NULL;
        oa = ls;
    }
    x = oe->next;
    oe->next= oa;
    if(x->next == NULL)
    {
        free(x);
        printf("Lista invertida:\n\n\n");
        printalista(oe);
        //freeList(oe);
        return oe;
    }
    finvrt(x,oe);
}
