#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double arredondar(double num, int casasDecimais) {
    double fator = pow(10, casasDecimais);
    return round(num * fator) / fator;
}
double sqrtB(float n, double lower, double upper)
{
    double x = lower + ((upper - lower) / 2);
    x = arredondar(x,12);

    if (((float)n) == ((float)(x * x)))
    {
        return x;
    }
    else if (x * x > n)
    {
        return sqrtB(n, lower, x);
    }
    else if (x * x < n)
    {
        return sqrtB(n, x, upper);
    }
 // Adicionado um retorno padrão para a função sqrtB
}

int main(void)
{
    float n;
    printf("Deseja calcular raiz quadrada de qual numero: ");
    scanf("%f",&n);
    if(n >= 1)
    {
        printf("Resultado:%f", sqrtB(n, 1.0, n));
    }
    else
    {
        printf("Resultado:%f", sqrtB(n, n, 1));
    }
    return 0;
}
