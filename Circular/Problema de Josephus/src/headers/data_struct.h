#ifndef _DATA_STRUCT_H
#define _DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct circulo Circulo;

typedef struct soldado Soldado;

//** Instanciadores
Soldado* criarSoldado( int id);
Circulo* criarCirculo();
Soldado* obterSoldado();

//** Inserts
int inserirSoldado(Circulo* c, Soldado* s);

//** Parametrização
int sortearInicial(Circulo* c, int n);

//** Main Loop (gerar roda de Josephus)
void iniciarRodaDeJosephus(Circulo* c, int n);
int removerSoldado(Circulo* c, Soldado* s);
Soldado* sortearProximo(Circulo* c,int n);

//** Display
void exibirSoldados(Circulo* c);

#endif