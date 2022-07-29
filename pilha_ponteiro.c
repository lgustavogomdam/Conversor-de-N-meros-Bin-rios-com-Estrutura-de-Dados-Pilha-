#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "pilha_ponteiro.h"

/*
InicPilha é a função que vai iniciar ambos os campos
da struct onde topo recebe um valor negativo deixando a pilha vazia.
*/

void inicPilha(TPilha *p, int tam){
	p -> topo = NULL;
	//p -> base = NULL;
}

/*
A função pilhaVazia é chamada normalmente para certificar
de que a pilha não contém elementos retornando "verdadeiro ou falso".
*/

int pilhaVazia(TPilha *p){
	
	if(p->topo == NULL)
		return (1);
	else
		return (0);
}

/*
A função pilhaCheia é chamada normalmente para certificar
se a pilha cabe ou não mais indexações de elementos retornando "verdadeiro ou falso".
*/

/*int pilhaCheia(Spilha *p){
	
	if(p->topo == (p->tam - 1))
		return (1);
	else
		return (0);
}*/

/*
A função empilha vai verificar se a pilha cabe mais indexações de elementos, caso esteja vazia
ela indexa no topo da pilha um novo valor, caso contrario ela procura pelo elemento do topo e indexa acima deste o elemento passado como parametro.
*/

int empilha(TPilha *p, int x){
	
	TElemento *novo = (TElemento *)malloc(sizeof(TElemento));
	novo -> valor = x;
	
	if(pilhaVazia(p)){
		p->topo = novo;           
//		p->base = novo;
		novo->abaixo = NULL;
	}else{
//		novo->valor = x;
//		p->topo->acima = novo;
		novo->abaixo = p->topo;
		p->topo = novo;
	}
//	novo->acima = NULL;
}

/*
A função desempilha vai verificar se a pilha não está vazia e desempilhará um elemento com a juda de u auxiliar, logo após ele libera a memória alocada para aquele elemento.
*/

int desempilha(TPilha *p){
	
	TElemento *desempilhado = NULL;
	int num_desempilhado;
    
	if (!pilhaVazia(p)){
		
		desempilhado = p->topo;
		p->topo =p->topo->abaixo;
		
	}else{

		printf("Ocorreu Underflow na pilha");
		return 0;
	
	}
    num_desempilhado = desempilhado -> valor;
	free(desempilhado);
    
	return num_desempilhado;
}

/*
A função topoPilha vai verificar se o elemento do topo da pilha não é o valor negativo(que indica que a pilha está vazia),
caso não seja ela retorna o elemento que se encontra no topo da pilha.
*/

int topoPilha(TPilha *p){
	int valor;
	if (pilhaVazia(p) == 1){
		printf("Ocorreu Underflow na pilha");
		return (0);
	}else
		return valor = p->topo->valor;
}

/*
inicia um breve menu indicando as funcionalidades.
*/

int menu(){
	
	int opcao;
	
	printf("\n\n\t\tBem Vindo ao Menu\t\t\n\n"
	"Suas opções de seleção são:\t");
	printf("\n\n0- Sair(Encerrar o programa).\t");
	printf("\n\n1- Empilhar(PUSH).\t");
	printf("\n\n2- Desempilhar(POP).\t");
	printf("\n\n3- Consultar elemento no topo da pilha.\t\n\n");
	printf("\n\nDigite aqui a op�o desejada: .\t");
	scanf("%d", &opcao);
	
	do{
	
	printf("\n\nERRO, voc� digitou um numero inv�lido.\t");
	printf("\n\nPor favor, digite aqui a op�o desejada de acordo com o menu: .\t");
	scanf("%d", &opcao);
	
	}while((opcao < 0) || (opcao > 3));
	
	return opcao;

}
