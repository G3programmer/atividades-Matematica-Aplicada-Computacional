#include <stdio.h>

int main() {
    int notas[5];       
    char nome[50];      
    int soma = 0;
    float media;

    printf("Digite o nome do aluno: \n");
    scanf("%49s", nome);  // TOLERA ATÉ 49 CARACTÉRES SEM BUGAR

    printf("\n=============================\n");
    printf(" |        %s        |\n", nome);
    
    // LEITURA DAS 5 NOTAS
    printf("Digite as 5 notas do aluno:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%d", &notas[i]);
        soma += notas[i];  // ACUMULA A SOMA GERAL
    }
    media = soma / 5.0;

    // VERIFICAÇÃO
    printf("\nMédia final: %.2f\n", media);
    if (media >= 7.0) {
        printf("Parabéns %s! Foi aprovado com média %.2f.\n", nome, media);
    }
    else if (media > 5.0 && media < 7.0) {
        printf("Aluno %s em recuperação com média %.2f.\n", nome, media);
    }
    else {
        printf("Aluno %s foi reprovado com média %.2f. Sinto muito!\n", nome, media);
    }

    return 0;
}
