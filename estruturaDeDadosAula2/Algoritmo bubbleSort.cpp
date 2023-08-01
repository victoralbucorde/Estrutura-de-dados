//Programa ordenação bubblesort

//Importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaração de variaveis
int vetor[10000];
int i = 0;
time_t t;
int temp;
int troquei;

//Função principal do programa
int main(){
//Inicialização da aleatoriedade
	srand((unsigned) time(&t));
//Inicialização do vetor
	for(i=0;i<10000;i++){
		vetor[i]=(rand() % 10000);
	}
	
//Impressão do vetor
	for(i=0;i<10000;i++){
		printf("%d\n", vetor[i]);
	}
//Ordenação propriamente dita
	troquei = 1;
	while(troquei){
		troquei = 0;
		
		for(i=0;i<9999;i++){//do primeiro ao penultimo
			if (vetor[i]>vetor[i+1]){
				temp = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = temp;
				troquei = 1;
			}
		}
	}
//Impressao do vetor
	for(i=0;i<10000;i++){
		printf("%d\n", vetor[i]);
	}
	
}
