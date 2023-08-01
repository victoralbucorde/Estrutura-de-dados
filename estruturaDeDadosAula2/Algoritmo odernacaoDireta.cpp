//Programa de ordenação direta

//Importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaração de variaveis
int vetor[10000];
int i = 0;
int j = 0;
time_t t;
int temp;
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
	for(i=0;i<9999;i++){ //do primeiro ao penultimo
		for(j=i+1;j<10000;j++){ //do proximo ao ultimo
			if(vetor[j] < vetor[i]){
				temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
		}
	}
//Impressao do vetor
	for(i=0;i<10000;i++){
		printf("%d\n", vetor[i]);
	}
	
}
