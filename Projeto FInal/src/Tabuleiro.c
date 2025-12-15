#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../Headers/jogo.h"
/*
    PROTOTIPO
    x = ATIRADO
    O = INTACTO
    (x) = ATIROU NA AGUA

        .  .  .  .  .  .  .  .  a
        .  .  .  .  .  .  .  .  b
        .  .  .  .  .  .  .  .  c
        .  .  .  .  .  .  .  .  d
        .  .  .  .  .  .  .  .  e    
        .  .  .  .  .  .  .  .  f
        .  .  .  .  .  .  .  .  g
        .  .  .  .  .  .  .  .  h
        1  2  3  4  5  6  7  8
*/

void montar_tabuleiro(char (*linha)[8][26]) {  // o *linha nao tava dando certo pq eu tava fazendo uma matriz de ponteiro, e nao um ponteiro para uma matriz de char. (*linha) cria um ponteiro para uma matriz de char.
    system("cls");
    printf("Por favor digite a duas cordenadas (No formato LetraNumero => a1, b2, c5) que representam onde deseja colocar o seu Navio pirata (ocupa 5 casas),\nsendo as duas representando duas pontas do navio\n");
    
    
    strcpy((*linha)[7], ".  .  .  .  .  .  .  .  8");
    strcpy((*linha)[6], ".  .  .  .  .  .  .  .  7");
    strcpy((*linha)[5], ".  .  .  .  .  .  .  .  6");
    strcpy((*linha)[4], ".  .  .  .  .  .  .  .  5");
    strcpy((*linha)[3], ".  .  .  .  .  .  .  .  4");
    strcpy((*linha)[2], ".  .  .  .  .  .  .  .  3");
    strcpy((*linha)[1], ".  .  .  .  .  .  .  .  2");
    strcpy((*linha)[0], ".  .  .  .  .  .  .  .  1");
    
    char abc[] = "a  b  c  d  e  f  g  h";
    for(int i = 7; i >= 0; i--){
        printf("%s\n", (*linha)[i]);
    }
    printf("%s\n", abc);
    char ponta[3];  
    char ponta2[3];


    bool aux = true;
    do{
        printf("Digite a primeira ponta do Navio Pirata: ");
        scanf("%s", &ponta); // string n precisa de &, mas é uma boa pratica colocar ou é desnecessario?
        printf("Digite a segunda ponta do Navio(O navio ocupa 5 casas): ");
        scanf("%s", &ponta2);
        
        if((ponta[0] - 97) > 7 || (ponta2[0] - 97) > 7 || (ponta[1] - 49) > 7 || (ponta2[1] - 49 > 7)){
            aux = false;
        }else if(ponta[0] != ponta2[0] && ponta[1] != ponta2[1]){
            aux = false;
        }else if(ponta[1]- 4 == ponta2[1]){
            aux = true;
        }else if(ponta2[1]- 4 == ponta[1]){
            aux = true;
        }else if(ponta[0] - 4 == ponta2[0]){
            aux = true;
        }else if(ponta2[0] - 4 == ponta[0]){
            aux = true;
        }else{
            aux = false;
        }
        if(aux == false){
            printf("Por favor, digite um distancia do tamanho do Navio(5 casas) e que esteja dentro dos limites do mapa\n");
        }   
    } while(aux == false);
    
    char letra1 = ponta[0];
    char letra2 = ponta2[0]; 
    int numero1 = ponta[1] - '0';   // faço pois como o vetor é de CHAR, o numero 1, não vale 1, ele vale o equivalente da tabela ascii, que e 49,ai subtraio por '0' q e 48
    int numero2 = ponta2[1] - '0';
    
    switch (numero1){
        case 1:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){    //faço porque o char 'a' e a letra numero 97 na tabela, portanto 'a' - 97 = 0
                    (*linha)[0][i] = 'P';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                    (*linha)[i][(letra1-97)*3] = 'P';
                }
            }
        break;
        case 2:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[1][i] = 'P';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'P';
                }
            }
        break;
        case 3:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[2][i] = 'P';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'P';
                }
            }
        break;
        case 4:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[3][i] = 'P';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'P';
                }
            }
        break;
        case 5:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[4][i] = 'P';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'P';
                }
            }
        break;
        case 6:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[5][i] = 'P';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'P';
                }
            }
        break;
        case 7:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[6][i] = 'P';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'P';
                }
            }
        break;
        case 8:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[7][i] = 'P';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'P';
                }
            }
        break;
        default:
        break;
    }

    for(int i = 7; i >= 0; i--){
        printf("%s\n", (*linha)[i]);
    }
    printf("%s\n", abc);

    do{
        printf("Agora digite a primeira posicao do Barco Viking(ocupa 4 casas): ");
        scanf(" %s", &ponta);
        printf("Digite a segunda posicao do Barco: ");
        scanf(" %s", &ponta2);
        letra1 = ponta[0];
        letra2 = ponta2[0]; 
        numero1 = ponta[1] - '0'; 
        numero2 = ponta2[1] - '0';
        if((ponta[0] - 97) > 7 || (ponta2[0] - 97) > 7 || (ponta[1] - 49) > 7 || (ponta2[1] - 49 > 7)){
            aux = false;
        }else if(ponta[0] != ponta2[0] && ponta[1] != ponta2[1]){
            aux = false;
        }else if(ponta[1]- 3 == ponta2[1]){
            aux = true;
        }else if(ponta2[1]- 3 == ponta[1]){
            aux = true;
        }else if(ponta[0] - 3 == ponta2[0]){
            aux = true;
        }else if(ponta2[0] - 3 == ponta[0]){
            aux = true;
        }else{  
            aux = false;
        }
        if(aux == true){
            if(numero1 == numero2){
                for (int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    if ((*linha)[numero1-1][i] != '.'){
                        printf("\nHa casas ja ocupadas por outros barcos nessa posicao, por favor escolha apenas casas livres\n");
                        aux = false;
                        break;
                    }
                }

            } else if(letra1 == letra2){
                for(int i = numero1 - 1; i <= numero2 - 1; i++){
                    if((*linha)[i][(letra1 - 97) * 3] != '.'){
                        printf("\nHa casas ja ocupadas por outros barcos nessa posicao, por favor escolha apenas casas livres\n");
                        aux = false;
                        break;
                    }
                }
            }
        }
        if(aux == false){
            printf("Por favor, digite um distancia do tamanho do Barco(4 casas) e que esteja dentro dos limites do mapa.\n");
            
        }
    } while(aux == false);
    
    switch (numero1){
        case 1:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[0][i] = 'V';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                    (*linha)[i][(letra1-97)*3] = 'V';
                }
            }
        break;
        case 2:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[1][i] = 'V';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'V';
                }
            }
        break;
        case 3:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[2][i] = 'V';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'V';
                }
            }
        break;
        case 4:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[3][i] = 'V';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'V';
                }
            }
        break;
        case 5:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[4][i] = 'V';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'V';
                }
            }
        break;
        case 6:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[5][i] = 'V';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'V';
                }
            }
        break;
        case 7:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[6][i] = 'V';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'V';
                }
            }
        break;
        case 8:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[7][i] = 'V';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'V';
                }
            }
        break;
        default:
        break;
    }

    for(int i = 7; i >= 0; i--){
        printf("%s\n", (*linha)[i]); 
    }
    printf("%s\n", abc);

    do{
        printf("Agora digite a primeira posicao do Barco de Pesca(ocupa 3 casas): ");
        scanf(" %s", &ponta);
        printf("Digite a segunda posicao do Barco: ");
        scanf(" %s", &ponta2);
        letra1 = ponta[0];
        letra2 = ponta2[0]; 
        numero1 = ponta[1] - '0'; 
        numero2 = ponta2[1] - '0';
        if((ponta[0] - 97) > 7 || (ponta2[0] - 97) > 7 || (ponta[1] - 49) > 7 || (ponta2[1] - 49 > 7)){
            aux = false;
        }else if(ponta[0] != ponta2[0] && ponta[1] != ponta2[1]){
            aux = false;
        }else if(ponta[1] - 2 == ponta2[1]){
            aux = true;
        }else if(ponta2[1] - 2 == ponta[1]){
            aux = true;
        }else if(ponta[0] - 2 == ponta2[0]){
            aux = true;
        }else if(ponta2[0] - 2 == ponta[0]){
            aux = true;
        }else{
            aux = false;
        }
        if(aux == true){
            if(numero1 == numero2){
                for (int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){ 
                    if ((*linha)[numero1-1][i] != '.'){
                        printf("\nHa casas ja ocupadas por outros barcos nessa posicao, por favor escolha apenas casas livres\n");
                        aux = false;
                        break;
                    }
                }

            } else if(letra1 == letra2){
                for(int i = numero1 - 1; i <= numero2 - 1; i++){
                    if((*linha)[i][(letra1 - 97)*3] != '.'){
                        printf("\nHa casas ja ocupadas por outros barcos nessa posicao, por favor escolha apenas casas livres\n");
                        aux = false;
                        break;
                    }
                }
            }
        }
        if(aux == false){
            printf("Por favor, digite um distancia do tamanho do Barco(3 casas), que esteja dentro dos limites do mapa e que ja nao esteja ocupada por outro navio\n");
        }   
    } while(aux == false);
    
    switch (numero1){
        case 1:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[0][i] = 'B';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                    (*linha)[i][(letra1-97)*3] = 'B';
                }
            }
        break;
        case 2:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[1][i] = 'B';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'B';
                }
            }
        break;
        case 3:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[2][i] = 'B';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'B';
                }
            }
        break;
        case 4:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[3][i] = 'B';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'B';
                }
            }
        break;
        case 5:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[4][i] = 'B';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'B';
                }
            }
        break;
        case 6:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[5][i] = 'B';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'B';
                }
            }
        break;
        case 7:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[6][i] = 'B';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'B';
                }
            }
        break;
        case 8:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[7][i] = 'B';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'B';
                }
            }
        break;
        default:
        break;
    }
    
    for(int i = 7; i >= 0; i--){
        printf("%s\n", (*linha)[i]); 
    }
    printf("%s\n", abc);

    do{
        printf("Agora digite a primeira posicao do Canoa(ocupa 2 casas): ");
        scanf(" %s", &ponta);
        printf("Digite a segunda posicao do Bote: ");
        scanf(" %s", &ponta2);
        letra1 = ponta[0];
        letra2 = ponta2[0]; 
        numero1 = ponta[1] - '0'; 
        numero2 = ponta2[1] - '0';
        if((ponta[0] - 97) > 7 || (ponta2[0] - 97) > 7 || (ponta[1] - 49) > 7 || (ponta2[1] - 49 > 7)){
            aux = false;
        }else if(ponta[0] != ponta2[0] && ponta[1] != ponta2[1]){
            aux = false;
        }else if(ponta[1] - 1 == ponta2[1]){
            aux = true;
        }else if(ponta2[1] - 1 == ponta[1]){
            aux = true;
        }else if(ponta[0] - 1 == ponta2[0]){
            aux = true;
        }else if(ponta2[0] - 1 == ponta[0]){
            aux = true;
        }else{
            aux = false;
        }
        if(aux == true){
            if(numero1 == numero2){
                for (int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){ 
                    if ((*linha)[numero1-1][i] != '.'){
                        printf("\nHa casas ja ocupadas por outros barcos nessa posicao, por favor escolha apenas casas livres\n");
                        aux = false;
                        break;
                    }
                }

            } else if(letra1 == letra2){
                for(int i = numero1 - 1; i <= numero2 - 1; i++){
                    if((*linha)[i][(letra1 - 97)*3] != '.'){
                        printf("\nHa casas ja ocupadas por outros barcos nessa posicao, por favor escolha apenas casas livres\n");
                        aux = false;
                        break;
                    }
                }
            }
        }
        if(aux == false){
            printf("Por favor, digite um distancia do tamanho do Bote(2 casas), que esteja dentro dos limites do mapa e que ja nao esteja ocupada por outro navio\n");
        }   
    } while(aux == false);
    
    switch (numero1){
        case 1:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[0][i] = 'C';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                    (*linha)[i][(letra1-97)*3] = 'C';
                }
            }
        break;
        case 2:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[1][i] = 'C';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'C';
                }
            }
        break;
        case 3:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[2][i] = 'C';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'C';
                }
            }
        break;
        case 4:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[3][i] = 'C';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'C';
                }
            }
        break;
        case 5:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[4][i] = 'C';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'C';
                }
            }
        break;
        case 6:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[5][i] = 'C';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'C';
                }
            }
        break;
        case 7:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[6][i] = 'C';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'C';
                }
            }
        break;
        case 8:
            if(numero1 == numero2){
                for(int i = (letra1-97) * 3; i <= (letra2 - 97) * 3; i = i + 3){
                    (*linha)[7][i] = 'C';
                }
            } else{
                for(int i = numero1-1; i <= numero2-1; i++){
                (*linha)[i][(letra1-97)*3] = 'C';
                }
            }
        break;
        default:
        break;
    }
    
}