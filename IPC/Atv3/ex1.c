#include <stdio.h>
#include <stdlib.h>
float CalcIMC(float altura, float peso);
void main(void)
{
    float peso,altura;
    printf("Digite seu peso (kg):");
    scanf("%f",&peso);
    printf("Digite sua altura (metros):");
    scanf("%f",&altura);
    printf("%f",CalcIMC(altura,peso));
}
float CalcIMC(float altura, float peso)
{
    return (peso/(altura*altura));
}