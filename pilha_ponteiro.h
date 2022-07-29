#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

/*
O código .h serve para chamar as funções linkadas no .c da biblioteca.
*/

typedef struct TipoElemento{
	int valor;
	struct TipoElemento *abaixo;
	
}TElemento;

typedef struct TipoPilha{
	TElemento *topo, *base;
	
}TPilha;

void inicPilha(TPilha *p, int tam);

int pilhaVazia(TPilha *p);

int pilhaCheia(TPilha *p);

int empilha(TPilha *p, int x);

int desempilha(TPilha *p);

int topoPilha(TPilha *p);

int menu();

