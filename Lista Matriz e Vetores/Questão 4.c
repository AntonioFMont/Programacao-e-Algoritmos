#include <stdio.h>
#include <stdbool.h>

int main(){
    int i, contador=0, empresa[10][2];
    i = 0;
    int soma=0; 
    while(i < 10){
            printf("Digite o investimento da %d filial\n", i+1);
            scanf("%d", &empresa[i][1]);
            printf("Digite o retorno obtido por ela\n");
            scanf("%d", &empresa[i][2]);
            i++;
        }
        for(i=0; i<10; i++){
            if(empresa[i][2] - empresa[i][1] > 0){
                printf("A filial %d deu %d de lucro\n", i+1, empresa[i][2]-empresa[i][1]);
                contador++;
                soma +=(empresa[i][2]-empresa[i][1]);
            }
        }
        printf("A media de lucros e %d\n", soma/contador);
}
