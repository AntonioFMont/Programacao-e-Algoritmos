#include "../Headers/instrucao.h"
#include "../Headers/jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

/* se for usar a função de sleep no compilador, usa-se:
#include <unistd.h> 

sleep(2);
*/
int main(){
    setlocale(LC_ALL, "");
    int resp = 0;
    do{
        system("cls");
        printf("===========================================\n");
        printf("               BATALHA NAVAL               \n");
        printf("===========================================\n");
        printf("1 - Novo Jogo \n");
        printf("2 - Continuar \n");
        printf("3 - Instruções\n");
        printf("4 - Sair\n");
        printf("Digite o Que deseja fazer: ");
        scanf("%d", &resp);
        switch (resp){
            case 1:
                system("cls");
                char tabuleiro1[8][26];
                char tabuleiro2[8][26];
                FILE *p1 = fopen("C:\\Users\\anton\\OneDrive\\Documentos\\GitHub\\Programacao-e-Algoritmos\\Projeto FInal\\Doc\\Player1.txt", "w");
                FILE *p2 = fopen("C:\\Users\\anton\\OneDrive\\Documentos\\GitHub\\Programacao-e-Algoritmos\\Projeto FInal\\Doc\\Player2.txt", "w");
                if(p1 == NULL){
                    printf("Erro ao abrir o arquivo do player 1\n");
                    system("pause");
                } if(p2 == NULL){
                    printf("Erro ao abrir o arquivo do player 2\n");
                    system("pause");
                }
                printf("Primeiro, O jogador 1 deve colocar os seus navios.\n");
                printf("Jogador 1, aperte ENTER para começar a colocar. \n");
                system("pause > nul");      // pauso o sistema mas eu "escondo" a mensagem direcionando-a a nul, que e um destino nulo no windows; 
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
                    printf("Jogador 2, aperte ENTER para começar a colocar seus barcos\n");
                    system("pause > nul");       
                montar_tabuleiro(&tabuleiro2);
                    for(int i = 7; i >= 0; i--){
                        int resultado = fprintf(p2, "%s\n", tabuleiro2[i]);
                        if(resultado < 0){
                            printf("Erro ao escrever arquivo\n");
                            break;
                        }
                    }
                
                break;
            case 2:
                system("cls");
                
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
                printf("Essa não é uma opção valida, por favor escolha entre numeros de 1 a 4\n");
                system("pause");
                system("cls");
                break;
        }
    } while (resp != 1 || resp != 2 || resp != 3);
}