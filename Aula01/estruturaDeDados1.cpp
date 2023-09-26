///////////////////////////////////////
//Programa de preenchimento de vetor///
///////////////////////////////////////

//Importacao de pacotes
#import <stdio.h>

//Declaracao de variaveis
int vetor[10];
int i = 0;
int z =0;
int vetorInvertido[10];

//////////////////////////////////////////
//Funcao principal de execucao de codigo//
//////////////////////////////////////////

int main(){
	//Limpeza da memoria
	for (i=0;i<10;i++){
		vetor[i] = 0;
	}
	//Preenchimento do vetor
	for(i=0;i<10;i++){
		printf("Digite o valor da posicao %d do vetor: ", i);
		scanf("%d", &vetor[i]);
	}
	//Impressao do vetor
	for (i=0;i<10;i++){
		printf("vetor[%d] = %d\n",i,vetor[i]);
	}
	//Inversao do vetor
	for(i=9;i>=0;i--){
		vetorInvertido[9-i] = vetor[i];
	}
	//Impressao do vetor invertido
	for (i=0;i<10;i++){
		printf("vetor[%d] = %d\n",i,vetorInvertido[i]);
	}
}
