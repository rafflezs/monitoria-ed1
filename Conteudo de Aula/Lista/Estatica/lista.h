typedef struct lista Lista;

Lista * criar_lista();
void	remover_lista(Lista **l);
int inserir_inicio(Lista *l, int vlr);
int trocar_itens(Lista *l, int pos1, int pos2);
int remover_inicio(Lista *l);
int inserir_posicao(Lista *l, int pos, int vlr);
int inserir_apos(Lista *l, int vlr_b, int vlr_i);
int inserir_antes(Lista *l, int vlr_b, int vlr_i);
int inserir_fim(Lista *l, int vlr);
int remover_por_valor(Lista *l, int vlr);
int remover_fim(Lista *l);
int * buscar_elemento(Lista *l, int vlr);
void mostrar_lista(Lista *l);
int obter_qtd(Lista *l);
float obter_media_dos_elementos(Lista *lista);
int * obter_maior_elemento(Lista *lista);
int obter_qtd_elementos_pares(Lista *lista);
