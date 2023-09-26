//Programa de duplamente lista encadeada

//importa��o de pacotes
#include <stdio.h>
#include <stdlib.h>

//Defini��o da estrutura do n�
struct no{
	int numero;
	struct no *proximo;
	struct no *anterior;
};

//Declara��o de variaveis
struct no *cabeca = NULL;

//Funcao que insere um n� na lista
void inserir(int parametroNumero){
	//Instancia��o da mem�ria
	struct no *novoNo = (struct no *) malloc(sizeof(struct no *));
	novoNo -> numero = parametroNumero;
	novoNo -> proximo = NULL;
	novoNo -> anterior = NULL;
	
	//Verificar se a lista est� vazia
	if(cabeca == NULL){
		cabeca = novoNo;
	}else{
		//Lista cheia
		struct no *ponteiro = cabeca;
		//While percorrendo a lista
		while(ponteiro -> proximo != NULL){
			ponteiro = ponteiro -> proximo;
		}
		//Alocando o novo elemento na lista
		ponteiro -> proximo = novoNo;
		novoNo -> anterior = ponteiro;
	}
}

//Funcao que remove um n� na lista
void remover(int parametroNumero){
	struct no *ponteiroExcluir = cabeca;
	
	//Percorrendo a lista
	while(ponteiroExcluir != NULL){
		
		//Verificar se o numero foi encontrado
		if (ponteiroExcluir -> numero == parametroNumero){
			if(ponteiroExcluir == cabeca){
				
				//Excluir o primeiro
				cabeca = cabeca -> proximo;
				if(cabeca != NULL){
				cabeca -> anterior = NULL;	
				}
			}else if(ponteiroExcluir -> proximo == NULL){
				
				//Excluir o ultimo
				ponteiroExcluir -> anterior -> proximo = NULL;	
			}else{
				
				//Excluir no meio
				ponteiroExcluir -> proximo -> anterior = ponteiroExcluir -> anterior;
				ponteiroExcluir -> anterior -> proximo = ponteiroExcluir -> proximo;
			}
			free(ponteiroExcluir);
			return;
		}
		ponteiroExcluir = ponteiroExcluir -> proximo;
	}
}
//Funcao que imprime a lista
void imprimir(){
	printf("=====================\n");
	
	struct no *ponteiro = cabeca;
	
	while(ponteiro != NULL){
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
}

//Execu��o do programa
int main(){
	inserir(1);


	imprimir();
	
	remover(1);
	remover(1);
	
	imprimir();
}

