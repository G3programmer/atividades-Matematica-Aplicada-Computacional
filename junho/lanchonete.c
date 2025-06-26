#include <stdio.h>
#include <string.h>

int main()
{
    // VALORES NUMÉRICOS
    int idade, qtd = 0, cancelar = 0;

    // FLOATS
    float total = 0.0, adicionais = 0.0, preco_base = 0.0;
    float preco_bebida = 0.0, preco_suco = 0.0;

    // CARACTERES GERAIS
    char nome[50];
    char a, rep, editar;
    char maionese, pepino, bacon, carne, molho, ketchup, mostarda, molho_verde;
    char com_leite, com_gelo, opcao_sabor;

    // STRINGS AUXILIARES
    char item_nome[30];
    char sabor[20];

    printf("Digite o seu nome:\n");
    scanf(" %[^\n]", nome);
    printf("Digite a sua idade:\n");
    scanf("%d", &idade);

    while (1)
    {
    menu_principal: /*DEPOIS QUE O USUÁRIO "FALA QUERO MAIS", VOLTA AQUI*/

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

        switch (a)
        {
        case 'a':
        case 'b':
        case 'c':
        {
        inicio_pedido:

            adicionais = 0.0;
            preco_base = 0.0;
            qtd = 0;
            cancelar = 0;

            /* DEIXEI JUNTO POR CONTA DAS OPÇÕES ADICIONAIS, EU QUIS RECICLAR ;) */

            if (a == 'a')
            {
                printf("Você escolheu: Hambúrguer - R$15,00\n");
                preco_base = 15.00;
            }
            else if (a == 'b')
            {
                printf("Você escolheu: X-Salada - R$17,00\n");
                preco_base = 17.00;
            }
            else if (a == 'c')
            {
                printf("Você escolheu: X-Bacon - R$18,50\n");
                preco_base = 18.50;
            }
            /*EU CHEGUEI A CONCLUSÃO DE QUE 10 É O SUFICIENTE, NUNCA VI PEDIREM 11 LANCHES*/
            do
            {
                printf("Quantos você deseja? (Máx. 10): ");
                scanf("%d", &qtd);
                if (qtd < 1 || qtd > 10)
                {
                    printf("Quantidade inválida! Tente novamente.\n");
                }
            } while (qtd < 1 || qtd > 10);

            total += qtd * preco_base;

            if (a == 'a')
            {
                printf("Deseja com maionese? (S/N): ");
                scanf(" %c", &maionese);
                printf("Deseja com pepino? (S/N): ");
                scanf(" %c", &pepino);
            }
            else
            {
                printf("Deseja com molho? (S/N): ");
                scanf(" %c", &molho);
                printf("Deseja com ketchup? (S/N): ");
                scanf(" %c", &ketchup);
                printf("Deseja com mostarda? (S/N): ");
                scanf(" %c", &mostarda);

                printf("Deseja adicionar molho verde por R$2,00? (S/N): ");
                scanf(" %c", &molho_verde);
                if (molho_verde == 'S' || molho_verde == 's')
                {
                    adicionais += qtd * 2.00;
                }
            }

            /*OPÇÕES QUE ACRESCENTAM NO VALOR :) */

            if (a == 'a' || a == 'c')
            {
                do
                {
                    printf("Deseja adicionar bacon por R$2,50? (S/N): ");
                    scanf(" %c", &bacon);
                } while (bacon != 'S' && bacon != 's' && bacon != 'N' && bacon != 'n');

                if (bacon == 'S' || bacon == 's')
                    adicionais += qtd * 2.50;

                do
                {
                    printf("Deseja carne extra por R$5,00? (S/N): ");
                    scanf(" %c", &carne);
                } while (carne != 'S' && carne != 's' && carne != 'N' && carne != 'n');

                if (carne == 'S' || carne == 's')
                    adicionais += qtd * 5.00;

                total += adicionais;

                /*MOSTRA O RELATÓRIO DO USUÁRIO*/

                printf("\n#############################################################\n");
                printf("#                   RESUMO DO PEDIDO                        #\n");
                printf("#-----------------------------------------------------------#\n");
                printf("# Descrição do item                                         #\n");
                printf("#-----------------------------------------------------------#\n");
                printf("# Item                       | Qtd |     Total              #\n");
                printf("#----------------------------|-----|------------------------#\n");

                char item_nome[30];
                if (a == 'a')
                    strcpy(item_nome, "Hambúrguer");
                else if (a == 'b')
                    strcpy(item_nome, "X-Salada");
                else
                    strcpy(item_nome, "X-Bacon");

                printf("# %-26s | %3d | R$ %7.2f            #\n", item_nome, qtd, qtd * preco_base);

                if (a == 'a')
                {
                    if (maionese == 'S' || maionese == 's')
                        printf("# %-26s |     | R$ %7.2f            #\n", "Com maionese", 0.00);
                    if (pepino == 'S' || pepino == 's')
                        printf("# %-26s |     | R$ %7.2f            #\n", "Com pepino", 0.00);
                }
                else
                {
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

                /*A PERGUNTA MAIS PERIGOSA DE TODAS*/

                printf("\nDeseja editar ou cancelar o pedido? (E para editar, C para cancelar, N para continuar): ");
                scanf(" %c", &editar);

                /*CANCELOU, JÁ ERA*/

                if (editar == 'C' || editar == 'c')
                {
                    printf("Pedido cancelado.\n");
                    cancelar = 1;
                    total = 0;
                }

                /*AQUI ELE VOLTA PARA AO 0 PARA MUDAR*/
                else if (editar == 'E' || editar == 'e')
                {
                    printf("Voltando para edição...\n");
                    total -= adicionais + (qtd * preco_base);
                    goto inicio_pedido;
                }

                /*CONFIMAÇÃO DE CERTEZA*/
                if (!cancelar)
                {
                    printf("\nDeseja pedir mais algo? (S ou N): ");
                    scanf(" %c", &rep);
                    if (rep == 'S' || rep == 's')
                    {
                        goto menu_principal;
                    }

                    /*DISSE NÃO, BOA*/
                    else
                    {
                        printf("Total final do pedido: R$%.2f\n", total);
                        printf("Obrigado pelo pedido!\n");
                        return 0;
                    }
                }

                break;
            }

        /* AS OPÇÕES DE BEBIDAS SÃO DIFERENTES, ENTÃO NÃO RECICLEI :( */
case 'd': {
    float preco_bebida = 6.00;
    char opcao_sabor;
    char sabor[30];
    char editar_bebida;
    int cancelar_bebida = 0;

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

    // Mostrar recibo no layout padrão
    printf("\n#############################################################\n");
    printf("#                   RESUMO DO PEDIDO                        #\n");
    printf("#-----------------------------------------------------------#\n");
    printf("# Descrição do item                                         #\n");
    printf("#-----------------------------------------------------------#\n");
    printf("# Item                       | Qtd |     Total              #\n");
    printf("#----------------------------|-----|------------------------#\n");
    printf("# %-26s |   1 | R$ %7.2f            #\n", sabor, preco_bebida);
    printf("#-----------------------------------------------------------#\n");
    printf("# Total parcial acumulado:        R$ %7.2f                 #\n", total);
    printf("##############################################################\n");

    // Pergunta se quer editar ou cancelar
    printf("\nDeseja editar ou cancelar o pedido? (E para editar, C para cancelar, N para continuar): ");
    scanf(" %c", &editar_bebida);

    if (editar_bebida == 'C' || editar_bebida == 'c') {
        printf("Pedido cancelado.\n");
        cancelar_bebida = 1;
        total -= preco_bebida;
    } else if (editar_bebida == 'E' || editar_bebida == 'e') {
        printf("Voltando para edição...\n");
        total -= preco_bebida;
        // Forçar voltar para essa bebida (pode usar um loop ou goto local)
        // Aqui vamos simplificar com um goto local:
        goto editar_refrigerante;
    }

    if (!cancelar_bebida) break;

editar_refrigerante:
    // Repetir o processo para refrigerante (escolher sabor e adicionar valor)
    // Copiar o código acima ou criar função para não repetir código

    break;
}

case 'e': {
    float preco_suco = 7.50;
    char opcao_sabor;
    char sabor[30];
    char com_leite, com_gelo;
    char editar_suco;
    int cancelar_suco = 0;

    printf("Você escolheu: Suco Natural - R$7,50\n");
    printf("Escolha o sabor do suco:\n");
    printf(" a) Uva\n b) Morango\n c) Abacaxi\n d) Maracujá\n");
    printf("Digite a letra do sabor desejado: ");
    scanf(" %c", &opcao_sabor);

    switch (opcao_sabor) {
        case 'a': strcpy(sabor, "Uva"); break;
        case 'b': strcpy(sabor, "Morango"); break;
        case 'c': strcpy(sabor, "Abacaxi"); break;
        case 'd': strcpy(sabor, "Maracujá"); break;
        default: strcpy(sabor, "Desconhecido");
    }

    printf("Deseja com leite? (S/N): ");
    scanf(" %c", &com_leite);
    printf("Deseja com gelo? (S/N): ");
    scanf(" %c", &com_gelo);

    total += preco_suco;

    printf("\n#############################################################\n");
    printf("#                   RESUMO DO PEDIDO                        #\n");
    printf("#-----------------------------------------------------------#\n");
    printf("# Descrição do item                                         #\n");
    printf("#-----------------------------------------------------------#\n");
    printf("# Item                       | Qtd |     Total              #\n");
    printf("#----------------------------|-----|------------------------#\n");
    printf("# Suco natural sabor %-14s |   1 | R$ %7.2f            #\n", sabor, preco_suco);
    if (com_leite == 'S' || com_leite == 's')
        printf("# Com leite                                             |     | R$ %7.2f            #\n", 0.00);
    if (com_gelo == 'S' || com_gelo == 's')
        printf("# Com gelo                                              |     | R$ %7.2f            #\n", 0.00);
    printf("#-----------------------------------------------------------#\n");
    printf("# Total parcial acumulado:        R$ %7.2f                 #\n", total);
    printf("##############################################################\n");

    // Pergunta se quer editar ou cancelar
    printf("\nDeseja editar ou cancelar o pedido? (E para editar, C para cancelar, N para continuar): ");
    scanf(" %c", &editar_suco);

    if (editar_suco == 'C' || editar_suco == 'c') {
        printf("Pedido cancelado.\n");
        cancelar_suco = 1;
        total -= preco_suco;
    } else if (editar_suco == 'E' || editar_suco == 'e') {
        printf("Voltando para edição...\n");
        total -= preco_suco;
        goto editar_suco_label;
    }

    if (!cancelar_suco) break;

editar_suco_label:
    // Repetir a parte de edição para suco aqui (ou colocar em função)

    break;
}

    return 0;
}
}
    }

    }
