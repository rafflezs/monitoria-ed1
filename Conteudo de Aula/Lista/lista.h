
typedef struct lista Lista;

Lista * criar_lista();
void remover_lista(Lista **lista);
int inserir_inicio(Lista *lista, int valor);
int inserir_fim(Lista *lista, int valor);
int inserir_ordenado(Lista *lista, int valor);
int inserir_na_posicao(Lista *lista, int valor, int pos);
int inserir_apos(Lista *l, int vlr_b, int vlr_i);
int remover_inicio(Lista *lista);
int remover_fim(Lista *lista);
int remover_por_valor(Lista *lista, int valor);
int remover_na_posicao(Lista *lista, int pos);
void concatenar_lista(Lista *lista1, Lista *lista2);
void intercalar_lista(Lista *lista1, Lista *lista2);
int buscar_elemento(Lista *lista);
void mostrar_lista(Lista *lista);


