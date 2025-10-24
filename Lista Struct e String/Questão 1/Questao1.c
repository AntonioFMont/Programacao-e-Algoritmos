#include <stdio.h>
#include <stdlib.h> 

int main(){
    struct jogador{
        char nome[50];
        int pontos;
    };
    struct jogador jogador1, jogador2;
    printf("Digite o nome do jogador 1: ");
    scanf("%s", &jogador1.nome);
    printf("Digite o nome do jogador 2: ");
    scanf("%s", &jogador2.nome);

    printf("Digite a quantidade de gols do %s: ", jogador1.nome);
    scanf("%d", &jogador1.pontos);
    printf("Digite a quantidade de gols do %s: ", jogador2.nome);
    scanf("%d", &jogador2.pontos);

        if (jogador1.pontos > jogador2.pontos){
            printf("O %s fez mais gols que o %s.", jogador1.nome, jogador2.nome);

        }  else if(jogador1.pontos < jogador2.pontos){
            printf("O %s fez mais gols que o %s.", jogador2.nome, jogador1.nome);
        }   else 
            printf("O jogo deu empate");
}