typedef struct filaP FilaP;

FilaP * criar_fila();
int * primeiro(FilaP *fila);
int enfileirar(FilaP *fila, int valor, int prioridade);
int desenfileirar(FilaP *fila);
void remover_fila(FilaP **fila);
void limpar_fila(FilaP *fila);
int tamanho_da_fila(FilaP *fila);
int fila_vazia(FilaP *fila);
int fila_cheia(FilaP *fila);
void mostrar_fila(FilaP *fila);

