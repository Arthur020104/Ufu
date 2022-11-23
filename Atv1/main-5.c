#include <stdio.h>
/*
Nome:Arthur Carvalho Oliveira
Matrícula:12211BSI220
*/
void main(void)
{
    int velha[3][3] ={{0,0,0},{0,0,0},{0,0,0}};
    int jogador =1;
    int ganhou=0;
    int pos1,pos2;
    do
    {
        for(int i =0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                j==0 ? printf("\n[%d,",velha[i][j]):j==1 ? printf("%d,",velha[i][j]): printf("%d]",velha[i][j]);
            }
        }
        printf("\nJogador %d sua vez: ",jogador);
        printf("\nColuna:");
        scanf("%d",&pos1);
        printf("\nLinha:");
        scanf("%d",&pos2);
        pos1--;
        pos2--;
        if(velha[pos2][pos1]==1||velha[pos2][pos1]==2)
        {
            printf("Voce nao pode subscrever um valor ja digitado");
            continue;
        }
        velha[pos2][pos1] = jogador;
        for(int h =0;h<2;h++)
        {
            for(int i =0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    int valor;
                    h==1 ? valor = velha[j][i] : (valor = velha[i][j]);
                    if(valor ==jogador)
                    {
                        if(j==2)
                        {
                            ganhou = 1;
                            printf("\nO jogador %d GANHOU",jogador);
                            return;
                        }
                        continue;
                    }
                    break;
                }
            }
        }
        for(int h =0;h<2;h++)
        {
            for(int i =0;i<3;i++)
            {
                int valor;
                h==1 ? valor = velha[i][2-i] :( valor = velha[i][i]);
                if(valor ==jogador)
                {
                    if(i==2)
                    {
                        ganhou = 1;
                        printf("\nO jogador %d GANHOU",jogador);
                        return;
                    }
                    continue;
                }
                break;
            }
        }
        (jogador == 1) ? (jogador = 2): (jogador=1);
    }
    while(ganhou!=1);

}