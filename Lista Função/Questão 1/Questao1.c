#include <stdio.h>

float area_triangulo(float base,float altura){
    if(base <= 0 || altura <= 0){
        printf("Valores menores ou iguais a 0 são invalidos");
        return 0;
    }
    float area = (base * altura)/2;
    return area;
}

int main(){
    float altura, base;
    printf("Digite a base do triangulo \n");
    scanf("%f", &base);
    printf("Digite a altura do triangulo \n");
    scanf(" %f", &altura);

    printf("A area do triangulo e %.2f", area_triangulo(base, altura));
}