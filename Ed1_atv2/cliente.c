#include <stdlib.h> // para funcao exit()
#include <stdio.h>
#include "vetor.h"
float MaiorNVet(Vetor* arr);
float SumVet(Vetor* arr);
float MediaVet(Vetor* arr);
int main()
{
    Vetor* V;
    int tam;
    float valor;
    //tam = V->tamanho;

    printf("Forneca o tamanho do vetor: ");
    scanf("%d", &tam);

    V = criar(tam);
    if (V == NULL)
    {
        printf("Erro: nao foi possivel criar o vetor\n");
        exit(1);
    }

    for (int i = 0; i < tamanho(V); i++)
    {
        printf("Digite o %do. valor: ", i + 1);
        scanf("%f", &valor);
        inserir(valor, V, i);

    }
    float vlr = SumVet(V);
    printf("\nSum do vetor %f", vlr);
    vlr = MediaVet(V);
    printf("\nMedia do vetor %f", vlr);
    vlr = MaiorNVet(V);
    printf("\nMaior valor vetor %f", vlr);
    printf("\nQual elemento do vetor deseja apagar 0-%d: ", tamanho(V) - 1);
    int index;
    scanf("%d", &index);
    if (index > tamanho(V) - 1 || index < 0)
    {
        printf("Tentando acessar elemento fora do vetor");
        return 1;
    }


    apagaElemento(V, index);
    for (int i = 0; i < tamanho(V); i++)
    {
        float x;
        acessar(V, i, &x);
        printf("\n[%d]%f ", i, x);
    }
    /*for (int i = 0; i < tamanho(V); i++) {
      acessar(V, i, &valor);
      printf("%f ", valor);
    }*/
    destruir(V);
    return 0;
}
/*
Entrada: um ponteiro para um vetor 
Saída: soma dos elementos do vetor 
Pre-condição: o ponteiro para o vetor deve ser válido
Pós-condição: não há modificação no vetor original
*/
float SumVet(Vetor* arr)
{
    float sum = 0;
    for (int i = 0; i < tamanho(arr); i++)
    {
        float x;
        acessar(arr, i, &x);
        sum += x;

    }
    return (sum);

}
/*
Entrada: um ponteiro para um vetor 
Saída: media aritmetica dos elementos do vetor
Pre-condição: o ponteiro para o vetor deve ser válido
Pós-condição: não há modificação no vetor original
*/
float MediaVet(Vetor* arr)
{
    float sum = 0;
    for (int i = 0; i < tamanho(arr); i++)
    {
        float x;
        acessar(arr, i, &x);
        sum += x;

    }
    return (sum / tamanho(arr));

}
/*
Entrada: um ponteiro para um vetor 
Saída: maior valor dentre os elementos do vetor
Pre-condição: o ponteiro para o vetor deve ser válido
Pós-condição: não há modificação no vetor original
*/
float MaiorNVet(Vetor* arr)
{
    float* maior = malloc(sizeof(int));
    for (int i = 0; i < tamanho((arr)); i++)
    {
        float x;
        acessar(arr, i, &x);
        if (maior == NULL || *maior < x)
        {
            *maior = x;
        }

    }

    float y = *maior;
    free(maior);
    return y;
}
