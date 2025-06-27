#include <stdio.h>

int main() {
    int a, b, c;

    while (1) {
        printf("Digite o valor de 'A': \n");
        scanf("%d", &a);
        printf("Digite o valor de 'B': \n");
        scanf("%d", &b);
        printf("Digite o valor de 'C': \n");
        scanf("%d", &c);

        if (a > 0 && b > 0 && c > 0) {
            if (a == b && b == c) {
                printf("Seu triangulo é um triângulo Equilátero! \n");
            }
            else if (a == b || b == c || a == c) {
                printf("Seu triangulo é um triângulo Isóceles! \n");
            }
            else {
                printf("Seu triangulo é um triângulo Escaleno! \n");
            }
            break; // sai do laço se tudo estiver ok
        } else {
            printf("Valores inválidos! Tente novamente!\n\n");
            // o laço continua automaticamente, sem precisar de "continue"
        }
    }

    return 0;
}
