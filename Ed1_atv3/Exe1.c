
int FuraFila(Fila* F, char x)
{
    if(cheia(F))
    {
        return 0;
    }
    int n = F->primeiro -1;
    if(n < 0)
    {
        n = MAX -1;
    }
    F->elementos[n] = x;
    F->primeiro=n;
    F->nro_elementos ++;
    return 1;
}
