
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Nome:Arthur Carvalho Oliveira
Matrícula:12211BSI220
*/

const int STR_LEN = 30;
const int STR_ARR_LEN = 5;

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
    for(int i = 0;i<STR_ARR_LEN;i++)
    {
        if(strcmp(string[i],tmp)< 0)
        {
            for(int h =0;h<STR_LEN;h++)
            {
                tmp[h] = string[i][h];
            }
        }
    }
    printf("\n\n%s",tmp);
}
