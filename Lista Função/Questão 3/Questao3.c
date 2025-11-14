#include <stdio.h>


int soma_numeros(int n1, int n2){
    int soma = 0;
    for(int i = n1; i <= n2; i++){
        soma += i;
    }
    return soma;
}



int main(){
    int p1, p2;
    printf("Digite as primeira pontuacao: ");
    scanf("%d", &p1);
    printf("Digite a segunda pontuacao: ");
    scanf("%d", &p2);

    printf("A soma das duas pontuacoes e: %d", soma_numeros(p1, p2));
}