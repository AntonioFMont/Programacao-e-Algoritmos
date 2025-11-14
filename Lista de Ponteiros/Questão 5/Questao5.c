#include <stdio.h>

int main(){
    int x, y, *p, *p2;
    p = &x;
    p2 = &y;
    printf("Digite o valor da variavel x: ");
    scanf("%d", &x);
    printf("Digite o valor da variavel y: ");
    scanf("%d", &y);
    if(p > p2){
        printf("a variavel com maior endereco e x e seu endereco e: %p", p);
    } else{
        printf("a variaveel com maior endereco e y e seu endereco e: %p", p2);
    }
}