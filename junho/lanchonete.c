#include <stdio.h>
#include <string.h> 

int main() {
    int idade, qtd = 0, cancelar = 0;
    float total = 0.0, adicionais = 0.0, preco_base = 0.0;
    char nome[50], a, rep, maionese, pepino, bacon, carne, molho, editar;
    char ketchup, mostarda, molho_verde;

    printf("Digite o seu nome:\n");
    scanf(" %[^\n]", nome);
    printf("Digite a sua idade:\n");
    scanf("%d", &idade);

menu_principal:  /*DEPOIS QUE O USUÁRIO "FALA QUERO MAIS", VOLTA AQUI*/

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

/*AQUI É TODA A PARTE DE ESCOLHAS (O FILHO CHORA E A MÃE TAMBÉM)*/

    switch (a) {
        case 'a':
        case 'b':
        case 'c': {
            inicio_pedido:

            adicionais = 0.0;
            preco_base = 0.0;
            qtd = 0;
            cancelar = 0;
            
/* DEIXEI JUNTO POR CPNTA DAS OPÇÕES ADICIONAIS, EU QUIS RECICLAR ;) */
            
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
/*EU CHEGUEI A CONCLUSÃO DE QUE 10 É O SUFICIENTE, NUNCA VI PEDIREM 11 LANCHES*/
            do {
                printf("Quantos você deseja? (Máx. 10): ");
                scanf("%d", &qtd);
                if (qtd < 1 || qtd > 10) {
                    printf("Quantidade inválida! Tente novamente.\n");
                }
            } while (qtd < 1 || qtd > 10);

            total += qtd * preco_base;

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
                if (molho_verde == 'S' || molho_verde == 's') {
                    adicionais += qtd * 2.00;
                }
            }
            
            /*OPÇÕES QUE ACRESCENTAM NO VALOR :) */
            
            if (a == 'a' || a == 'c') {
                printf("Deseja adicionar bacon por R$2,50? (S/N): ");
                scanf(" %c", &bacon);
                if (bacon == 'S' || bacon == 's') adicionais += qtd * 2.50;

                printf("Deseja carne extra por R$5,00? (S/N): ");
                scanf(" %c", &carne);
                if (carne == 'S' || carne == 's') adicionais += qtd * 5.00;
            }

            total += adicionais;
            
            /*MOSTRA O RELATÓRIO DO CABOCO*/
            
            printf("\n#############################################################\n");
printf("#                   RESUMO DO PEDIDO                        #\n");
printf("#-----------------------------------------------------------#\n");
printf("# Descrição do item                                         #\n");
printf("#-----------------------------------------------------------#\n");
printf("# Item                       | Qtd |     Total              #\n");
printf("#----------------------------|-----|------------------------#\n");

char item_nome[30];
if (a == 'a') strcpy(item_nome, "Hambúrguer");
else if (a == 'b') strcpy(item_nome, "X-Salada");
else strcpy(item_nome, "X-Bacon");

printf("# %-26s | %3d | R$ %7.2f            #\n", item_nome, qtd, qtd * preco_base);

if (a == 'a') {
    if (maionese == 'S' || maionese == 's')
        printf("# %-26s |     | R$ %7.2f            #\n", "Com maionese", 0.00);
    if (pepino == 'S' || pepino == 's')
        printf("# %-26s |     | R$ %7.2f            #\n", "Com pepino", 0.00);
} else {
    if (molho == 'S' || molho == 's')
        printf("# %-26s |     | R$ %7.2f            #\n", "Com molho", 0.00);
    if (ketchup == 'S' || ketchup == 's')
        printf("# %-26s |     | R$ %7.2f            #\n", "Com ketchup", 0.00);
    if (mostarda == 'S' || mostarda == 's')
        printf("# %-26s |     | R$ %7.2f            #\n", "Com mostarda", 0.00);
    if (molho_verde == 'S' || molho_verde == 's')
        printf("# %-26s |     | R$ %7.2f            #\n", "Molho verde", qtd * 2.00);
}

if (bacon == 'S' || bacon == 's')
    printf("# %-26s |     | R$ %7.2f            #\n", "Bacon extra", qtd * 2.50);
if (carne == 'S' || carne == 's')
    printf("# %-26s |     | R$ %7.2f            #\n", "Carne extra", qtd * 5.00);

printf("#-----------------------------------------------------------#\n");
printf("# Total parcial acumulado:        R$ %7.2f                 #\n", total);
printf("##############################################################\n");


            printf("\nDeseja editar ou cancelar o pedido? (E para editar, C para cancelar, N para continuar): ");
            scanf(" %c", &editar);

            if (editar == 'C' || editar == 'c') {
                printf("Pedido cancelado.\n");
                cancelar = 1;
                total = 0;
            } else if (editar == 'E' || editar == 'e') {
                printf("Voltando para edição...\n");
                total -= adicionais + (qtd * preco_base);
                goto inicio_pedido;
            }

            if (!cancelar) {
                printf("\nDeseja pedir mais algo? (S ou N): ");
                scanf(" %c", &rep);
                if (rep == 'S' || rep == 's') {
                    goto menu_principal;
                } else {
                    printf("Total final do pedido: R$%.2f\n", total);
                    printf("Obrigado pelo pedido!\n");
                    return 0;
                }
            }

            break;
        }

        case 'd': {
            float preco_bebida = 6.00;
            char sabor[20], opcao_sabor;

            printf("Você escolheu: Refrigerante - R$6,00\n");
            printf("Escolha o sabor:\n");
            printf(" a) Coca-Cola\n b) Guaraná\n c) Laranja\n");
            printf("Digite a letra do sabor desejado: ");
            scanf(" %c", &opcao_sabor);

            switch (opcao_sabor) {
                case 'a': strcpy(sabor, "Coca-Cola"); break;
                case 'b': strcpy(sabor, "Guaraná"); break;
                case 'c': strcpy(sabor, "Laranja"); break;
                default: strcpy(sabor, "Desconhecido");
            }

            total += preco_bebida;

            printf("\nResumo do seu pedido:\n");
            printf("- 1 Refrigerante sabor %s: R$6,00\n", sabor);
            printf("Total parcial acumulado: R$%.2f\n", total);

            printf("\nDeseja pedir mais algo? (S ou N): ");
            scanf(" %c", &rep);
            if (rep == 'S' || rep == 's') {
                goto menu_principal;
            } else {
                printf("Total final do pedido: R$%.2f\n", total);
                printf("Obrigado pelo pedido!\n");
                return 0;
            }
            break;
        }

        case 'e': {
            float preco_suco = 7.50;
            char com_leite, com_gelo;

            printf("Você escolheu: Suco Natural - R$7,50\n");
            printf("Deseja com leite? (S/N): ");
            scanf(" %c", &com_leite);
            printf("Deseja com gelo? (S/N): ");
            scanf(" %c", &com_gelo);

            total += preco_suco;

            printf("\nResumo do seu pedido:\n");
            printf("- 1 Suco Natural: R$7,50\n");
            if (com_leite == 'S' || com_leite == 's') printf("- Com leite\n");
            if (com_gelo == 'S' || com_gelo == 's') printf("- Com gelo\n");
            printf("Total parcial acumulado: R$%.2f\n", total);

            printf("\nDeseja pedir mais algo? (S ou N): ");
            scanf(" %c", &rep);
            if (rep == 'S' || rep == 's') {
                goto menu_principal;
            } else {
                printf("Total final do pedido: R$%.2f\n", total);
                printf("Obrigado pelo pedido!\n");
                return 0;
            }
            break;
        }

        default:
            printf("Opção inválida!\n");
            goto menu_principal;
    }

    return 0;
}
