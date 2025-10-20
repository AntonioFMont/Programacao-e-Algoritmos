#include <stdio.h>
#include <stdlib.h>

int main(){
    int matriz[3][3], i, j;
        for(i=0; i < 3; i++){
            for(j=0;j < 3; j++){
                printf("Digite a %d coluna da %d linha: \n", j+1, i+1);
                scanf("%d", &matriz[i][j]);
                    if(matriz[i][j]%2 == 0){
                        matriz[i][j] = 1;
                    } else{
                        matriz[i][j] = -1;
                    }
            }
        }
        for(i=0; i < 3; i++){
            for(j=0;j < 3; j++){  
            printf("%2d  ", matriz[i][j]);
            }
            printf("\n");
        }
}