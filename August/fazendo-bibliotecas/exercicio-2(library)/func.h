#ifndef FUNC_H
#define FUNC_H

struct Livro {
    char titulo[50];
    char autor[50];
    char isbn[20];
    int emprestado; // 0 = DISPONÍVEIS, 1 = EMPRESTADOS
};

// FUNÇÕES GERAIS
int cadastrarLivro(Livro livros[], int qtd);
int listarLivros(Livro livros[], int qtd);
int emprestarLivro(Livro livros[], int qtd);
int devolverLivro(Livro livros[], int qtd);

#endif
