//////////////////////////////////////////
//Programa de multiplicacao de matrizes//
////////////////////////////////////////

//Importacao de bibliotecas
#import <stdio.h>

//Declaracao de variaveis
int matriz1[2][3];
int matriz2[3][2];
int resultado[2][2];
int i = 0;
int j = 0;
int k = 0;

//////////////////////
//Inicio do programa//
//////////////////////

int main(){
//Limpando matrizes
	for(i=0;i<2;i++){
		for(j=0;j<3;i++){
			matriz1[i][j] = 0;
			matriz2[j][i] = 0;
		}
	}
	
	for(i=0;i<2;i++){
		for(j=0;j<2;i++){
			resultado[i][j] = 0;
		}
	}
//Preenchimento das matrizes
	for(i=0;i<2;i++){
		for(j=0;j<3;i++){
			printf("Digite o valor da matriz1[%d][%d]", i, j);
			scanf("%d", &matriz1[i][j]);
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<2;i++){
			printf("Digite o valor da matriz1[%d][%d]", i, j);
			scanf("%d", &matriz2[i][j]);
		}
	}
//Multiplicação das matrizes

//Impressao do resultado
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			printf("%d\t",matriz1[i][j]);
		}
	}
	
	for(i=0;i<3;i++){
		for(j=0;j<2;i++){
			printf("%d\t",matriz2[i][j]);
		}
	}
	
	for(i=0;i<2;i++){
		for(j=0;j<2;i++){
			printf("%d\t",resultado[i][j]);
		}
	}
}
