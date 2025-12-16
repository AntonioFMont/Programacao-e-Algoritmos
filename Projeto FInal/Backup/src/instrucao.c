#include <stdio.h>
#include "../Headers/instrucao.h"
#include <stdlib.h>

void ler(){
    FILE *file = fopen("Doc/instrucao.txt", "r");
    // int limp;
    // while ((limp = getchar()) != '\n' && limp != EOF);
    if(file == NULL){
        printf("Erro ao iniciar o arquivo");
        getchar();
        return;
    }
    char c;
    while((c = fgetc(file)) != EOF){
        printf("%c", c);
    }
    printf("\n\nPresione ENTER para voltar para o menu.");
    getchar();
    fclose(file);
    return;
}