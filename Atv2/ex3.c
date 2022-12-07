#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int STR_LEN = 30;
const int STR_ARR_LEN = 20;

int calculoordem(char s[]);

int main()
{
    char string[20][30];
    for(int i =0;i<STR_ARR_LEN;i++)
    {
        scanf("%s",string[i]);
    }
    for(int  i =0;i<STR_ARR_LEN;i++)
    {
        for(int j = (STR_ARR_LEN-2);j>=0;j--)
        {
            if(calculoordem(string[j])>calculoordem(string[j+1]))
            {
                char tmp[30];
                for(int h =0;h<STR_LEN;h++)
                {
                    tmp[h] = string[j][h];
                    string[j][h] = string[j+1][h];
                    string[j+1][h] = tmp[h];
                }
            }
        }
    }
    printf("\n\nStrings ordenadas:");
    for(int i =0;i<STR_ARR_LEN;i++)
    {
        printf("%s\n",string[i]);
    }
}
int calculoordem(char s[])
{
    int soma = 0;
    for(int i=0;i<STR_LEN;i++)
    {
        if(s[i]=='\0')
        {
            break;
        }
        int c = (int)s[i];
        if(c < 97)
        {
            soma += i==0 ? 10000 *(c+32) : (STR_LEN-i*2) <=0 ? 1 *(c+32): (STR_LEN-i*2) *(c+32);
            continue;
        }
        soma += i==0 ? 10000 *(c) : (STR_LEN-i*2) <=0 ? 1 *(c): (STR_LEN-i*2) *(c);
    }
    return soma;
}

