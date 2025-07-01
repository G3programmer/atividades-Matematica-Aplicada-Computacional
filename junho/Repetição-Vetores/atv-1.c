#include <stdio.h>

int main() {
    int numeros[10];  //VETOR DE 10 NÚMEROS
    int par,impar,i;
    par=0;
    impar=0;

    // LEITURA DOS NÚMEROS
    for (i = 0; i < 10; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // VERIFICAR  SE É PAR OU ÍMPAR
    for (i = 0; i < 10; i++) {
        if(numeros[i]%2==0){
            par++;
        }
        else{
            impar++;
        }
            
    }

    // EXIBIÇÃO GERAL
    printf("\nVocê digitou 10 números e esta é a relação geral da matriz:\n");
        for (i = 0; i < 10; i++) {
        printf("%4d", numeros[i]);  // LARGURA 4 PARA ALINHAR
        if ((i + 1) % 5 == 0)       // A LINHA QUEBRA A CADA 5 ELEMENTOS
            printf("\n");
    }
        printf("###########################\n");
        printf("# Pares:   # %d #\n", par);
        printf("# Ímpares: # %d #\n", impar);
        printf("###########################\n");

    return 0;
}
