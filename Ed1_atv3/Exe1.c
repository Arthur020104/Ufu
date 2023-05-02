/* 
 * Entrada: uma fila F e um caractere x
 * Saída: inteiro indicando se o elemento foi adicionado ou não (1: adicionado; 0: não adicionado)
 * Pré-condição: a fila F não deve estar cheia
 * Pós-condição: o elemento x é adicionado ao início da fila F
 */

// A função FuraFila adiciona um novo elemento x ao início da fila F:
int FuraFila(Fila* F, char x)
{
    // Verifica se a fila está cheia:
    if(cheia(F))
    {
        return 0;
    }
    // Calcula o índice do novo primeiro elemento:
    int n = F->primeiro -1;
    if(n < 0)
    {
        n = MAX -1;
    }
    // Insere o novo elemento no início da fila:
    F->elementos[n] = x;
    // Atualiza o índice do primeiro elemento da fila:
    F->primeiro=n;
    // Incrementa o número de elementos da fila:
    F->nro_elementos ++;
    // Retorna 1, indicando que o elemento foi adicionado com sucesso:
    return 1;
}