#include "../headers/menu.h"

int contador = 0;

void drive()
{
  Circulo *c = criarCirculo();
int opt;
  do
  {
  opt = menu();
    switch (opt)
    {
    case 1:
    {

      // char nome[30];
      // scanf("%[^\n]s", nome);
      if(inserirSoldado(c, criarSoldado(contador))){
        printf("Soldado %d inserido corretamente\n", contador);
        contador++;
      } else {
        printf("Houve problemas na inserção.\n");
      }
    }
    break;

    case 2:
    {
      printf("\n ------ LISTA DE SOLDADOS ------\n");
      exibirSoldados(c);
    }
    break;

    case 3:
    {
      int n = 0;
      printf("\nInsira uma contagem n: ");
      scanf("%d", &n);
      sortearInicial(c,n);
    }
    break;

    case 4:
    {
      int n = 0;
      printf("\nInsira uma contagem n: ");
      scanf("%d", &n);
      iniciarRodaDeJosephus(c,n);
    }
    break;

    default:
      break;
    }

  } while (opt != 0);
}

int menu()
{

  printf("\n---------- MENU ----------\n");
  printf("1 - Inserir Soldado\n");
  printf("2 - Mostrar Soldados\n");
  printf("3 - Sortear Soldado que iniciará a contagem\n");
  printf("4 - Iniciar Josephus\n");
  printf("\nInsira sua opção: ");

  int opt;
  scanf("%d", &opt);
  return opt;
}