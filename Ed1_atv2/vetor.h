struct vetor {
  float dados[10];
  int tamanho;
};

typedef struct vetor Vetor;

Vetor *criar(int tam);
void destruir(Vetor *vet);
int inserir(float valor, Vetor *vet, int pos);
int acessar(Vetor *vet, int pos, float *valor);
int tamanho(Vetor *vet);
void apagaElemento(Vetor *arr,int index);
