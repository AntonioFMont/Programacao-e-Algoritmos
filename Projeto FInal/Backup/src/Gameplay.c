#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "../Headers/Gameplay.h"

    
void gameplay(char tabuleiro_original_jogador1[8][26], char tabuleiro_original_jogador2[8][26], int novo_jogo){
    int limp; 
    FILE *f1, *f2, *f3, *f4;
    time_t dt = time(NULL);                 // forma de colocar a data, aprendi num tutorial do youtube e achei mt legal, provavelmente amanha vou esquecer mas e bom ja começar a aprender
    struct tm data = *localtime(&dt);
    int acertos_jg1 = 0, acertos_jg2 = 0;
    int pirata = 0, viking = 0, pesca = 0, canoa = 0, pirata2 = 0, viking2 = 0, pesca2 = 0, canoa2 = 0;
    int erros_jg1 = 0, erros_jg2 = 0;
    int salvar = 0;
    char escolha[3], vencedor[8];  
    char sair;
    char campo_jogador1[8][26];
    char campo_jogador2[8][26];
    char abc[] = "a  b  c  d  e  f  g  h";
    
    if(novo_jogo == 1){
        f1 = fopen("Doc/Campo_Jogador1.txt", "w");
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
        f2 = fopen("Doc/Campo_Jogador2.txt", "w");
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
        getchar();
    }else if(novo_jogo == 0){
        f1 = fopen("Doc/Campo_Jogador1.txt", "r");
        f2 = fopen("Doc/Campo_Jogador2.txt", "r");
        for(int i = 7; i >= 0; i--){
            if(fgets(campo_jogador1[i], sizeof(campo_jogador1[i]), f1) == NULL){
                printf("Erro ao copiar o arquivo do Jogador 1");
            }
            char aux[2];                            // com a maior epifania da minha vida eu pensei em colocar o aux pra receber os \n e conseguir ler a matriz corretamente
            fgets(aux, sizeof(aux), f1);
        }
        for(int i = 7; i >= 0; i--){
            if(fgets(campo_jogador2[i], sizeof(campo_jogador2[i]), f2) == NULL){
                printf("Erro ao copiar o arquivo do Jogador 2");
            }
            char aux[2];
            fgets(aux, sizeof(aux), f2);
        }
        f3 = fopen("Doc/InformacoesParaSalvamento.txt", "r");
        fscanf(f3, "%*s %*s %d", &acertos_jg1);
        fscanf(f3, " %*s %*s %d", &erros_jg1);
        fscanf(f3, " %*s %d", &pirata);
        fscanf(f3, " %*s %d", &viking);
        fscanf(f3, " %*s %d", &pesca);
        fscanf(f3, " %*s %d", &canoa);
        fscanf(f3, " %*s %*s %d", &acertos_jg2);
        fscanf(f3, " %*s %*s %d", &erros_jg2);
        fscanf(f3, " %*s %d", &pirata2);
        fscanf(f3, " %*s %d", &viking2);
        fscanf(f3, " %*s %d", &pesca2);
        fscanf(f3, " %*s %d", &canoa2);
        fclose(f1);
        fclose(f2);
        fclose(f3);

    }
    // começo do jogo
    do{
        system("cls");
        bool jogar_novamente = true, aux = true;        
        do{
            for(int i = 7; i >= 0; i--){
                printf("%s\n", campo_jogador2[i]);
            }
            printf("%s\n", abc);
            do{
                printf("Jogador 1: Escolha a coordenada da casa que deseja atacar: ");
                scanf(" %s", &escolha);
                while ((limp = getchar()) != '\n' && limp != EOF);     //limpar buffer
                if((escolha[0] - 97) > 7 || (escolha[1] - 49) > 7){
                    printf("Por favor escolha uma coordenada que esteja dentro do mapa.\n");
                    aux = false;
                    
                }else if(campo_jogador2[escolha[1] - '1'][(escolha[0] - 'a')*3] != '.'){       
                    printf("Essa coordenada ja foi atacada, por favor escolha uma coordenada que ainda nao foi escolhida.\n");
                    aux = false;   
                }else{
                    aux = true;
                }
            } while(aux == false);
            int numero = escolha[1] - '1';
            char letra = escolha[0] - 'a';     
            switch(tabuleiro_original_jogador2[numero][letra * 3]){
                case 'P':
                printf("Voce acertou um navio!\n");
                acertos_jg1++;
                campo_jogador2[numero][letra*3] = 'X';
                pirata++;
                if(pirata == 5){
                    printf("\nVoce afundou um navio!!\n\n");
                }
                jogar_novamente = true;
                break;
                case 'V':
                printf("Voce acertou um navio!\n");
                acertos_jg1++;
                campo_jogador2[numero][letra*3] = 'X';
                viking++;
                if(viking == 4){
                    printf("\nVoce afundou um navio!!\n\n");
                }
                jogar_novamente = true;
                break;
                case 'B':
                printf("Voce acertou um navio!\n");
                acertos_jg1++;
                campo_jogador2[numero][letra*3] = 'X';
                pesca++;
                if(pesca == 3){
                    printf("\nVoce afundou um navio!!\n\n");
                }
                jogar_novamente = true;
                break;
                case 'C':
                printf("Voce acertou um navio!\n");
                acertos_jg1++;
                campo_jogador2[numero][letra*3] = 'X';
                canoa++;
                if(canoa == 2){
                    printf("\nVoce afundou um navio!!\n\n");
                }
                jogar_novamente = true;
                break;
                case '.':
                printf("Voce nao acertou nada :(\n");
                erros_jg1++;
                campo_jogador2[numero][letra*3] = '*';
                jogar_novamente = false;
                break;
            }
            if (acertos_jg1 == 14){
            jogar_novamente = false;
        }
        } while (jogar_novamente == true);
        if (acertos_jg1 == 14){
            break;
        }
        
                // Vez do Jogador 2
        printf("Agora, jogador 2, por favor aperte ENTER para comecar a jogar\n");
        getchar();
        system("cls");
        do{
            for(int i = 7; i >=0; i--){
                printf("%s\n", campo_jogador1[i]);
            }
            printf("%s\n", abc);
            do{
                printf("Jogador 2: Escolha uma coordenada para atacar: ");
                scanf(" %s", &escolha);
                while((limp = getchar()) != '\n' && limp != EOF);
                if((escolha[0] - 97) > 7 || (escolha[1] - 49) > 7){
                    printf("Por favor escolha uma coordenada que esteja dentro do mapa.\n");
                    aux = false;
                }else if(campo_jogador1[escolha[1] - '1'][(escolha[0] - 'a')*3] != '.'){
                    printf("Essa coordenada ja foi atacada, por favor escolha uma coordenada que ainda nao foi escolhida.\n");
                    aux = false;   
                }else{
                    aux = true;
                }
            }while(aux == false);
            int numero = escolha[1] - '1';
            char letra = escolha[0] - 'a'; 
            switch(tabuleiro_original_jogador1[numero][letra * 3]){
                case 'P':
                printf("Voce acertou um navio! \n");
                acertos_jg2++;
                campo_jogador1[numero][letra*3] = 'X';
                pirata2++;
                if(pirata2 == 5){
                    printf("\nVoce afundou um navio!!\n\n");
                }
                jogar_novamente = true;
                break;
                case 'V':
                printf("Voce acertou um navio! \n");
                acertos_jg2++;
                campo_jogador1[numero][letra*3] = 'X';
                viking2++;
                if(viking2 == 4){
                    printf("\nVoce afundou um navio!!\n\n");
                }
                jogar_novamente = true;
                break;
                case 'B':
                printf("Voce acertou um navio! \n");
                acertos_jg2++;
                campo_jogador1[numero][letra*3] = 'X';
                pesca2++;
                if(pesca2 == 3){
                    printf("\nVoce afundou um navio!!\n\n");
                }
                jogar_novamente = true;
                break;
                case 'C':
                printf("Voce acertou um navio! \n");
                acertos_jg2++;
                campo_jogador1[numero][letra*3] = 'X';
                canoa2++;
                if(canoa2 == 2){
                    printf("\nVoce afundou um navio!!\n\n");
                }
                jogar_novamente = true;
                break;
                case '.':
                printf("Voce nao acertou nada :(\n");
                erros_jg2++;
                campo_jogador1[numero][letra*3] = '*';
                jogar_novamente = false;
                break;
            }
            if(acertos_jg2 == 14){
                jogar_novamente = false;
            }
        }while (jogar_novamente == true);
        if(acertos_jg2 == 14){
            break;
        }
        do{
            printf("Voce deseja salvar o jogo e sair?\n1 - Sim\n2 - Nao(continuar o jogo)\n");
            scanf(" %d", &salvar);
            while ((limp = getchar()) != '\n' && limp != EOF);
                switch (salvar){
                case 1:
                f1 = fopen("Doc/Campo_Jogador1.txt", "w");
                for(int i = 7;i >= 0 ; i--){
                    int verif = fprintf(f1, "%s\n", campo_jogador1[i]);
                    if(verif < 0){
                        printf("Erro ao colar arquivo na linha %d\n", i);
                        break;
                    }
                }
                fclose(f1);
                f2 = fopen("Doc/Campo_Jogador2.txt", "w");
                for(int i = 7; i >= 0; i--){
                    int verif = fprintf(f2, "%s\n", campo_jogador2[i]);
                    if(verif < 0){
                        printf("Erro ao colar arquivo na linha %d \n", i);
                        break;
                    }
                }
                fclose(f2);
                f3 = fopen("Doc/InformacoesParaSalvamento.txt", "w");
                fprintf(f3, "Acertos Jogador1: %d\n", acertos_jg1);
                fprintf(f3, "Erros jogador1: %d\n", erros_jg1);
                fprintf(f3, "Pirata: %d\n", pirata);
                fprintf(f3, "Viking: %d\n", viking);
                fprintf(f3, "Pesca: %d\n", pesca);
                fprintf(f3, "Canoa: %d\n", canoa);
                fprintf(f3, "Acertos jogador2: %d\n", acertos_jg2);
                fprintf(f3, "Erros jogador2: %d\n", erros_jg2);
                fprintf(f3, "Pirata2: %d\n", pirata2);
                fprintf(f3, "Viking2: %d\n", viking2);
                fprintf(f3, "Pesca2: %d\n", pesca2);
                fprintf(f3, "Canoa2: %d\n", canoa2);
                fclose(f3);
                printf("Jogo salvo!\n");
                printf("Aperte ENTER para sair\n");
                getchar();
                return;
                case 2:
                break;
                default:
                printf("Essa nao e uma opcao valida, digite 1 para salvar e 2 para continuar o jogo\n");
                    break;
                }
        }while(salvar != 1 && salvar != 2);
        printf("Agora e a vez do jogador 1, por favor, jogador 1 aperte ENTER para jogar.\n");
        getchar();
    } while (acertos_jg1 != 14 || acertos_jg2 != 14);
    if(acertos_jg1 == 14){
        system("cls");
        printf("\n\nParabens Jogador 1!!! Voce ganhou\n");    
        strcpy(vencedor, "Player1");
    } else if(acertos_jg2 == 14){
        system("cls");
        printf("\n\nParabens Jogador 2!!! Voce ganhou\n");
        strcpy(vencedor, "Player2");
    }
    f4 = fopen("Doc/JogosSalvos.txt", "a");
    fprintf(f4, "   Jogo do dia %d/%d/%d\n", data.tm_mday, data.tm_mon+1, data.tm_year+1900);   
    fprintf(f4, "Vencedor: %s\n", vencedor);  // +1 pq mes começa no 0 ^                ^ +1900 porque por algum motivo ele subtrai 1900 anos no total
    fprintf(f4, "Numero de rodadas: %d\n", acertos_jg1+erros_jg1);
    fprintf(f4, "Acertos jogador 1: %d\n", acertos_jg1);
    fprintf(f4, "Erros jogador 1: %d\n", erros_jg1);
    fprintf(f4, "Acertos jogador 2: %d\n", acertos_jg2);
    fprintf(f4, "Erros jogador 2: %d\n", erros_jg2);
    printf("Os status da partida foram:\n\n");
    printf("A partida teve %d rounds\n", acertos_jg1+erros_jg1);
    printf("O jogador 1 acertou %d vezes e errou %d vezes\n", acertos_jg1, erros_jg1);
    printf("O jogador 2 acertou %d vezes e errou %d vezes\n", acertos_jg2, erros_jg2);
    printf("Os dados estao salvos no arquivo JogosSalvos.txt\n");
    f3 = fopen("Doc/InformacoesParaSalvamento.txt", "w");
    fclose(f3);

    printf("Obrigado por jogar batalha naval!\n");
    printf("Aperte ENTER para voltar para o menu\n");
    getchar();
    return;
}