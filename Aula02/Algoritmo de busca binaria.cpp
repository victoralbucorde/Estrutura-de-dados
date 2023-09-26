//Programa de busca binaria

//Importação de bibliotecas
#include <stdio.h>

//Declaração de variaveis
int vetor[10000];
int i = 0;
int busca = 0;
int inicio = 0;
int meio = 0;
int fim = 0;

//Função principal do programa
int main(){
//Inicialização do vetor
	for(i=0;i<10000;i++){
		vetor[i] = i;
	}
//Definicao de busca
	printf("Digite o numero a ser buscado: ");
	scanf("%d", &busca);

//Busca propriamente dita
	inicio = 0;
	fim = 9999;
	
	while(fim >= inicio){
		meio = (inicio + fim) / 2;
		
		if(vetor[meio] == busca){
			printf("Achei!!!!");
			return 0;
		}else if(vetor[meio] > busca){
			fim = (meio - 1);
		}else{
			inicio = (meio + 1);
		}
	}
	printf("Nao foi encontrado");
}
