#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "pilha_ponteiro.h"

/*
A função acharContDiv realiza a operação para descobrir a quantidade de divisões a ser feita
e retorna esse valor para uma variável que vai recebê-la definindo o tamanho do array que
representa a quantidade caracteres a ser utilizado para representar o numero binário.
*/

int acharContDiv(int n){
	
	return (log10(n)/log10(2)) + 1;
	
}

/*
A função converterDecimal vai empilhar elementos na pilha "n(qntDiv)" vezes(onde "n" 
corresponde à quantidade de divisões feitas, ou ainda a quantidade de itens na pilha)
à medida que coleta os restos das operações obtendo assim o número em binário.
*/

void converterDecimal(TPilha *p, int contDiv, int n){
	
	int restoDiv,i;
	
	for(i = contDiv;i > 0;i--){
		restoDiv = n % 2;
		empilha(p,restoDiv);
		n = n / 2;
	}
}

/*
A função imprimirPilha vai desempilhar a pilha "n(qntDiv)" vezes(onde "n" 
corresponde à quantidade de divisões feitas, ou ainda a quantidade de itens na pilha)
e em seguida imprimir elemento por elemento.
*/

void imprimirPilha(TPilha *p, int contDiv,int n){
	
	int i;
	
	printf("\nO número %d convertido em binário é: ", n);
	if(n == 0)
        printf("0000");
    
	else{
    	for(i = contDiv;i > 0;i--)
    		printf("%d", desempilha(p));
    		
    	printf("\n\n---------------------------------------------------------");
    }
	
}

int main(int argc, char *argv[]){
	
	//Usado para atribuir acentuação nas impressões(printf's)
	
	setlocale(LC_ALL,"Portuguese");
	
	//Criação de variáveis
	
	int n=0,contDiv=0;
	
	//Apresentação do programa
	
	printf("Bem Vindo à Calculadora Binária"
	"\n\nObservação: Para Sair digite um número negativo");
	
	//Laço de repetição para rodar o programa até o usuário digitar um número negativo
	
	do{
		printf("\n\nInforme o número a ser convertido: ");
		scanf("%d", &n);
		
		//Condicional para identificar o fim do programa ou reexecução
		
		if(n < 0){
			printf("\nVocê optou por encerrar o programa.");
			return 0;
		}else
			printf("\nVocê optou por converter um número.\n");
		
		//Chamada de criação da pilha
		
		TPilha p;
		
		//Chamada da função de iniciar pilha
		
		inicPilha(&p,n);
		
		//Função para descobrir a quantidade de divisões feitas para definir o tamanho do array
		
		contDiv = acharContDiv(n);
		
		//Função para converter o número decimal em binário
		
		converterDecimal(&p,contDiv,n);
		
		//Função para desempilhar e imprimir a pilha
		
		imprimirPilha(&p,contDiv,n);
		
	}while(n>=0);
	
	return 0;
}