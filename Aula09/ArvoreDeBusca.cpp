//Programa que implementa uma arvore de busca

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declaracao de estruturas

struct no {
	int numero;
	struct no *esquerda;
	struct no *direita;
};

//funcao que insere um no na arvore de busca

struct no *inserir (struct no *raiz, int numero){
	if (raiz == NULL){ // caso em que a raiz é nula
		raiz = (struct no *) malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
	} else{
		if (numero < raiz -> numero){ // numero menor que a raiz portanto vai a esquerda
			raiz -> esquerda = inserir(raiz -> esquerda, numero);
		}else if (numero > raiz -> numero){ // numero maior que a raiz portanto vai a direita
			raiz -> direita = inserir(raiz -> direita, numero);
		}
	}
	
	
	return raiz;
}

//funcao que busca um no na arvore

void buscar(struct no *raiz, int numero){
	if (raiz == NULL){
		printf("NÃO ACHEI!!!\n");
	}else if(raiz -> numero == numero){
		printf("ACHEI!!!!!\n");
	}else if(raiz -> numero > numero){
		buscar(raiz -> esquerda, numero);
	}else{
		buscar(raiz -> direita, numero);
	}
	
}

//funcao que navega em ordem

void navegar(struct no *raiz){
	if (raiz != NULL){
		navegar(raiz -> esquerda);
		printf("%d\t", raiz -> numero);
		navegar(raiz -> direita);
	}
}

//funcao principal

int main(){
	//declaracao de variaveis
	struct no *raiz = NULL;
	int opcao = 0;
	int numero = 0;
	int i = 0;
	
	//inicializacao da aleatoriedade
	time_t t;
	srand((unsigned) time(&t));
	
	//menu de opções
	while(opcao != 5){
		printf("+============================+\n");
		printf("|       Menu de opcoes       |\n");
		printf("+============================+\n");
		printf("| 1 - Criar Arvore Aleatoria |\n");
		printf("| 2 - Inserir No na Arvore   |\n");
		printf("| 3 - Buscar No na Arvore    |\n");
		printf("| 4 - Navegar a Arvore       |\n");
		printf("| 5 - Sair                   |\n");
		printf("+============================+\n");
		printf("Digite a sua opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				for (i = 0; i < 100; i++){
					raiz = inserir(raiz, rand());
				}
				break;
			case 2:
				printf("Digite o numero: ");
				scanf("%d", &numero);
				raiz = inserir(raiz, numero);
				break;
			case 3:
				printf("Digite o numero: ");
				scanf("%d", &numero);
				buscar(raiz, numero);
				break;
			case 4:
				navegar(raiz);
				break;
		}
	}
}
