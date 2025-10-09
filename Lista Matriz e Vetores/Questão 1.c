int main(){
int n_provas, i, n_reprovados, n_aprovados;
float media, soma, prova[10], reprovados[10], aprovados[10];
n_reprovados = 0;
n_aprovados = 0;
const int media_geral = 4;
printf("escreva o numero de provas realizadas\n");
scanf("%d", &n_provas);
media = 0;
soma = 0;
for(i = 0; i < n_provas; i++){
    printf("escreva a %d nota\n", i+1);
    scanf("%f", &prova[i]);
    }
i = 0;
while(i < n_provas){
        if(prova[i] <= 4){
        reprovados[i] = prova[i];
        n_reprovados++;
        }
        else{
            aprovados[i] = prova[i];
            n_aprovados++;
        }
        soma += aprovados[i];
        i++;
}
    media = soma / n_aprovados;
    
    printf("%d alunos fizeram a prova\n", n_provas);
    printf("%d alunos foram aprovados\n", n_aprovados);
    printf("%d alunos foram reprovados\n", n_reprovados);
    printf("a media de alunos aprovados foi %.1f\n", media);
}