/* 
 * Entrada: uma pilha P e um caractere x
 * Saída: 1, caso x esteja presente em P; 0, caso contrário
 * Pré-condição: não existe
 * Pós-condição: não existe
 */

// A função AchaNaPilha recebe uma pilha P e um caractere x como entrada
int AchaNaPilha(Pilha *P,char x)
{
    // Enquanto a pilha P não estiver vazia:
    while(!vazia(P))
    {
        char n ;
        // Desempilha o elemento do topo da pilha P e o armazena em n:
        desempilhar(P,&n);
        // Se o elemento n for igual a x, retorna 1:
        if(n == x)
        {
            return 1;
        }
    }
    // Caso o elemento x não tenha sido encontrado na pilha P, retorna 0:
    return 0;
}
