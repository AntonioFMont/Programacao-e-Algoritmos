#include <stdio.h>
#include <stdlib.h>
#include "../Headers/limpar_tela.h"

void limpar_tela(void){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif    
}