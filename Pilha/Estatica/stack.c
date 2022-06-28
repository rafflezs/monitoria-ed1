#include

struct Pilha
{

  int topo; /* posiÃ§Ã£o elemento topo */
  int capa;
  float *pElem;
};

void criarPilha(struct Pilha *p, int c)
{

  p->topo = -1;
  p->capa = c;
  p->pElem = (float *)malloc(c * sizeof(float));
}

int estaVazia(struct Pilha *p)
{

  if (p->topo == -1)

    return 1; // true

  else

    return 0; // false
}

int estaCheia(struct Pilha *p)
{

  if (p->topo == p->capa - 1)

    return 1;

  else

    return 0;
}

void empilhar(struct Pilha *p, float v)
{

  p->topo++;
  p->pElem[p->topo] = v;
}

float desempilhar(struct Pilha *p)
{

  float aux = p->pElem[p->topo];
  p->topo--;
  return aux;
}

float retornaTopo(struct Pilha *p)
{

  return p->pElem[p->topo];
}
