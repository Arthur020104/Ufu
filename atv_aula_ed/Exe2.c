#include <stdio.h>
#include <stdlib.h>

int Comb(int n, int k)
{
    if (k == n)
    {
        return 1;
    }
    else if (k == 1)
    {
        return n;
    }
    else if (k > 1 && k < n)
    {
        return Comb(n - 1, k - 1) + Comb(n - 1, k);
    }

    return 0; // Adicionado um retorno padrão para evitar avisos de compilador
}
void main(void)
{
    printf("%d",Comb(10,4));
}