#include <stdio.h>
#include <stdbool.h>
int main(){
int n_provas, i, contador;
float media, soma, prova[10];
printf("escreva o numero de provas realizadas\n");
scanf("%d", &n_provas);
media = 0;
soma = 0;
contador = 0;
    for(i = 0; i < n_provas; i++){
        printf("escreva a %d nota\n", i+1);
        scanf("%f", &prova[i]);
            while(prova[i] > 10 || prova[i] < 0){
                printf("Por favor, escreva apenas notas que vao de 0 a 10\n");
                scanf("%f", &prova[i]);
            }
            soma += prova[i];
            contador++;
        }
    media = soma / contador;
        if(media >= 8){
            media = 10;
        }
    printf("%d alunos fizeram a prova\n", n_provas);
    printf("a media perfeita das notas dos alunos e %.1f\n", media);
}
