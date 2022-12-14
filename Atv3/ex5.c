#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long int FibonacciIterativo(int n);
unsigned long long int FibonacciRecursivo (int n);
int main(void) 
{
    int i;
    clock_t start, end;
    double execution_time1,execution_time2;
    start = clock();

    for (i = 1; i < 100; i++)
    printf("\n termo %d: %llu", i, FibonacciIterativo(i));

    end = clock();
    execution_time1 = ((double)(end - start))/CLOCKS_PER_SEC;
    start = clock();

    for (i = 1; i < 100; i++)
    printf("\n termo %d: %llu", i, FibonacciRecursivo (i));

    end = clock();
    execution_time2 = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("FibonacciIterativo em segundos: %f", execution_time1);
    printf("FibonacciRecursivo em segundos: %f", execution_time1);
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