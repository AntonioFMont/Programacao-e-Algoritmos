#include <stdio.h>
#include "../Headers/instrucao.h"
#include <stdlib.h>

void ler(){
    FILE *file = fopen("C:\\Users\\anton\\OneDrive\\Documentos\\GitHub\\Programacao-e-Algoritmos\\Projeto FInal\\Doc\\instrucao.txt", "r");
    if(file == NULL){
        printf("Erro ao iniciar o arquivo\n");
        system("pause");
        return;
    }
    char c;
    while((c = fgetc(file)) != EOF){
        printf("%c", c);
    }
    printf("\n\nPresione ENTER para voltar para o menu.\n");
    system("pause > nul");
    fclose(file);
}