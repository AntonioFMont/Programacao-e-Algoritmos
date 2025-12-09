#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

    // faço a função receber os dois ponteiros FILE que apontam para o campo dos jogadores (no caso o Player1.txt e o Player2.txt);
    
void gameplay(char tabuleiro_original_jogador1[8][26], char tabuleiro_original_jogador2[8][26]){
    int acertos_jg1 = 0;
    int acertos_jg2 = 0;
    int erros_jg1 = 0;
    int erros_jg2 = 0;
    int salvar = 0;
    char escolha[3];
    //FILE *p = fopen ("../Doc/Player1.txt", "r");      Não sei se ainda preciso (já que eu vou receber as duas matrizes de qualquer jeito);
    //FILE *p2 = fopen ("../Doc/Player2.txt", "r");

    FILE *f1 = fopen("Campo_Jogador1.txt", "w");   
    char campo_jogador1[8][26];
    char abc[] = "a  b  c  d  e  f  g  h";
    strcpy(campo_jogador1[7], ".  .  .  .  .  .  .  .  8");
    strcpy(campo_jogador1[6], ".  .  .  .  .  .  .  .  7");
    strcpy(campo_jogador1[5], ".  .  .  .  .  .  .  .  6");
    strcpy(campo_jogador1[4], ".  .  .  .  .  .  .  .  5");
    strcpy(campo_jogador1[3], ".  .  .  .  .  .  .  .  4");
    strcpy(campo_jogador1[2], ".  .  .  .  .  .  .  .  3");
    strcpy(campo_jogador1[1], ".  .  .  .  .  .  .  .  2");
    strcpy(campo_jogador1[0], ".  .  .  .  .  .  .  .  1");
    for(int i = 7;i >= 0 ; i--){
        int verif = fprintf(f1, "%s\n", campo_jogador1[i]);
        if(verif < 0){
            printf("Erro ao colar arquivo\n");
            break;
        }
    }
    fclose(f1);
    FILE *f2 = fopen("Campo_Jogador2.txt", "w");
    char campo_jogador2[8][26];
    strcpy(campo_jogador2[7], ".  .  .  .  .  .  .  .  8");
    strcpy(campo_jogador2[6], ".  .  .  .  .  .  .  .  7");
    strcpy(campo_jogador2[5], ".  .  .  .  .  .  .  .  6");
    strcpy(campo_jogador2[4], ".  .  .  .  .  .  .  .  5");
    strcpy(campo_jogador2[3], ".  .  .  .  .  .  .  .  4");
    strcpy(campo_jogador2[2], ".  .  .  .  .  .  .  .  3");
    strcpy(campo_jogador2[1], ".  .  .  .  .  .  .  .  2");
    strcpy(campo_jogador2[0], ".  .  .  .  .  .  .  .  1");
    for(int i = 7; i >= 0; i--){
        int verif = fprintf(f2, "%s\n", campo_jogador2[i]);
        if(verif < 0){
            printf("Erro ao colar arquivo\n");
            break;
        }
    }
    fclose(f2);
    printf("Agora vamos comecar o jogo!\nO jogador 1 comecara jogando.\n");
    printf("Jogador 1, aperte ENTER para comecar\n");
    system("pause > nul");
         // começo do jogo
    do{
        bool jogar_novamente = true, aux = true;        // cuidado para não estar errado
        do{
            for(int i = 7; i >= 0; i--){
                printf("%s\n", campo_jogador2[i]);
            }
            printf("%s\n", abc);
            do{
                printf("Jogador 1: Escolha a coordenada da casa que deseja atacar: ");
                scanf(" %s", &escolha);
                if((escolha[0] - 97) > 7 || (escolha[1] - 49) > 7){
                    printf("Por favor escolha uma coordenada que esteja dentro do mapa.\n");
                    aux = false;
                    
                }else if(campo_jogador2[escolha[1] - '1'][(escolha[0] - 'a')*3] != '.'){        // se der erro subtrair pelo numero;
                    printf("Essa coordenada ja foi atacada, por favor escolha uma coordenada que ainda nao foi escolhida.\n");
                    aux = false;   
                }  
            } while(aux == false);
            int numero = escolha[1] - '1';
            char letra = escolha[0] - 'a';      // se der erro talvez seja aqui(subtrair 97 ao invés de 'a'?)
            if(tabuleiro_original_jogador2[numero][letra * 3] == 'O'){
                printf("Voce acertou um navio!\n");
                acertos_jg1++;
                campo_jogador2[numero][letra*3] = 'X';
                jogar_novamente = true;
            }else if(tabuleiro_original_jogador2[numero][letra * 3] == '.'){
                printf("Voce nao acertou nada :(\n");
                erros_jg1++;
                campo_jogador2[numero][letra*3] = '*';
                jogar_novamente = false;
                break;
            }
        } while (jogar_novamente = true);
                // Vez do Jogador 2
        printf("Agora, jogador 2, por favor aperte ENTER para comecar a jogar\n");
        system("pause > nul");
        do{
            for(int i = 7; i >=0; i--){
                printf("%s\n", campo_jogador1[i]);
            }
            do{
                printf("Jogador 2: escolha uma coordenada para atacar: ");
                scanf("%s", &escolha);
                if((escolha[0] - 97) > 7 || (escolha[1] - 49) > 7){
                    printf("Por favor escolha uma coordenada que esteja dentro do mapa.\n");
                    aux = false;
                    
                }else if(campo_jogador1[escolha[1] - '1'][(escolha[0] - 'a')*3] != '.'){
                    printf("Essa coordenada ja foi atacada, por favor escolha uma coordenada que ainda nao foi escolhida.\n");
                    aux = false;   
                }  
            }while(aux = false);
            int numero = escolha[1] - '1';
            char letra = escolha[0] - 'a'; 
            if(tabuleiro_original_jogador1[numero][letra * 3] == 'O'){
                printf("Voce acertou um navio! \n");
                acertos_jg2++;
                campo_jogador1[numero][letra*3] = 'X';
                jogar_novamente = true;
            }else if(tabuleiro_original_jogador1[numero][letra * 3] == '.'){
                printf("Voce nao acertou nada :(\n");
                erros_jg2++;
                campo_jogador1[numero][letra*3] = '*';
                jogar_novamente = false;
                break;
            }

        }while (jogar_novamente = true);
        do{
            printf("Voce deseja salvar o jogo e sair?\n1 - Sim\n2 - Nao(continuar o jogo)\n");
            scanf(" %d", &salvar);
                switch (salvar){
                case 1:
                for(int i = 7;i >= 0 ; i--){
                    int verif = fprintf(f1, "%s\n", campo_jogador1[i]);
                    if(verif < 0){
                        printf("Erro ao colar arquivo na linha %d\n", i);
                        break;
                    }
                }
                fclose(f1);
                for(int i = 7; i >= 0; i--){
                    int verif = fprintf(f2, "%s\n", campo_jogador2[i]);
                    if(verif < 0){
                        printf("Erro ao colar arquivo na linha %d \n", i);
                        break;
                    }
                }
                fclose(f2);
                    break;
                case 2:
                break;
                default:
                printf("Essa nao e uma opcao valida, digite 1 para salvar e 2 para continuar o jogo\n");
                    break;
                }
        }while(salvar != 1 && salvar != 2);
        printf("Agora e a vez do jogador 1, por favor, jogador 1 aperte ENTER para jogar.\n");
        system("pause > nul");
    } while (acertos_jg1 != 14 || acertos_jg2 != 14);



}

    void main(){
        char tabuleiro_jogador1[8][26];
        char tabuleiro_jogador2[8][26];
    strcpy(tabuleiro_jogador1[7], ".  O  .  .  .  .  .  .  8");
    strcpy(tabuleiro_jogador1[6], ".  O  .  .  O  O  .  .  7");
    strcpy(tabuleiro_jogador1[5], ".  O  .  .  .  .  .  .  6");
    strcpy(tabuleiro_jogador1[4], ".  O  .  .  .  O  .  .  5");
    strcpy(tabuleiro_jogador1[3], ".  O  .  .  .  O  .  .  4");
    strcpy(tabuleiro_jogador1[2], ".  .  .  .  .  O  .  .  3");
    strcpy(tabuleiro_jogador1[1], ".  .  .  .  .  .  .  .  2");
    strcpy(tabuleiro_jogador1[0], ".  .  O  O  O  O  .  .  1");

    strcpy(tabuleiro_jogador2[7], ".  .  .  .  .  .  .  .  8");
    strcpy(tabuleiro_jogador2[6], ".  O  O  O  .  O  .  .  7");
    strcpy(tabuleiro_jogador2[5], ".  .  .  .  .  O  .  .  6");
    strcpy(tabuleiro_jogador2[4], ".  .  O  O  .  O  .  .  5");
    strcpy(tabuleiro_jogador2[3], ".  .  .  .  .  O  .  .  4");
    strcpy(tabuleiro_jogador2[2], ".  .  .  .  .  .  .  .  3");
    strcpy(tabuleiro_jogador2[1], ".  .  .  .  .  .  .  .  2");
    strcpy(tabuleiro_jogador2[0], ".  O  O  O  O  O  .  .  1");
        gameplay(tabuleiro_jogador1, tabuleiro_jogador2);
    }

