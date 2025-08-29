#ifndef HEADER_H
#define HEADER_H

const int MAX_SIZE = 100;

struct Matriz {
    int linhas;
    int colunas;
    double** dados;
};

// Funções SIMPLES
Matriz criarMatriz(int linhas, int colunas);
void liberarMatriz(Matriz* m);
void imprimirMatriz(const Matriz& m);

// OPERAÇÕES
Matriz somarMatrizes(const Matriz& a, const Matriz& b);
Matriz multiplicarMatrizes(const Matriz& a, const Matriz& b);
Matriz inversaMatriz(const Matriz& m);
double determinanteMatriz(const Matriz& m);

// VERIFICAÇÕES
bool ehQuadrada(const Matriz& m);
bool mesmoTamanho(const Matriz& a, const Matriz& b);

#endif