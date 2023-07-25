/////////////////////////////////////
//Programa para transpor uma matriz//
/////////////////////////////////////

//Importação de pacote
#import <stdio.h>

//Declaracao de variavel
int matrizOriginal[2][3];
int matrizTransposta[3][2];
int i=0;
int z=0;


//////////////////////
//Inicio do programa//
//////////////////////
int main(){
	//Limpando as matrizes
	for(i=0;i<2;i++){
		for(z=0;z<3;z++){
			matrizOriginal[i][z] = 0;
			matrizTransposta[z][i] = 0;
		}
	}
	//Preenchimento da matriz
	for(i=0;i<2;i++){
		for(z=0;z<3;z++){
			printf("Digite o valor da matriz[%d][%d] = ", i, z);
			scanf("%d", &matrizOriginal[i][z]);
		}
	}
	//Transpocicao propriamente dita
	for(i=0;i<2;i++){
		for(z=0;z<3;z++){
			matrizTransposta[z][i] = matrizOriginal[i][z];
		}
	}
	//Impressao das matrizes
	for(i=0;i<2;i++){
		for(z=0;z<3;z++){
			printf("%d\t", matrizOriginal[i][z]);
		}
		printf("\n");
	}
	printf("\n");

	for(i=0;i<3;i++){
		for(z=0;z<2;z++){
			printf("%d\t", matrizTransposta[i][z]);
		}
		printf("\n");
	}
	
}
