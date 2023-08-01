//Programa ordenação bubblesort

//Importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaração de variaveis
int vetor[10000];
int i = 0;
time_t t;
int achei;
int busca;

//Função principal do programa
int main(){
//Inicialização da aleatoriedade
	srand((unsigned) time(&t));
//Inicialização do vetor
	for(i=0;i<10000;i++){
		vetor[i]=(rand() % 10000);
	}
//Definicao da pesquisa
	printf("Digite um numero a ser buscado: ");
	scanf("%d", &busca);
	
//Busca propriamente dita
	achei = -1;
	for(i = 0; i < 10000; i++){
		if (vetor[i] == busca){
			achei = i;
		}
	}
	
	if(achei == -1){
		printf("Nao existe.");
	}else{
		printf("Achei na posicao %d", achei);
	}
}
