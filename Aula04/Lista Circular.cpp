//Programa de lista circular

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
	novoNo -> proximo = cabeca;
	
	//Verificar se a lista está vazia
	if (cabeca == NULL){
		cabeca = novoNo;
		cabeca -> proximo = cabeca;
	}else {
		//Procurar ultimo elemento da lista
		struct no *ponteiro = cabeca;
		while(ponteiro -> proximo != cabeca){
			ponteiro = ponteiro -> proximo;
		}
		
		//Apontar o ultimo para o novo numero
		ponteiro -> proximo = novoNo;
	}
}

//Função que remove um elemento da lista
void remover(int parametroNumero){
	struct no *ponteiroFinal = cabeca;
	struct no *ponteiroExcluir = cabeca;
	struct no *ponteiroPenultimo = NULL;
	
	while(ponteiroFinal -> proximo != cabeca){
		if (ponteiroFinal -> proximo -> numero == parametroNumero){
			ponteiroExcluir = ponteiroFinal -> proximo;
		}
		if (ponteiroFinal -> proximo -> proximo == cabeca){
			ponteiroPenultimo = ponteiroFinal;
		}
		ponteiroFinal = ponteiroFinal -> proximo;
	}
	if(ponteiroExcluir == cabeca){
		ponteiroFinal -> proximo = cabeca -> proximo;
		cabeca = cabeca -> proximo;
		free(ponteiroExcluir);
	}else if(ponteiroExcluir == ponteiroFinal){
		ponteiroPenultimo -> proximo = cabeca;
		ponteiroFinal = NULL;
		free(ponteiroExcluir);
	}else{
		ponteiroFinal = cabeca;
		while((ponteiroFinal -> proximo != cabeca)&&(ponteiroFinal -> proximo -> numero != parametroNumero)) {
			ponteiroFinal = ponteiroFinal -> proximo;
		}
		if(ponteiroFinal -> proximo != cabeca){
			ponteiroExcluir = ponteiroFinal -> proximo;
			ponteiroFinal -> proximo = ponteiroExcluir -> proximo;
			free(ponteiroExcluir);
		}
	}
	
}

//Função que imprime os elementos da lista
void imprimir(){
	struct no *ponteiro = cabeca;
	
	while(true){
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
		if(ponteiro == cabeca){
			break;
		}
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
	remover(3);
	printf("==============================\n");
	imprimir();
	
}
