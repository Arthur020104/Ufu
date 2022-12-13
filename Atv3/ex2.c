#include <stdio.h>
#include <stdlib.h>
int SomaptNn(int n);
void main(void)
{
    int n;
    printf("Digite um numero para funcao: ");
    scanf("%d",&n);
    printf("%d",SomaptNn(n));
}
int SomaptNn(int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        return (n*n)+SomaptNn((n-1));
    }
}