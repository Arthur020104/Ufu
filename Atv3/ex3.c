#include <stdio.h>
#include <stdlib.h>
void decrescente(int n);
void crescente(int n);
void main(void)
{
    printf("\n crescente:"); crescente(15);
    printf("\n descrescente:"); decrescente(15);
    return;

}

int *cres= NULL;
void crescente(int n)
{
    if(!(cres))
    {
        cres = (int*)malloc(sizeof(int));
        *cres = n;
        n = 0;
        crescente(n);
    }
    else if(n==*cres)
    {
        printf(" %d",n);
        return;
    }
    else
    {
        printf(" %d",n);
        crescente((++n));
    }
}
void decrescente(int n)
{
    if(n <=0)
    {
        printf(" %d",n);
        return;
    }
    else
    {
        printf(" %d",n);
        decrescente((--n));
    }
}
