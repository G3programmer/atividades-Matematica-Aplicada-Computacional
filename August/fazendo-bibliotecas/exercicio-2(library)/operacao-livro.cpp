#include <stdio.h>
#include <string.h>
#include "func.h"

int cadastrarLivro(Livro livros[], int qtd) {
    if (qtd >= 10) {
        printf("Limite de livros atingido!\n");
        return qtd;
    }
    printf("Titulo: ");
    scanf(" %49[^\n]", livros[qtd].titulo);
    printf("Autor: ");
    scanf(" %49[^\n]", livros[qtd].autor);
    printf("ISBN: ");
    scanf(" %19s", livros[qtd].isbn);
    livros[qtd].emprestado = 0; // disponivel
    printf("Livro cadastrado com sucesso!\n");
    return qtd + 1;
}

int listarLivros(Livro livros[], int qtd) {
    if (qtd == 0) {
        printf("Nenhum livro cadastrado.\n");
        return qtd;
    }
    for (int i = 0; i < qtd; i++) {
        printf("%d - %s | %s | ISBN: %s | %s\n", 
            i + 1, livros[i].titulo, livros[i].autor, livros[i].isbn, 
            livros[i].emprestado ? "Emprestado" : "Disponivel");
    }
    return qtd;
}

int emprestarLivro(Livro livros[], int qtd) {
    char busca[20];
    printf("Digite o ISBN do livro a emprestar: ");
    scanf(" %19s", busca);

    for (int i = 0; i < qtd; i++) {
        if (strcmp(livros[i].isbn, busca) == 0) {
            if (livros[i].emprestado) {
                printf("Livro ja esta emprestado.\n");
            } else {
                livros[i].emprestado = 1;
                printf("Livro emprestado com sucesso!\n");
            }
            return qtd;
        }
    }
    printf("Livro nao encontrado.\n");
    return qtd;
}

int devolverLivro(Livro livros[], int qtd) {
    char busca[20];
    printf("Digite o ISBN do livro a devolver: ");
    scanf(" %19s", busca);

    for (int i = 0; i < qtd; i++) {
        if (strcmp(livros[i].isbn, busca) == 0) {
            if (!livros[i].emprestado) {
                printf("Livro ja esta disponivel.\n");
            } else {
                livros[i].emprestado = 0;
                printf("Livro devolvido com sucesso!\n");
            }
            return qtd;
        }
    }
    printf("Livro nao encontrado.\n");
    return qtd;
}
