
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int STR_LEN = 30;
const int STR_ARR_LEN = 5;

int calculoordem(char s[]);

int main()
{
    char string[5][30];
    for(int i =0;i<STR_ARR_LEN;i++)
    {
        scanf("%s",string[i]);
    }
    char tmp[30];
    for(int i =0;i<STR_ARR_LEN;i++)
    {
        tmp[i] =string[0][i]; 
    }
    for(int j = (STR_ARR_LEN-2);j>=0;j--)
    {
        if(strcmp(string[j+1],string[j])< 0)
        {
            for(int h =0;h<12;h++)
            {
                tmp[h] = string[j+1][h];
            }
        }
    }
    printf("\n\n%s",tmp);
}
