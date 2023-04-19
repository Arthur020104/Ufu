#include <stdio.h>
#include <stdlib.h>


int mdc(int a ,int b)
{
    if(b==0)
    {
        return a;
    }
    else{
        mdc(b,a%b);
    }
}
void main(void)
{
    printf("%d",mdc(24,36));
}