#include <stdio.h>
#include <stdlib.h>

    int main(){
        int i, vetor1[5], vetor2[5];
        printf("Digite o valor da força do sinal nos horarios correspondentes:  ");
        for(i=0; i < 5; i++){
            scanf("%d", &vetor1[i]);
        }
        vetor2[0] = vetor1[0];
        for(i=1; i < 5; i++){
            vetor2[i] = vetor1[i] + vetor1[i-1];
        }
        printf("o vetor do primeiro farol é: ");
        for(i=0; i < 5; i++){
            printf("%2d", vetor1[i]);
        }        
        printf("\n o vetor do segundo farol é: ");
        for(i=0; i < 5; i++){
            printf("%2d", vetor2[i]);
        }      
}