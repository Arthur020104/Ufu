typedef struct Fila
{
    int frst, lst, sizCons, sizMax;
    int values[6];
} Fila;

void printFila(struct Fila x);
int proxPosFila(struct Fila *x, int n);
void adicionaFila(struct Fila *f, int val);
int filaCheia(struct Fila *f);
int filaVazia(struct Fila *f);
int retireUm(struct Fila *x);
Fila criaFila();