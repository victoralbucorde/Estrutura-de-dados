//Programa de ordena��o direta

//Importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declara��o de variaveis
int vetor[10000];
int i = 0;
int j = 0;
time_t t;
int temp;
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
