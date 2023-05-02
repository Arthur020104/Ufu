int AchaNaPilha(Pilha *P,char x)
{
    while(!vazia(P))
    {

 

        char n ;
        desempilhar(P,&n);
        if(n == x)
        {
            return 1;
        }
    }
    return 0;
}

 