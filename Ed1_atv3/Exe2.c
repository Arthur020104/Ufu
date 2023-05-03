/* 
 * Entrada: uma pilha P e um caractere x
 * Saída: 1, caso x esteja presente em P; 0, caso contrário
 * Pré-condição: não existe
 * Pós-condição: não existe
 */

// A função AchaNaPilha recebe uma pilha P e um caractere x como entrada
int AchaNaPilha(Pilha *P,char x)
{
    Pilha P1;
    // Enquanto a pilha P não estiver vazia:
    while(!vazia(P))
    {
        char n ;
        desempilhar(P,&n);

        if(n != x)
        {
            empilhar(&P1,n);
        }
    }
    while(!vazia(P1))
    {
        char n;
        desempilhar(P1,&n);
        empilhar(P,n);
    }

    if(P->nro_elementos != P1.nro_elementos)
    {
        return 1;
    }
    // Caso o elemento x não tenha sido encontrado na pilha P, retorna 0:
    return 0;
}
