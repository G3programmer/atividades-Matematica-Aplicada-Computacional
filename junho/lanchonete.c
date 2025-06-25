#include <stdio.h>

int main()
{
    int idade, qtd = 0, cancelar = 0;
    float total = 0.0, adicionais = 0.0, preco_base = 0.0;
    char nome[50], a, rep, maionese, pepino, bacon, carne, molho, editar;
    char ketchup, mostarda, molho_verde;


/*ETAPA INICIAL DO CÓDIGO É APENAS APRESENTAÇÃO*/

    printf("Digite o seu nome:\n");
    scanf(" %[^\n]", nome);
    printf("Digite a sua idade:\n");
    scanf("%d", &idade);

menu_principal:  // AQUI É QUANDO O USUÁRIO QUISER PEDIR MAIS

    printf("  ===== Seja Bem-vindo à Lanchonete do Gabriel Morozini =====\n");
    printf("  ===========================================================\n");
    printf("     Nome: %-30s Idade: %-2d\n", nome, idade);
    printf("  ===========================================================\n");
    printf("               ===== Menu da lanchonete =====\n");
    printf(" _____________________________________________________________________\n");
    printf(" ---|    Lanches   |-|  Preço  |-----|     Bebidas    |--| Preço |---|\n");
    printf(" ---|a) Hambúrguer |-| R$15,00 |-----|d) Refrigerante |--|R$6,00 |---|\n");
    printf(" ---|b)  X-Salada  |-| R$17,00 |-----|e) Suco Natural |--|R$7,50 |---|\n");
    printf(" ---|c)  X-Bacon   |-| R$18,50 |-----|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("    |~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("Digite o seu pedido (letra):\n");

    scanf(" %c", &a);
    
/*AQUI COMEÇA AS OPÇÕES DE ESCOLHA (O FILHO CHORA E A MÃE TAMBÉM)*/
    
    switch (a) {
        case 'a':
        case 'b':
        case 'c': {
        inicio_pedido:

            adicionais = 0.0;
            total = 0.0;
            qtd = 0;
            cancelar = 0;

            if (a == 'a') {
                printf("Você escolheu: Hambúrguer - R$15,00\n");
                preco_base = 15.00;
            } else if (a == 'b') {
                printf("Você escolheu: X-Salada - R$17,00\n");
                preco_base = 17.00;
            } else if (a == 'c') {
                printf("Você escolheu: X-Bacon - R$18,50\n");
                preco_base = 18.50;
            }

            do {
                printf("Quantos você deseja? (Máx. 10): ");
                scanf("%d", &qtd);
                if (qtd < 1 || qtd > 10) {
                    printf("Quantidade inválida! Tente novamente.\n");
                }
            } while (qtd < 1 || qtd > 10);

            total = qtd * preco_base;

            /* OPÇÕES ADICIONAIS SE QUISER ENCHER TEU LANCHE*/
            
            if (a == 'a') {
                printf("Deseja com maionese? (S/N): ");
                scanf(" %c", &maionese);
                printf("Deseja com pepino? (S/N): ");
                scanf(" %c", &pepino);
            } else {
                printf("Deseja com molho? (S/N): ");
                scanf(" %c", &molho);
                printf("Deseja com ketchup? (S/N): ");
                scanf(" %c", &ketchup);
                printf("Deseja com mostarda? (S/N): ");
                scanf(" %c", &mostarda);

                printf("Deseja adicionar molho verde por R$2,00? (S/N): ");
                scanf(" %c", &molho_verde);
                if (molho_verde == 'S' || molho_verde == 's') adicionais += qtd * 2.00;
            }

            /* OPÇÃO QUE ADICIONA E PAGA, ME DEIXA FELIZ :) */
        
        if (a == 'a' || a == 'c') {
            printf("Deseja adicionar bacon por R$2,50? (S/N): ");
            scanf(" %c", &bacon);
        if (bacon == 'S' || bacon == 's') adicionais += qtd * 2.50;

            printf("Deseja carne extra por R$5,00? (S/N): ");
            scanf(" %c", &carne);
        if (carne == 'S' || carne == 's') adicionais += qtd * 5.00;
        }



            total += adicionais;

            printf("\nResumo do seu pedido:\n");
            printf("- %d unidade(s): R$%.2f\n", qtd, qtd * preco_base);
            if (a == 'a') {
                if (maionese == 'S' || maionese == 's') printf("- Com maionese\n");
                if (pepino == 'S' || pepino == 's') printf("- Com pepino\n");
            } else {
                if (molho == 'S' || molho == 's') printf("- Com molho\n");
                if (ketchup == 'S' || ketchup == 's') printf("- Com ketchup\n");
                if (mostarda == 'S' || mostarda == 's') printf("- Com mostarda\n");
                if (molho_verde == 'S' || molho_verde == 's') printf("- Molho verde: R$%.2f\n", qtd * 2.00);
            }
            if (bacon == 'S' || bacon == 's') printf("- Bacon: R$%.2f\n", qtd * 2.50);
            if (carne == 'S' || carne == 's') printf("- Carne extra: R$%.2f\n", qtd * 5.00);

            printf("Total parcial: R$%.2f\n", total);

                /*A PERGUNTA MAIS IMPORTANTE DE TODAS! :O*/
            printf("\nDeseja editar ou cancelar o pedido? (E para editar, C para cancelar, N para continuar): ");
            scanf(" %c", &editar);

            if (editar == 'C' || editar == 'c') {
                printf("Pedido cancelado.\n");
                cancelar = 1;
            } else if (editar == 'E' || editar == 'e') {
                printf("Voltando para edição...\n");
                goto inicio_pedido;
            }

           
            if (!cancelar) {
                printf("\nDeseja pedir mais algo? (S ou N): ");
                scanf(" %c", &rep);
                if (rep == 'S' || rep == 's') {
                    goto menu_principal;  /*AQUI VOLTA PARA O INÍCIO, PARA O INÍCIO, PARA O INÍCIO, PARA O INÍCIO, PARA O INÍCIO...*/
                } else {
                    printf("Total final do pedido: R$%.2f\n", total);
                    printf("Obrigado pelo pedido!\n");
                    return 0;
                }
            }

            break;
        }

        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}
