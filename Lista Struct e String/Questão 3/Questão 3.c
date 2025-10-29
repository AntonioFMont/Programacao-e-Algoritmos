#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    struct pessoa{
        char nome[20];
        int idade;
    };
    struct pessoa pessoas[2];    
    for(i=0; i < 2; i++){
    printf("Digite o nome da pessoa %d: ", i+1);
    fgets(pessoas[i].nome, 20, stdin);
    }
    printf("A pessoa 1 tem %d anos e se chama %s\n", pessoas[1].idade, pessoa[1].nome);    
    printf("A pessoa 2 tem %d anos e se chama %s\n", pessoas[2].idade, pessoa[2].nome);    
}