#include "vetor.h"
#include <stdlib.h>
/*
  Entrada: valor inteiro que representa o tamanho do vetor
  Saida: ponteiro para o vetor, ou NULL caso nao seja possivel cria-lo
  Pre-condicao: o tamanho deve ser menor ou igual ao tamanho maximo do vetor (ou seja, 10)
  Pos-condicao: nao existe
*/
Vetor *criar(int tam)
{
    if(tam > 10 )
    {
        return NULL;

    }

    Vetor *vet;

    vet = malloc(sizeof(Vetor));
    vet->tamanho = tam;

    return vet;
}

/*
  Entrada: ponteiro para um vetor
  Saida: nao existe
  Pre-condicao: nao existe
  Pos-condicao: memoria do vetor eh desalocada
*/
void destruir(Vetor *vet)
{
  if (vet != NULL) free(vet);
}

/*
  Entrada: um valor em ponto flutuante, um ponteiro para vetor e a posicao onde o valor sera inserido
  Saida: 1, se a posicao for valida, 0 caso contrario
  Pre-condicao: o ponteiro tem que ser valido
  Pos-condicao: o valor na posicao eh modificado
*/
int inserir(float valor, Vetor *vet, int pos)
{
  if (pos < 0 || pos >= vet->tamanho)
    return 0;

  vet->dados[pos] = valor;
  return 1;
}

/*
  Entrada: um ponteiro para vetor, uma posicao e um valor em ponto flutuante passado por referencia
  Saida: 1, se a posicao for valida, 0 caso contrario
  Pre-condicao: o ponteiro tem que ser valido
  Pos-condicao: a variavel valor eh modificada
*/
int acessar(Vetor *vet, int pos, float *valor)
{
  if (pos < 0 || pos >= vet->tamanho)
    return 0;

  *valor = vet->dados[pos];
  return 1;
}

/*
  Entrada: um ponteiro para vetor
  Saida: tamanho do vetor
  Pre-condicao: ponteiro tem que ser valido
  Pos-condicao: nao existe
*/
int tamanho(Vetor *vet) {
  return vet->tamanho;
}
/*Entrada: um ponteiro para vetor e um inteiro.
Saida: não há.
Pre-condicao: o ponteiro para vetor tem que ser válido e a posição "index" deve ser uma posição válida dentro do vetor.
Pos-condicao: o elemento na posição "index" é removido do vetor, e todos os elementos seguintes são movidos uma posição para a esquerda.
*/
void apagaElemento(Vetor *arr,int index)
{

    for(int i = index;i < tamanho(arr)-1;i++)
    {
        float x;
        acessar(arr, i+1, &x);
        inserir(x, arr, i);

    }
    arr->tamanho -=1;
}
