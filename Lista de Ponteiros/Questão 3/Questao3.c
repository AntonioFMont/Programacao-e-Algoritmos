#include <stdio.h>

int main(){
    /* Ponteiro: 
    Ponteiros são variaveis que, ao invés de armazenar valores, como as outras, armazenam endereços. por exemplo:
            x = 10;
            int *p = &x;
    o ponteiro *p aponta para o endeereço da variavel x, podendo assim escrever e mudar seu valor.
    outra caracteristica dde ponteiros é que podem mudar caracteristicas de variaveis mesmo estando fora da sua função.
    */

    /*  Ponteiro de ponteiro: 
    Um ponteiro que aponta para outro ponteiro aponta, tambem, para a variavel a qual o ponteiro apontado aponta(kkk)
            int x = 20;
            int *p = &x;
            int **p2 = &p;
    então se:
            x += 20;
    tanto: *p será 40 quanto **p2, pois no final apontam para o mesmo endereço int.
    */

    /*  Endereço de um ponteiro:  
    O endereço de um ponteiro é o endedreço da variavel que ele aponta, 
    portando as mudanças feitas no ponteiro na verdade afetarão a variavel apontada, e consequentemente o ponteiro também.
    */
   
    /*  O conteudo que um ponteiro guarda: 
    O conteudo guardado por um ponteiro nada mais é do que o endereço no qual ele aponta, e toda mundaça no ponteiro mudará o valor da variavel 
    salva no seu endereço.
   */

   /*   O endereço de uma variável:
   O endereço da variável é onde a variavel fica salva na memoria, podendo ser acessado através de um ponteiro.
   */
}