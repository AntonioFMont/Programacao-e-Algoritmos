#include <stdio.h>
#include <stdlib.h>

int main(){
    float media;
    int i;
    struct produto{
        float preco;
        char nome[20];
    };
    struct produto produtos[3];

    for(i=0;i < 3; i++){
    printf("Digite o nome do %d produto: ", i+1);
    setbuf(stdin, NULL);
    fgets(produtos[i].nome, 20, stdin);
    printf("Digite o preco do %d produto: ", i+1);
    scanf("%f", &produtos[i].preco);
    }   
    media = (produtos[0].preco + produtos[1].preco + produtos[2].preco)/3;
    printf("A media de preco dos 3 itens e: %.2f\n", media);
    for(i=0; i < 3;i++){
        printf("O nome do %d produto e: %s\n",i+1, produtos[i].nome);
    }
}