//Programa que implementa uma arvore AVL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaracao da estrutura do no

struct no{
	int numero;
	struct no *esquerda;
	struct no *direita;
	int altura;
};

//funcao que retorna a altura de um no

int getAlturaDoNo(struct no *raiz){
	return ((raiz == NULL) ? 0 : raiz -> altura);
}

//funcao que retorna o maior entre dois numeros

int getMaximoEntreDoisNumeros(int a, int b){
	return (a > b) ? a : b;
}

//funcao que captura o balanco da arvore

int getBalanco(struct no *raiz){
	int retorno = 0;
	
	if(raiz != NULL){
		retorno = (getAlturaDoNo(raiz -> esquerda) - getAlturaDoNo(raiz -> direita));
	}
	
	return retorno;
}

//funcao que executa a rotacao a esquerda

struct no *rotacaoEsquerda(struct no *raiz){
	struct no *novaRaiz = raiz -> direita;
	struct no *temp = novaRaiz -> esquerda;
	
	novaRaiz -> esquerda = raiz;
	raiz -> direita = temp;
	raiz -> altura = (getMaximoEntreDoisNumeros(getAlturaDoNo(raiz -> esquerda), getAlturaDoNo(raiz -> direita)) + 1);
	novaRaiz -> altura = (getMaximoEntreDoisNumeros(getAlturaDoNo(novaRaiz -> esquerda), getAlturaDoNo(raiz -> direita)) + 1);
	
	return novaRaiz;
}

//funcao que executa a rotacao a direita

struct no *rotacaoDireita(struct no *raiz){
	struct no *novaRaiz = raiz -> esquerda;
	struct no *temp = novaRaiz -> direita;
	
	novaRaiz -> direita = raiz;
	raiz -> esquerda = temp;
	
	raiz -> altura = (getMaximoEntreDoisNumeros(getAlturaDoNo(raiz -> direita), getAlturaDoNo(raiz -> esquerda)) + 1);
	novaRaiz -> altura = (getMaximoEntreDoisNumeros(getAlturaDoNo(novaRaiz -> direita), getAlturaDoNo(raiz -> esquerda)) + 1);
	
	return novaRaiz; 
}

//funcao que insere um novo no na arvore

struct no *inserir(struct no *raiz, int numero){
	if (raiz == NULL){
		raiz = (struct no *) malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz -> esquerda = NULL;
		raiz -> altura = 1;
		raiz -> direita = NULL;
	}else{
		if (raiz -> numero > numero){
			raiz -> esquerda = inserir(raiz -> esquerda, numero);
		}else{
			raiz -> direita = inserir(raiz -> direita, numero);
		}
	}
	
	raiz -> altura = (1 + getMaximoEntreDoisNumeros(getAlturaDoNo(raiz -> esquerda), getAlturaDoNo(raiz -> direita)));
	
	int balanco = getBalanco(raiz);
	
	if((balanco > 1) && (numero < raiz -> esquerda -> numero)){
		raiz = rotacaoDireita(raiz);
	}
	
	if((balanco < -1) && (numero > raiz -> direita -> numero)){
		raiz = rotacaoEsquerda(raiz);
	}
	
	if((balanco > 1) && (numero > raiz -> esquerda -> numero)){
		raiz -> esquerda = rotacaoEsquerda(raiz -> esquerda);
		raiz = rotacaoDireita(raiz);
	}
	
	if((balanco < -1) && (numero < raiz -> direita -> numero)){
		raiz -> direita = rotacaoDireita(raiz -> direita);
		raiz = rotacaoEsquerda(raiz);
	}
	
	return raiz;
}

//funcao que imprime a arvore
void imprimir(struct no *raiz, char *endentador){
	if(raiz != NULL){
		printf("%s%d (A %d)\n",endentador,raiz->numero,raiz->altura);
		char *temp = (char *) malloc(1024 * sizeof(char));
		strcpy(temp, endentador);
		strcat(temp, "---");
		
		imprimir(raiz -> esquerda, temp);
		imprimir(raiz -> direita, temp);
	}
}

//funcao de execucao principal do programa
int main(){
	struct no *raiz = NULL;
	int i = 0;
	
	for(i = 0;i<10;i++){
		raiz = inserir(raiz, i);
	}
	
	imprimir(raiz, "");
}
