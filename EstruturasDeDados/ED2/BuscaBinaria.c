#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>
void preencherVetorAleatorio(int *vetor, int len);
int Binary(int lower,int upper,int*vet,int n);
void preencherVetorAleatorio(int *vetor, int len) 
{
    for(int i = 0; i < len; i++) 
    {
        vetor[i] = i;
    }
}
int Binary(int lower,int upper,int*vet,int n)
{
    if(upper == lower||lower>upper)
    {
        printf("Nao esta no arr");
        return -1;
    }
    else
    {
        int index = lower+((int)((upper-lower)/2));
        if(n > vet[index])
        {
            lower = index+1;
            return Binary(lower,upper,vet,n);
        }
        else if(n<vet[index])
        {
            upper = index-1;
            return Binary(lower,upper,vet,n);
        }
        else
        {
            return index;
        }
    }
    //10
    //5-6,7,8,9,10
}
int Linear(int len,int *vet,int n)
{
    for(int i = 0;i<len;i++)
    {
        if(vet[i] == n)
        {
            return i;
        }
    }
    return -1;
}
int main(void) 
{
    int len = 100000000;
    int *vetor = (int *)malloc(sizeof(int) * len);
    preencherVetorAleatorio(vetor, len);

    LARGE_INTEGER start_time, end_time, frequency;
    QueryPerformanceCounter(&start_time);
    int index = Binary(0, len, vetor, (len - 10));
    QueryPerformanceCounter(&end_time);
    QueryPerformanceFrequency(&frequency);

    double time_taken = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("Tempo de execucao para busca binaria: %lf segundos, index %d\n", time_taken, index);

    QueryPerformanceCounter(&start_time);
    index = Linear(len, vetor, (len - 10));
    QueryPerformanceCounter(&end_time);

    time_taken = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
    printf("Tempo de execucao para busca linear: %lf segundos, index %d\n", time_taken, index);

    free(vetor);
    return 0;
}