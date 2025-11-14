#include <stdio.h>
/*
      A passagem de parâmetros por valor é a mais comum em C,
    ela é acontece quando uma função utiliza parâmetros para fazer uma "Cópia" do valor de uma variável
    e utiliza-la dentro da propria função, mas sem alterar o valor da variavel fora da dita função.
    
      Ja a passagem de parâmetros por referência utiliza ponteiros para modificar o valor tanto dentro como fora da função,
    utilizando os ponteiros você consegue modificar um valor de uma variavel definida em main, numa função fora de main por exemplo.
*/

int passagem_valores(int x,int y){
  // essa função recebe parametros por valores e os utiliza dentro da função sem modificar o valor fora dela.
  x = (x*y)/2;
  y = (y*x) + 10;
  printf("Os valores de x e y dentro da funcao sao, relativamente: %d e %d\n", x, y);
  return x;
}

int passagem_referencia(int *p){
  (*p)++;    // incrementa o valor do int o qual p aponta
  *p = (*(p) * 5) + 10;
  printf("Valor de z dentro da funcao: %d\n", *p);
  return *p;
}


int main(){
  int x, y, z;
  x = 10;
  y = 20;
  z = 100;
  printf("Os valores de x e y eram antes da funcao, relativamente: %d e %d\n", x, y);
  passagem_valores(x, y);  
  printf("Os valores de x e y depois da funcao sao, relativamente: %d e %d\n", x, y);
    // como poder os valores de x e y, com a passagem de parametros por valores é alterado apenas dentro da função.
  printf("\nO valor de z antes de chamar a funcao: %d\n", z);
  passagem_referencia(&z);
  printf("O valor de z depois de chamar a funcao: %d\n", z);

  }