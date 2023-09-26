//Programa de lista encadeada simples

//importação de pacotes
#include <stdio.h>
#include <stdlib.h>

//Definição da estrutura do nó
struct no{
	int numero;
	struct no *proximo;
};

//Declaração de variaveis
struct no *cabeca;

//Função que insere um nó na lista
void inserir(int parametroNumero){
	//Criar um novo nó
	struct no *novoNo = NULL;
	novoNo = (struct no *) malloc(sizeof(struct no *));
	novoNo -> numero = parametroNumero;
	novoNo -> proximo = NULL;
	
	//Verificar se a lista está vazia
	if (cabeca == NULL){
		cabeca = novoNo;
	}else {
		//Procurar ultimo elemento da lista
		struct no *ponteiro = cabeca;
		while(ponteiro -> proximo != NULL){
			ponteiro = ponteiro -> proximo;
		}
		
		//Apontar o ultimo para o novo numero
		ponteiro -> proximo = novoNo;
	}
}

//Função que remove um elemento da lista
void remover(int parametroNumero){
	struct no *ponteiroAnterior;
	struct no *ponteiroExcluir;
	
	if (cabeca != NULL){
		if (cabeca -> numero == parametroNumero){
			ponteiroExcluir = cabeca;
			cabeca = cabeca -> proximo;
			free(ponteiroExcluir);

		} else{
			ponteiroAnterior = cabeca;
			while((ponteiroAnterior != NULL)&&(ponteiroAnterior -> proximo -> numero != parametroNumero)) {
				ponteiroAnterior = ponteiroAnterior -> proximo;
			}
			if(ponteiroAnterior != NULL){
				ponteiroExcluir = ponteiroAnterior -> proximo;
				ponteiroAnterior -> proximo = ponteiroExcluir -> proximo;
				free(ponteiroExcluir);
			}
		}
	}	
}

//Função que imprime os elementos da lista
void imprimir(){
	struct no *ponteiro = cabeca;
	
	while(ponteiro != NULL){
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
}

//Execução do programa
int main(){
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	inserir(6);
	imprimir();
	remover(9);
	printf("==============================\n");
	imprimir();
	
}
