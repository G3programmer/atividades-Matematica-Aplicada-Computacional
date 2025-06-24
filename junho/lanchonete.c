#include <stdio.h>

int main()
{
    int idade;
    char nome[50], a, rep;

    printf("Digite o seu nome:\n");
    scanf("%49s", nome);  // limite de 49 para evitar overflow
    printf("Digite a sua idade:\n");
    scanf("%d", &idade);

    printf("  ===== Seja Bem-vindo à Lanchonete do Gabriel Morozini =====\n");
    printf("              ===== Menu da lanchonete =====\n");
    printf("_______________________________________________________________\n");
    printf("---|   Lanche s   |-|  Preço  |-----|     Bebidas    |--|Preço|---|\n");
    printf("---|a) Hambúrguer |-| R$15,00 |-----|d) Refrigerante |--|Preço|---|\n");
    printf("---|b)  X-Salada  |-| R$17,00 |-----|e) Suco Natural |--|Preço|---|\n");
    printf("---|c)  X-Bacon   |-| R$18,50 |-----|~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("   |~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("Digite o seu pedido (letra):\n");

    scanf(" %c", &a);  // espaço para ignorar '\n'

    switch (a) {
        case 'a':
            printf("Você escolheu: Hambúrguer - R$15,00\nDeseja mais algo? (S ou N): ");
            scanf(" %c", &rep);
            if (rep == 'S' || rep == 's') {
                printf("Ok, pode pedir mais!\n");
                // aqui você pode continuar o programa para novo pedido
            } else {
                printf("Obrigado pelo pedido!\n");
                return 0;
            }
            break;

        case 'b':
            printf("Você escolheu: X-Salada - R$17,00\nDeseja mais algo? (S ou N): ");
            scanf(" %c", &rep);
            if (rep == 'S' || rep == 's') {
                printf("Ok, pode pedir mais!\n");
            } else {
                printf("Obrigado pelo pedido!\n");
                return 0;
            }
            break;

        case 'c':
            printf("Você escolheu: X-Bacon - R$18,50\nDeseja mais algo? (S ou N): ");
            scanf(" %c", &rep);
            if (rep == 'S' || rep == 's') {
                printf("Ok, pode pedir mais!\n");
            } else {
                printf("Obrigado pelo pedido!\n");
                return 0;
            }
            break;

        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}
