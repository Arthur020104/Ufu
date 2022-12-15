#include <stdio.h>
#include <stdlib.h>

unsigned long long int FibonacciIterativo(int n);
unsigned long long int FibonacciRecursivo (int n);
int main(void) 
{
    int i;
    //A funcao abaixo nao consegue satisfazer seu objetivo
    //por nao conseguir retornar o numero de por exemplo fibonacci(100)
    //que seria 354224848179261915075, devido a tal numero exceder a capacidade
    //do long long 
    for (i = 1; i < 100; i++)
    printf("\n termo %d: %llu", i, FibonacciIterativo(i));

    //A funcao abaixo nao termina sua execuçao com numeros maiores
    //, devido a grander quantidade de processamento necessário para fazer 
    //sua execuçao.Ex: FibonacciRecursivo (100) necessita do calculo
    //de FibonacciRecursivo (99)+FibonacciRecursivo (98)
    //que por consequencia FibonacciRecursivo (99) e FibonacciRecursivo (98)
    //que necessitam do calculo de FibonacciRecursivo (n-1) e FibonacciRecursivo (n-2)...
    //No meu computador o script rodou por 30 min e conseguiu retornar apenas até
    //fibonacci de 52
    for (i = 1; i < 100; i++)
    printf("\n termo %d: %llu", i, FibonacciRecursivo (i));
    return 0;
}

unsigned long long int FibonacciIterativo(int n)
{
    unsigned long long int arr[100];
    unsigned long long int soma = 0;
    for(int i= 0;i<=n;i++)
    {
        if(i < 2)
        {
            //printf("\ni=%d",i);
            int x = i;
            arr[x] = x;
            soma = x;
        }
        else
        {
            arr[i] = arr[i-1]+arr[i-2];
            soma = arr[i];
        }
    }
    return soma;
}

unsigned long long int FibonacciRecursivo (int n)
{
    if(n>1)
    {
        return FibonacciRecursivo (n-2) + FibonacciRecursivo (n-1);
    }
    else
    {
        return n;
    }
}

