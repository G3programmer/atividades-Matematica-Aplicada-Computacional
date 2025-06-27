#include <stdio.h>
#include <string.h>

/*
SE ENCONTRAR UM MÉTODO MELHOR, SINTA-SE BEM EM ATUALIZAR!
MI CASA ES SU CASA ;)
*/

int main() {
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
    char recibo_final[1000] = "";
    char temp_recibo[100] = "";

    // STRINGS AUXILIARES
    char item_nome[30];
    char sabor[30];
    
while (1) {
    printf("Digite o seu nome:\n");
    scanf(" %[^\n]", nome);

    printf("Digite a sua idade:\n");
    scanf("%d", &idade);

    if (idade > 120) {
        printf("Idade inválida! É impossível ter mais de 120 anos.\n\n");
        continue; // SEI QUE VOCÊ NÃO TEM E NEM MAIS QUE 120 ANOS 
    }

    if (idade < 13) {
        printf("Desculpe, você precisa ter pelo menos 13 anos para comprar.\n\n");
        continue; // MUITO JOVEM, PEÇA A UM RESPONÁVEL MAIS VELHO
    }

    break; // OK
}


    while (1) {
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
        switch (a) {
        case 'a':
        case 'b':
        case 'c': {
        inicio_pedido:
            adicionais = 0.0;
            preco_base = 0.0;
            qtd = 0;
            cancelar = 0;
            temp_recibo[0] = '\0'; //LIMPO POR UM TEMPO

            /* DEIXEI JUNTO POR CONTA DAS OPÇÕES ADICIONAIS, EU QUIS RECICLAR ;) */
            if (a == 'a') {
                printf("Você escolheu: Hambúrguer - R$15,00\n");
                preco_base = 15.00;
                strcpy(item_nome, "Hambúrguer");
            } else if (a == 'b') {
                printf("Você escolheu: X-Salada - R$17,00\n");
                preco_base = 17.00;
                strcpy(item_nome, "X-Salada");
            } else if (a == 'c') {
                printf("Você escolheu: X-Bacon - R$18,50\n");
                preco_base = 18.50;
                strcpy(item_nome, "X-Bacon");
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
                do {
                    printf("Deseja adicionar bacon por R$2,50? (S/N): ");
                    scanf(" %c", &bacon);
                } while (bacon != 'S' && bacon != 's' && bacon != 'N' && bacon != 'n');

                if (bacon == 'S' || bacon == 's')
                    adicionais += qtd * 2.50;

                do {
                    printf("Deseja carne extra por R$5,00? (S/N): ");
                    scanf(" %c", &carne);
                } while (carne != 'S' && carne != 's' && carne != 'N' && carne != 'n');

                if (carne == 'S' || carne == 's')
                    adicionais += qtd * 5.00;

                total += adicionais;
            }

            /*MOSTRA O RELATÓRIO DO USUÁRIO*/
            printf("\n#############################################################\n");
            printf("#                   RESUMO DO PEDIDO                        #\n");
            printf("#-----------------------------------------------------------#\n");
            printf("# Descrição do item                                         #\n");
            printf("#-----------------------------------------------------------#\n");
            printf("# Item                       | Qtd |     Total              #\n");
            printf("#----------------------------|-----|------------------------#\n");

            sprintf(temp_recibo, "# %-26s | %3d | R$ %7.2f            #\n", item_nome, qtd, qtd * preco_base);
            strcat(recibo_final, temp_recibo);
            printf("%s", temp_recibo);

            if (a == 'a') {
                if (maionese == 'S' || maionese == 's') {
                    sprintf(temp_recibo, "# %-26s |     | R$ %7.2f            #\n", "Com maionese", 0.00);
                    strcat(recibo_final, temp_recibo);
                    printf("%s", temp_recibo);
                }
                if (pepino == 'S' || pepino == 's') {
                    sprintf(temp_recibo, "# %-26s |     | R$ %7.2f            #\n", "Com pepino", 0.00);
                    strcat(recibo_final, temp_recibo);
                    printf("%s", temp_recibo);
                }
            } else {
                if (molho == 'S' || molho == 's') {
                    sprintf(temp_recibo, "# %-26s |     | R$ %7.2f            #\n", "Com molho", 0.00);
                    strcat(recibo_final, temp_recibo);
                    printf("%s", temp_recibo);
                }
                if (ketchup == 'S' || ketchup == 's') {
                    sprintf(temp_recibo, "# %-26s |     | R$ %7.2f            #\n", "Com ketchup", 0.00);
                    strcat(recibo_final, temp_recibo);
                    printf("%s", temp_recibo);
                }
                if (mostarda == 'S' || mostarda == 's') {
                    sprintf(temp_recibo, "# %-26s |     | R$ %7.2f            #\n", "Com mostarda", 0.00);
                    strcat(recibo_final, temp_recibo);
                    printf("%s", temp_recibo);
                }
                if (molho_verde == 'S' || molho_verde == 's') {
                    sprintf(temp_recibo, "# %-26s |     | R$ %7.2f            #\n", "Molho verde", qtd * 2.00);
                    strcat(recibo_final, temp_recibo);
                    printf("%s", temp_recibo);
                }
            }

            if (bacon == 'S' || bacon == 's') {
                sprintf(temp_recibo, "# %-26s |     | R$ %7.2f            #\n", "Bacon extra", qtd * 2.50);
                strcat(recibo_final, temp_recibo);
                printf("%s", temp_recibo);
            }
            if (carne == 'S' || carne == 's') {
                sprintf(temp_recibo, "# %-26s |     | R$ %7.2f            #\n", "Carne extra", qtd * 5.00);
                strcat(recibo_final, temp_recibo);
                printf("%s", temp_recibo);
            }

            printf("#-----------------------------------------------------------#\n");
            printf("# Total parcial acumulado:        R$ %7.2f                 #\n", total);
            printf("##############################################################\n");

            /*A PERGUNTA MAIS PERIGOSA DE TODAS*/
            printf("\nDeseja editar ou cancelar o pedido? (E para editar, C para cancelar, N para continuar): ");
            scanf(" %c", &editar);

            /*CANCELOU, JÁ ERA*/
            if (editar == 'C' || editar == 'c') {
                printf("Pedido cancelado.\n");
                cancelar = 1;
                total = 0;
                recibo_final[0] = '\0'; // LIMPA O RECIBO
            }

            /*AQUI ELE VOLTA PARA AO 0 PARA MUDAR*/
            else if (editar == 'E' || editar == 'e') {
                printf("Voltando para edição...\n");
                total -= adicionais + (qtd * preco_base);
                recibo_final[0] = '\0'; // Limpa o recibo para edição
                goto inicio_pedido;
            }

            /*CONFIMAÇÃO DE CERTEZA*/
            if (!cancelar) {
                printf("\nDeseja pedir mais algo? (S ou N): ");
                scanf(" %c", &rep);
                if (rep == 'S' || rep == 's') {
                    goto menu_principal;
                } else {
                    printf("#############################################################\n");
                    printf("#                   RESUMO FINAL DO PEDIDO                  #\n");
                    printf("#-----------------------------------------------------------#\n");
                    printf("# Item                       | Qtd |     Total              #\n");
                    printf("#----------------------------|-----|------------------------#\n");
                    printf("%s", recibo_final); // PEGA TUDO E SOMA
                    printf("#-----------------------------------------------------------#\n");
                    printf("# Total final acumulado:        R$ %7.2f                 #\n", total);
                    printf("#############################################################\n");
                    printf("Obrigado pelo pedido, %s!\n", nome);

                    return 0;
                }
            }
            break;
        }

        case 'd': {
            float preco_bebida = 6.00;
            char opcao_sabor;
            char sabor[30];
            char editar_bebida;
            int cancelar_bebida = 0;
            int qtd_bebida = 0;

        editar_refrigerante:
            printf("Você escolheu: Refrigerante - R$6,00\n");
            temp_recibo[0] = '\0'; // LIMPO TEMPORARIAMENTE

            // USUÁRIO, DIGA QUANTOS VOCÊ QUER!
            do {
                printf("Quantos deseja? (Máx. 10): ");
                scanf("%d", &qtd_bebida);
                if (qtd_bebida < 1 || qtd_bebida > 10)
                    printf("Quantidade inválida! Tente novamente.\n");
            } while (qtd_bebida < 1 || qtd_bebida > 10);

            // ESCOLHA BEM O SABOR
            printf("Escolha o sabor:\n");
            printf(" a) Coca-Cola\n b) Guaraná\n c) Laranja\n");
            printf("Digite a letra do sabor desejado: ");
            scanf(" %c", &opcao_sabor);

            switch (opcao_sabor) {
            case 'a':
                strcpy(sabor, "Coca-Cola");
                break;
            case 'b':
                strcpy(sabor, "Guaraná");
                break;
            case 'c':
                strcpy(sabor, "Laranja");
                break;
            default:
                strcpy(sabor, "Desconhecido");
            }

            total += preco_bebida * qtd_bebida;

            // RECIBO QUE MOSTRA
            printf("\n#############################################################\n");
            printf("#                   RESUMO DO PEDIDO                        #\n");
            printf("#-----------------------------------------------------------#\n");
            printf("# Descrição do item                                         #\n");
            printf("#-----------------------------------------------------------#\n");
            printf("# Item                       | Qtd |     Total              #\n");
            printf("#----------------------------|-----|------------------------#\n");
            sprintf(temp_recibo, "# %-26s | %3d | R$ %7.2f            #\n", sabor, qtd_bebida, preco_bebida * qtd_bebida);
            strcat(recibo_final, temp_recibo);
            printf("%s", temp_recibo);
            printf("#-----------------------------------------------------------#\n");
            printf("# Total parcial acumulado:        R$ %7.2f                 #\n", total);
            printf("##############################################################\n");

            //PARTE DO  "EDITA, CANCELA OU CONTINUA?"
            printf("\nDeseja editar ou cancelar o pedido? (E para editar, C para cancelar, N para continuar): ");
            scanf(" %c", &editar_bebida);

            if (editar_bebida == 'C' || editar_bebida == 'c') {
                printf("Pedido cancelado.\n");
                cancelar_bebida = 1;
                total -= preco_bebida * qtd_bebida;
                recibo_final[0] = '\0'; // RESETA
            } else if (editar_bebida == 'E' || editar_bebida == 'e') {
                printf("Voltando para edição...\n");
                total -= preco_bebida * qtd_bebida;
                recibo_final[0] = '\0'; // LIMPO PARA A EDIÇÃO
                goto editar_refrigerante;
            }

            if (!cancelar_bebida) {
                printf("\nDeseja pedir mais algo? (S ou N): ");
                scanf(" %c", &rep);
                if (rep == 'S' || rep == 's') {
                    goto menu_principal;
                } else {
                    printf("#############################################################\n");
                    printf("#                   RESUMO FINAL DO PEDIDO                  #\n");
                    printf("#-----------------------------------------------------------#\n");
                    printf("# Item                       | Qtd |     Total              #\n");
                    printf("#----------------------------|-----|------------------------#\n");
                    printf("%s", recibo_final); //O VALOR FINAL APRESENTA AQUI
                    printf("#-----------------------------------------------------------#\n");
                    printf("# Total final acumulado:        R$ %7.2f                 #\n", total);
                    printf("#############################################################\n");
                    printf("Obrigado pelo pedido, %s!\n", nome);

                    return 0;
                }
            }
            break;
        }

        case 'e': {
            float preco_suco = 7.50;
            char opcao_sabor;
            char sabor[30];
            char com_leite, com_gelo;
            char editar_suco;
            int cancelar_suco = 0;
            int qtd_bebida = 0;

        editar_suco:
            printf("Você escolheu: Suco Natural - R$7,50\n");
            temp_recibo[0] = '\0'; // TEMPORARIAMENTE LIMPO

            do {
                printf("Quantos deseja? (Máx. 10): ");
                scanf("%d", &qtd_bebida);
                if (qtd_bebida < 1 || qtd_bebida > 10)
                    printf("Quantidade inválida! Tente novamente.\n");
            } while (qtd_bebida < 1 || qtd_bebida > 10);

            printf("Escolha o sabor do suco:\n");
            printf(" a) Uva\n b) Morango\n c) Abacaxi\n d) Maracujá\n");
            printf("Digite a letra do sabor desejado: ");
            scanf(" %c", &opcao_sabor);

            switch (opcao_sabor) {
            case 'a':
                strcpy(sabor, "Uva");
                break;
            case 'b':
                strcpy(sabor, "Morango");
                break;
            case 'c':
                strcpy(sabor, "Abacaxi");
                break;
            case 'd':
                strcpy(sabor, "Maracujá");
                break;
            default:
                strcpy(sabor, "Desconhecido");
            }

            printf("Deseja com leite? (S/N): ");
            scanf(" %c", &com_leite);
            printf("Deseja com gelo? (S/N): ");
            scanf(" %c", &com_gelo);

            total += preco_suco * qtd_bebida;

            printf("\n#############################################################\n");
            printf("#                   RESUMO DO PEDIDO                        #\n");
            printf("#-----------------------------------------------------------#\n");
            printf("# Descrição do item                                         #\n");
            printf("#-----------------------------------------------------------#\n");
            printf("# Item                       | Qtd |     Total              #\n");
            printf("#----------------------------|-----|------------------------#\n");
            sprintf(temp_recibo, "# Suco natural sabor %-10s | %3d | R$ %7.2f          #\n", sabor, qtd_bebida, preco_suco * qtd_bebida);
            strcat(recibo_final, temp_recibo);
            printf("%s", temp_recibo);
            if (com_leite == 'S' || com_leite == 's') {
                sprintf(temp_recibo, "# %-26s |     | R$ %7.2f             #\n", "Com leite", 0.00);
                strcat(recibo_final, temp_recibo);
                printf("%s", temp_recibo);
            }
            if (com_gelo == 'S' || com_gelo == 's') {
                sprintf(temp_recibo, "# %-26s |     | R$ %7.2f             #\n", "Com gelo", 0.00);
                strcat(recibo_final, temp_recibo);
                printf("%s", temp_recibo);
            }

            printf("#-----------------------------------------------------------#\n");
            printf("# Total parcial acumulado:        R$ %7.2f                 #\n", total);
            printf("##############################################################\n");

            // USUÁRIO, QUER EDITAR OU CANCELAR?
            printf("\nDeseja editar ou cancelar o pedido? (E para editar, C para cancelar, N para continuar): ");
            scanf(" %c", &editar_suco);

            if (editar_suco == 'C' || editar_suco == 'c') {
                printf("Pedido cancelado.\n");
                cancelar_suco = 1;
                total -= preco_suco * qtd_bebida;
                recibo_final[0] = '\0'; // RESETA
            } else if (editar_suco == 'E' || editar_suco == 'e') {
                printf("Voltando para edição...\n");
                total -= preco_suco * qtd_bebida;
                recibo_final[0] = '\0'; // DEIXA PRONTO PARA A EDIÇÃO
                goto editar_suco;
            }

            if (!cancelar_suco) {
                printf("\nDeseja pedir mais algo? (S ou N): ");
                scanf(" %c", &rep);
                if (rep == 'S' || rep == 's') {
                    goto menu_principal;
                } else {
                    printf("#############################################################\n");
                    printf("#                   RESUMO FINAL DO PEDIDO                  #\n");
                    printf("#-----------------------------------------------------------#\n");
                    printf("# Item                       | Qtd |     Total              #\n");
                    printf("#----------------------------|-----|------------------------#\n");
                    printf("%s", recibo_final); //O VALOR FINAL APRESENTA AQUI
                    printf("#-----------------------------------------------------------#\n");
                    printf("# Total final acumulado:        R$ %7.2f                 #\n", total);
                    printf("#############################################################\n");
                    printf("Obrigado pelo pedido, %s!\n", nome);

                    return 0;
                }
            }
            break;
        }
        }
    }
    return 0;
}
