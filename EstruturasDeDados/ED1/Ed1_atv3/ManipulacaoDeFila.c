#include<stdlib.h>
#include<stdio.h>

#define  MAX  5 // Tamanho

// Definir a ED fila
struct fila {
	int primeiro;
	int final;
	int nro_elementos;
	char elementos[MAX];
};
typedef struct fila fila;
int retirarNaOrdemInversa(fila *f, char *x);
int retirarNaOrdem(fila *f, char *x);
int inserirNaOrdem(fila* F, char x);
int inserirNaFrente(fila *f, char x);
// Definir o tipo de dados fila


/*
  Entrada: nao existe
  Saida: ponteiro para fila, ou NULL caso nao seja possivel cria-la
  Pre-condicao: nao existe
  Pos-condicao: nao existe
*/
fila *criar()
{
	
	fila *f;

	f = malloc(sizeof(fila));
	if (f != NULL) {
		f->primeiro = 0;
		f->final = 0;
		f->nro_elementos = 0;
	}

	return f;
}

/* 
 * Entrada: uma fila
 * Saida: nao existe
 * Pre-condicao: nao existe
 * Pos-condicao: memoria da fila liberada
 */
void destruir(fila *f)
{
	if (f != NULL) free(f);
}

/*
 * Entrada: uma fila
 * Saida: 1 se a fila for vazia, 0 caso contrario
 * Pre-condicao: fila deve ser valida
 * Pos-condicao: nao existe
 */
int vazia(fila *f)
{
	if (f->nro_elementos == 0) return 1; // true
	else return 0; // false
}

/*
 * Entrada: uma fila
 * Saida: 1 se a fila for cheia, 0 caso contrario
 * Pre-condicao: fila deve ser valida
 * Pos-condicao: nao existe
 */
int cheia(fila *f)
{
	if (f->nro_elementos == MAX) return 1; // true
	else return 0; // false
}

/*
 * Entrada: uma fila e um caractere
 * Saida: 1 se bem sucedida, 0 caso contrario
 * Pre-condicao: fila tem que ser valida e caractere tambem
 * Pos-condicao: conteudo da pilha alterado
 */
int inserirNaFrente(fila *f, char x)
{
    //if (cheia(f))
	if (cheia(f) == 1)
		return 0;	// false
	else {
		f->nro_elementos ++;
        int n = f->primeiro-1;
        if(n <0)
        {
            n = MAX-1;
        }
        f->primeiro =n;
		f->elementos[ n] = x;
		
		return 1;	// true
	}
}
/*
 * Entrada: uma fila e um caractere
 * Saida: 1 se bem sucedida, 0 caso contrario
 * Pre-condicao: fila tem que ser valida e caractere tambem
 * Pos-condicao: conteudo da pilha alterado
 */
int inserirNaOrdem(fila* f, char x)
{
   if (cheia(f) == 1)
		return 0;	// false
	else {
		f->nro_elementos = f->nro_elementos + 1;
		f->elementos[ f->final ] = x;
		
		// avanca o indice Final. Atencao: o vetor eh circular
		if (f->final == (MAX-1))
		    f->final = 0;
		else
		    f->final = f->final + 1;
		
		return 1;	// true
	}
}
/*
 * Entrada: uma fila e um caractere passado por referencia
 * Saida: 1 se bem sucedida, 0 caso contrario
 * Pre-condicao: fila tem que ser valida
 * Pos-condicao: conteudo da fila alterado
 */
int retirarNaOrdemInversa(fila *f, char *x)
{
	if (vazia(f) == 1)
		return 0;	// false
	else {
	    f->nro_elementos = f->nro_elementos - 1;
	    *x = f->elementos[ f->final ];
	    
	    if (f->final < 0)
	        f->final = MAX - 1;
	    else f->final--;
		
		return 1;	// true
	}
}
/*
 * Entrada: uma fila e um caractere passado por referencia
 * Saida: 1 se bem sucedida, 0 caso contrario
 * Pre-condicao: fila tem que ser valida
 * Pos-condicao: conteudo da fila alterado
 */
int retirarNaOrdem(fila *f, char *x)
{
	if (vazia(f) == 1)
		return 0;	// false
	else {
	    f->nro_elementos = f->nro_elementos - 1;
	    *x = f->elementos[ f->primeiro ];
	    
	    if (f->primeiro == (MAX-1))
	        f->primeiro = 0;
	    else f->primeiro = f->primeiro + 1;
		
		return 1;	// true
	}
}

int main()
{
	fila *F;
	char c;

	int teste;

	F = criar();
	if (F == NULL) {
		printf("Erro: nao foi possivel criar a pilha\n");
		exit(-1);
	}

	for (int i = 0; i < 2; i++) {
		printf("Digite um caractere: ");
		scanf(" %c", &c);

		inserirNaOrdem(F, c);
	}
    printf("\nInserir na frente:");
    scanf(" %c", &c);
    inserirNaFrente(F,c);
    printf("\nInserir na ordem:");
    scanf(" %c", &c);
    inserirNaOrdem(F,c);
    //while (!cheia(F)) {
	/*while (cheia(F) == 0) {
		printf("Digite um caractere: ");
		scanf(" %c", &c);
		inserir(F, c);
	}*/
    char y;
	while (retirarNaOrdem(F, &y) == 1)
		printf("%c\n", y);

	destruir(F);

	return 0;
}