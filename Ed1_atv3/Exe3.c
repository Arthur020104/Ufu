/* 
 * Entrada: uma fila e uma pilha
 * Saída: não existe
 * Pré-condição: a fila deve conter elementos
 * Pós-condição: fila invertida
 */

// A função Inverte recebe uma pilha P e uma fila F como parâmetros
void Inverte(Pilha *P, Fila *F)
{
    // Enquanto a fila não estiver vazia:
    while(!vazia(F))
    {
        char x;
        // Retira o primeiro elemento da fila e o armazena em x:
        retirar(F,&x);
        // Empilha o elemento x na pilha P:
        empilhar(P,x);
    }
    // Enquanto a pilha P não estiver vazia:
    while(!vaziaa(P))
    {
        char x;
        // Desempilha o elemento do topo da pilha P e o armazena em x:
        desempilhar(P,&x);
        // Insere o elemento x no final da fila F:
        inserir(F,x);
    }
    // A função não possui saída explícita
    return;
}

