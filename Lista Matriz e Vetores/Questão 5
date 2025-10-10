#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
 /*
 5. Um grupo de amigos está debatendo sobre a altura entre eles para formar um time de
basquete e assim definir a posição de cada jogador. Para resolver essa discussão,
eles pediram que você criasse um algoritmo que fizesse o seguinte:
a. Leia a altura de 6 jogadores;
b. Imprima a maior e a menor altura, juntamente com o índice;
c. Em seguida, imprima as alturas dos jogadores em ordem decrescente, do mais
alto para o mais baixo.
 */
float maior=0, menor=10, altura[6], aux=0;
int x, i;
int main() {
    for(i=0; i < 6; i++){
        printf("Digite a altura do %d jogador\n", i+1);
        scanf("%f", &altura[i]);
        if(maior < altura[i]){
            maior = altura[i];
        }
        if(menor > altura[i]){
            menor = altura[i];
        }
    }
    system("cls");
    for(x=0; x<6; x++){
        for(i=0; i<6;i++){
            if(altura[x]>altura[i]){        // pq a altura[x] tem q ser > que a altura[i] pra ela ser em ordem decrescente?
                aux = altura[i];
                altura[i] = altura[x];
                altura[x] = aux;
            }
        }
    }
        printf("O maior jogador tem %.2f metros\n", maior);
        printf("O menor jogador tem %.2f metroz\n", menor);
        printf("As alturas em ordem decrescente sao:\n");
        for(i=0; i<6;i++){
            printf("%.2f\n", altura[i]);
        }
    return 0;
}
