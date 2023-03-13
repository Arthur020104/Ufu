#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    int a,b;
    int *P1,*P2,**P3;
    float *P4;
    a = 1;
    b=3;
    P1 = &b;
    P2 = P1 = &a;
    *P1 = 20;
    printf("P2:%d -P1:%d - A:%d",*P2,*P1,a);
}