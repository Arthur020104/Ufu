#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Class struct
Class Conta
{
    //
    char nome[20];//Poderia ser objeto Usuario
    float saldo;
    void(*MostarConta)(Class Conta*);
    int(*Deposito)(float,Class Conta*);
    int(*Saque)(float, Class Conta*);
    int(*Transferencia)(float,Class Conta*,Class Conta*);
};
int Transferencia(float valorDeTransferencia, Class Conta* recebeTransferencia,Class Conta* enviaTransferencia)
{   
    int vereficaSeTranferenciaEPossivel = valorDeTransferencia <= enviaTransferencia->saldo && valorDeTransferencia > 0 && strcmp(recebeTransferencia->nome,enviaTransferencia->nome) !=0;
    if(vereficaSeTranferenciaEPossivel)
    {
        enviaTransferencia->saldo -= valorDeTransferencia;
        recebeTransferencia->saldo += valorDeTransferencia;
        return 0;
    }

    return 1;
}
int Deposito(float valorDoDeposito,Class Conta* conta)
{
    if(valorDoDeposito > 0)
    {
        conta->saldo += valorDoDeposito;
        return 0; 
    }

    return 1;
   
}
int Saque(float valorDeSaque, Class Conta* conta)
{
    if(valorDeSaque <= conta->saldo && valorDeSaque > 0)
    {
        conta->saldo -= valorDeSaque;
        return 0;
    }
    return 1;
}
void DisplayConta(Class Conta* conta)
{
    printf("\nConta de %s.\nO saldo e de %.2f reais",conta->nome,conta->saldo);
}
Class Conta* CriaConta(char* nome)
{
    Class Conta* conta = (Class Conta*) malloc(sizeof(Class Conta));
    strcpy(conta->nome,nome);
    conta->saldo = 0;
    conta->MostarConta = &DisplayConta;
    conta->Deposito = &Deposito;
    conta->Saque = &Saque;
    conta->Transferencia = &Transferencia;
    return conta;
}
void main(void)
{
    Class Conta* conta = CriaConta("Arthur");
    Class Conta* conta2 = CriaConta("Cleiton");
    conta->MostarConta(conta);

    conta->Deposito(100.5,conta);

    conta->MostarConta(conta);

    conta->Saque(25.2,conta);

    conta->MostarConta(conta);

    conta2->MostarConta(conta2);

    conta->Transferencia(55.3,conta2,conta);

    conta->MostarConta(conta);

    conta2->MostarConta(conta2);
    
    free(conta);
    free(conta2);
}