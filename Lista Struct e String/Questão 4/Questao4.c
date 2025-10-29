#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char senha_usuario[10], senha[10];
    strcpy(senha, "senha123");
    printf("Digite a senha: \n");
    scanf("%s", &senha_usuario);
        if (strcmp(senha_usuario, senha) == 0){
            printf("Acesso permitido\n");           
        } else 
            printf("Acesso negado");
}