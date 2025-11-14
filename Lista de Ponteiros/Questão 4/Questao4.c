#include <stdio.h>


void soma(int *x, int y){
    *x += y;
}

int main(){
    int A, B;
    printf("Insira os valores de A: \n");
    scanf("%d", &A);
    printf("Insira os valores de B: ");
    scanf("%d", &B);
    soma(&A, B);
    printf("O valor de A apos a funcao e: %d\n", A);
}