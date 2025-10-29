#include <stdlib.h>
#include <stdio.h> 
#include <string.h>

int main(){
    int i;
    char aux[20];
    struct nomes{
    char nome[20];
    };
    struct nomes nome[3];
    for(i=0;i<3;i++){
        printf("Digite o %d nome: ", i+1);
        fgets(nome[i].nome, 20, stdin);
        setbuf(stdin, NULL);
    }
    strcpy(aux, nome[0].nome);
    for(i=0;i<3;i++){
        if(strcmp(aux, nome[i].nome) > 0){
            strcpy(aux, nome[i].nome);
        }
    }
    printf("O nome que vem primeiro em ordem alfabetica e: %s", aux);
}