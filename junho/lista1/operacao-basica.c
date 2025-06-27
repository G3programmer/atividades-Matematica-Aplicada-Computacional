#include <stdio.h>

int main() {
    int a, b, d;
    char c;
    
    printf("Digite o primeiro número: \n");
    scanf(" %d", &a);
    printf("Digite a operação(+,-,*,/): \n");
    scanf(" %c", &c);
    printf("Digite o segundo número: \n");
    scanf(" %d", &b);
    
    switch(c) {
        case '+': 
            d=a+b;
            printf("A soma de %d e %d é igual a %d\n", a, b, d);
            break;
        case '-':
            d = a - b;
            printf("A subtração de %d e %d é igual a %d\n", a, b, d);
            break;
        case '*':
            d = a * b;
            printf("A multiplicação de %d e %d é igual a %d\n", a, b, d);
            break;
        case '/':
            if (b != 0) {
                d = a / b;
                printf("A divisão de %d por %d é igual a %d\n", a, b, d);
            } else {
                printf("Erro: divisão por zero não é permitida.\n");
            }
            break;
        default:
            printf("Operador inválido.\n");

    }
    return 0;
}
