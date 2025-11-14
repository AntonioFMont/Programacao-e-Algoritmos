#include <stdio.h>

float pesoIdeal (float altura, char sexo){  
    if (sexo == '1'){
        return (72.7 * altura) - 58;
    }else{
    return (62.1 * altura) - 44.7;
    }
}

int main(){
    float altura;
    char sexo;
    printf("Digite a sua altura: ");
    scanf("%f", &altura);
    printf("Digite seu sexo (1 para homem // 2 para mulher): ");
    scanf(" %c", &sexo);
    printf("seu peso ideal e: %.2fKg", pesoIdeal(altura, sexo));
}