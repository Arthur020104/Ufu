#include <stdio.h>
#include <stdlib.h>
void decrescente(int n);
int crescente(int n);
void main(void)
{
    printf("\n crescente:"); crescente(15);
    printf("\n descrescente:"); decrescente(15);
    return;

}

int crescente(int n)
{
    if(n==0)
    {
        printf("%d ",0);
        return 0;
    }
    else
    {
        int x = 1+crescente(--n);
        printf("%d ",x);
        return x;
    }
}
void decrescente(int n)
{
    if(n==0)
    {
        printf("%d ",n);
        return;
    }
    else
    {
        printf("%d ",n);
        decrescente(--n);
    }
}
