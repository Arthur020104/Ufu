#include <stdio.h>
#include <stdlib.h>

float Ackerman(float m, float n)
{
    if(m==0)
    {
        return n+1;
    }
    else if(m > 0 && n==0)
    {
        return Ackerman(m-1,1);
    }
    else if(m > 0 && n>0)
    {
        return Ackerman(m-1,Ackerman(m,n-1));
    }
}
void main(void)
{
    printf("%f",Ackerman(1,2));
}