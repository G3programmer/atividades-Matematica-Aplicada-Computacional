#include <stdio.h>
#include <locale.h>
#include "func.h"

int main() {
    setlocale(LC_ALL, "Portuguese.1252");

    Livro livros[10];
    int qtd = 0;
    int opcao;

    do {
        printf("\n=== Sistema de Biblioteca ===\n");
        printf("1. Cadastrar novo livro\n");
        printf("2. Listar todos os livros\n");
        printf("3. Emprestar livro\n");
        printf("4. Devolver livro\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                qtd = cadastrarLivro(livros, qtd);
                break;
            case 2:
                qtd = listarLivros(livros, qtd);
                break;
            case 3:
                qtd = emprestarLivro(livros, qtd);
                break;
            case 4:
                qtd = devolverLivro(livros, qtd);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
