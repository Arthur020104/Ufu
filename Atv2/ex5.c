#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUANTIDADE 21
void main(void)
{
    char temp[12];
    printf("Antes de ordenar:\n=====================\n");
    char string[QUANTIDADE][12] = { "Vinicius", "Guilherme", "Vitor", "Lucas", "Igor", "Joao", "Pedro", "Abel", "Luiz", "Wemerson", "Rafael", "Pablo", "Saint", "Thais", "Matheus", "Douglas", "Gabriel", "Viviane", "Reginaldo", "Jose", "Leonardo"};
    printf("Antes de ordenar:\n=====================\n");
    for (int i = 0; i < QUANTIDADE; i++)
        printf("%s\n",string[i]);

    for(int  i =0;i<QUANTIDADE;i++)
    {
        for(int j = (QUANTIDADE-2);j>=0;j--)
        {
            if(strcmp(string[j+1],string[j])< 0)
            {
                char tmp[30];
                for(int h =0;h<12;h++)
                {
                    tmp[h] = string[j][h];
                    string[j][h] = string[j+1][h];
                    string[j+1][h] = tmp[h];
                }
            }
        }
    }
    printf("\n\nApos ordenar:\n=====================\n");
    for (int i = 0; i < QUANTIDADE; i++)printf("%s\n",string[i]);
        return;
}
