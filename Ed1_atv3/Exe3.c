void Inverte(Pilha *P, Fila *F)
{
    while(!vazia(F))
    {
        char x;
        retirar(F,&x);
        empilhar(P,x);
    }
    while(!vaziaa(P))
    {
        char x;
        desempilhar(P,&x);
       inserir(F,x);

 

    }
    return;
}