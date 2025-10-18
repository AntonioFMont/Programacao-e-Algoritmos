
#include <stdio.h>

int main() {
	int linhas = 3, colunas = 3;
	int matriz[linhas][colunas];
	for(int i=0; i < linhas; i++) {
		for(int j =0; j < colunas; j++) {
			printf("digite a idade da cidade %d do estado %d: \n", j+1, i+1);
			scanf("%d", &matriz[i][j]);
		}
	}
	for(int i=0; i < linhas; i++) {
		for(int j=0; j < colunas; j++) {
			for(int k=0; k < colunas; k++) {
				if(matriz[i][j] < matriz[i][k]) {
					int aux = matriz[i][j];
					matriz[i][j] = matriz[i][k];
					matriz[i][k] = aux;
				}
			}
		}
	}
    for(int i=0; i<linhas;i++){
        for(int j=0; j < colunas; j++){
            printf("%d ", matriz[i][j]);
        }
    printf("\n");
    }
	int indice_linha=0; 
	float soma = 0;
	printf("Digite o indice da linha que deseja saber a media: ");
	scanf("%d", &indice_linha-1);
		for(int j=0; j < colunas; j++){
			soma += matriz[indice_linha][j];
		}
	printf("A media das 6 cidades e: %.2f", soma/6);
}

