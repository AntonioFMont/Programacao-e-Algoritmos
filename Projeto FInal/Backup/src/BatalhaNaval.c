#include "../Headers/instrucao.h"
#include "../Headers/jogo.h"
#include "../Headers/Gameplay.h"
#include <stdio.h>
#include <stdlib.h>
C:\Users\anton\OneDrive\Documentos\GitHub\Programacao-e-Algoritmos\Projeto FInal
int main(){
    int resp = 0; 
    do{
        system("cls");
        printf("===========================================\n");
        printf("               BATALHA NAVAL               \n");
        printf("===========================================\n");
        printf("1 - Novo Jogo \n");
        printf("2 - Continuar \n");
        printf("3 - Instrucoes\n");
        printf("4 - Sair\n");
        printf("Digite o Que deseja fazer: ");
        scanf("%d", &resp);
        int limp;
        while ((limp = getchar()) != '\n' && limp != EOF);              // Os bugs com o getchar() aconteceram por que eu não estava restando buffer(acho que se chama assim) depois do scanf, que no caso era o ENTER ou \n
        switch (resp){
            case 1:
                system("cls");
                char tabuleiro1[8][26];
                char tabuleiro2[8][26];
                FILE *p1 = fopen("Doc/Player1.txt", "w");         
                FILE *p2 = fopen("Doc/Player2.txt", "w");
                if(p1 == NULL){
                    printf("Erro ao abrir o arquivo do player 1\n");
                    printf("Aperte ENTER para sair.");
                    getchar();
                    break;
                } if(p2 == NULL){
                    printf("Erro ao abrir o arquivo do player 2");
                    printf("Aperte ENTER para sair.");
                    getchar();
                    break;
                }
                printf("Primeiro, O jogador 1 deve colocar os seus navios.\n");
                printf("Jogador 1, aperte ENTER para comecar a colocar. \n");
                getchar();                                                  // o getchar(); é uma forma de conseguir usar o system("pause") em computadores linux
                montar_tabuleiro(&tabuleiro1);
                    for(int i = 7; i >= 0; i--){
                        int resultado = fprintf(p1, "%s\n", tabuleiro1[i]);
                        if(resultado < 0){
                            printf("Erro ao escrever o arquivo\n");            // Isso e uma forma de verificar se deu erro ao escrever(por que quando da erro, o fprintf retorna EOF que e -1), caso eu quisesse veririficar se deu em uma linha especifica eu colodo %d e i, que representa a linha que falhou
                            break;                                            // dava pra ter feito tambem so um if, com um break pra parar logo, essa forma e so pra caso alguma linha especifica tenha dado erro.
                        }                                                     
                    }
                    fclose(p1);
                    system("cls");
                    printf("Agora o jogador 2 deve montar seu tabuleiro.\n");
                    printf("Jogador 2, aperte ENTER para comecar a colocar seus barcos\n");
                    getchar();    
                montar_tabuleiro(&tabuleiro2);
                    for(int i = 7; i >= 0; i--){
                        int resultado = fprintf(p2, "%s\n", tabuleiro2[i]);
                        if(resultado < 0){
                            printf("Erro ao escrever arquivo\n");
                            break;
                        }
                    }
                gameplay(tabuleiro1, tabuleiro2, 1);
                break;
            case 2:
                system("cls");
                FILE *f1 = fopen("Doc/InformacoesParaSalvamento.txt", "r");
                fseek(f1, 0, SEEK_END);
                int posicao = ftell(f1);
                if(posicao == 0){
                    printf("Nao existe um jogo em andamento, por favor comece um jogo novo\n");
                    printf("Aperte ENTER para voltar para o menu");
                    getchar();
                    break;
                }else{
                    printf("Continuando jogo...\n");
                    gameplay(tabuleiro1, tabuleiro2, 0);
                }
                break;
            case 3:
                system("cls");
                ler();
                break;
            case 4:
                printf("Obrigado por jogar batalha naval!");
                exit(0);
            default:
                system("cls");
                printf("Essa nao e uma opcao valida, por favor escolha entre numeros de 1 a 4\n");
                getchar();
                system("cls");
                break;
        }
    } while (resp != 4);
}