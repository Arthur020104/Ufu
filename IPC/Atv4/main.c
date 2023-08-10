/*Nome:Arthur Carvalho Oliveira
Matricula:12211BSI220*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // biblioteca time.h
#include <string.h>
struct funcionario{
    char cpf[12],nome[30];
    time_t entrada;
    time_t saida;
    char status;

};
struct funclog{
    char cpf[12];
    time_t horario;
    char evento;
 
};
void registro(FILE *funcionarios, FILE *log) {
    struct funcionario funcio;
    printf("Cpf:\n");
    scanf("%s",funcio.cpf);
    rewind(funcionarios);
    struct funclog login;
    struct funcionario x;
    while(1)
    {
    fread(&x,sizeof(struct funcionario),1,funcionarios);
    if(feof(funcionarios))
    {
        break;
    }
    if(strcmp(funcio.cpf,x.cpf)==0)
    {
        printf("Evento[E:Entrada,S:Saida]:\n");
        fflush(stdin);
        scanf("%c",&login.evento);
        if(login.evento=='E')
        {
        x.entrada = time(NULL);
        x.status = 'P';
        }
        else
        {
        x.saida = time(NULL);
        x.status = 'A';
        }
        strcpy(login.cpf,x.cpf);
        login.horario = time(NULL);
        fseek(funcionarios, -1 * (int)sizeof(struct funcionario),SEEK_CUR);
        fwrite(&x,sizeof(struct funcionario),1,funcionarios);
        fwrite(&login,sizeof(struct funclog),1,log);
        return;
    }
    }
    login.evento = 'E';
    login.horario = time(NULL);
    fwrite(&login,sizeof(struct funclog),1,log);
    funcio.entrada= time(NULL);
    funcio.status = 'P';
    printf("Nome:\n");
    scanf("%s",funcio.nome); 
    fwrite(&funcio,sizeof(struct funcionario),1,funcionarios);
    return;
 

}
 
void listagem_funcionarios(FILE *funcionarios) {
    rewind(funcionarios);
    struct funcionario x;
    while(1)
    {
    fread(&x,sizeof(struct funcionario),1,funcionarios);
    if(feof(funcionarios))
    {
        break;
    }
    printf("Nome:%s\n", x.nome);
    printf("Cpf:%s\n", x.cpf);
    printf("Status:%C\n", x.status);
    if(x.status=='P')
    {
        printf("%s\n", ctime(&x.entrada));
    }
    else
    {
        printf("%s\n", ctime(&x.saida));
    }
    }
}
void listagem_log(FILE *log) {
    rewind(log);
    struct funclog x;
    while(1)
    {
    fread(&x,sizeof(struct funclog),1,log);
    if(feof(log))
    {
        break;
    }
    printf("Cpf:%s\n", x.cpf);
    printf("Horario:%s\n", ctime(&x.horario));
    printf("Evento:%c\n", x.evento);
    }
}
int main() {
    FILE *funcionarios;
    FILE *log;
    funcionarios = fopen("funcionarios.bin","rb+");
    log = fopen("log.bin","rb+");
    if(!funcionarios || !log)
    {
    funcionarios = fopen("funcionarios.bin","wb+");
    log = fopen("log.bin","wb+");
    if(!funcionarios || !log)
    {
        printf("Error\n");
        return 1;
    }
    }
    // a partir daqui nesta função main() o código não deve ser alterado
    int opcao;
    do {
    printf("\n\n 0-sair\n 1-registro entrada/saida\n 2-lista funcionarios\n 3-lista log\n");
    printf("\n Opcao: "); scanf(" %d",&opcao);
    switch(opcao) {
        case 1: registro(funcionarios,log); break;
        case 2: listagem_funcionarios(funcionarios); break;
        case 3: listagem_log(log); break;
        printf("\n\n\n");
    }
    } while (opcao != 0);
    fclose(funcionarios);
    fclose(log);
    return 0;
}