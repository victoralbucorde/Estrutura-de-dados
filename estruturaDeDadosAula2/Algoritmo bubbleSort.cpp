//Programa ordena��o bubblesort

//Importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declara��o de variaveis
int vetor[10000];
int i = 0;
time_t t;
int temp;
int troquei;

//Fun��o principal do programa
int main(){
//Inicializa��o da aleatoriedade
	srand((unsigned) time(&t));
//Inicializa��o do vetor
	for(i=0;i<10000;i++){
		vetor[i]=(rand() % 10000);
	}
	
//Impress�o do vetor
	for(i=0;i<10000;i++){
		printf("%d\n", vetor[i]);
	}
//Ordena��o propriamente dita
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
