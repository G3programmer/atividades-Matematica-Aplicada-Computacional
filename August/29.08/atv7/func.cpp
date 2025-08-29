#include <iostream>
#include <cmath>
#include "header.h"
using namespace std;

Matriz criarMatriz(int linhas, int colunas) {
    Matriz m;
    if (linhas > MAX_SIZE || colunas > MAX_SIZE) {
        cout << "Erro: Tamanho excede o limite máximo de " << MAX_SIZE << "x" << MAX_SIZE << endl;
        m.linhas = 0;
        m.colunas = 0;
        m.dados = nullptr;
        return m;
    }
    
    m.linhas = linhas;
    m.colunas = colunas;
    m.dados = new double*[linhas];
    for (int i = 0; i < linhas; i++) {
        m.dados[i] = new double[colunas]{0};
    }
    return m;
}

void liberarMatriz(Matriz* m) {
    if (m->dados != nullptr) {
        for (int i = 0; i < m->linhas; i++) {
            delete[] m->dados[i];
        }
        delete[] m->dados;
    }
    m->linhas = 0;
    m->colunas = 0;
    m->dados = nullptr;
}

void imprimirMatriz(const Matriz& m) {
    if (m.dados == nullptr) {
        cout << "Matriz vazia!" << endl;
        return;
    }
    
    for (int i = 0; i < m.linhas; i++) {
        for (int j = 0; j < m.colunas; j++) {
            cout << m.dados[i][j] << "\t";
        }
        cout << endl;
    }
}

bool mesmoTamanho(const Matriz& a, const Matriz& b) {
    return (a.linhas == b.linhas && a.colunas == b.colunas);
}

bool ehQuadrada(const Matriz& m) {
    return (m.linhas == m.colunas);
}

Matriz somarMatrizes(const Matriz& a, const Matriz& b) {
    if (!mesmoTamanho(a, b)) {
        cout << "Erro: Matrizes de tamanhos diferentes!" << endl;
        return criarMatriz(0, 0);
    }
    
    Matriz resultado = criarMatriz(a.linhas, a.colunas);
    for (int i = 0; i < a.linhas; i++) {
        for (int j = 0; j < a.colunas; j++) {
            resultado.dados[i][j] = a.dados[i][j] + b.dados[i][j];
        }
    }
    return resultado;
}

Matriz multiplicarMatrizes(const Matriz& a, const Matriz& b) {
    if (a.colunas != b.linhas) {
        cout << "Erro: Dimensões incompatíveis para multiplicação!" << endl;
        return criarMatriz(0, 0);
    }
    
    Matriz resultado = criarMatriz(a.linhas, b.colunas);
    for (int i = 0; i < a.linhas; i++) {
        for (int j = 0; j < b.colunas; j++) {
            for (int k = 0; k < a.colunas; k++) {
                resultado.dados[i][j] += a.dados[i][k] * b.dados[k][j];
            }
        }
    }
    return resultado;
}

double determinanteMatriz(const Matriz& m) {
    if (!ehQuadrada(m)) {
        cout << "Erro: Matriz não é quadrada!" << endl;
        return 0;
    }
    
    if (m.linhas == 1) return m.dados[0][0];
    if (m.linhas == 2) {
        return m.dados[0][0] * m.dados[1][1] - m.dados[0][1] * m.dados[1][0];
    }
    
    double det = 0;
    for (int j = 0; j < m.colunas; j++) {
        Matriz sub = criarMatriz(m.linhas-1, m.colunas-1);
        
        for (int i = 1; i < m.linhas; i++) {
            int colSub = 0;
            for (int k = 0; k < m.colunas; k++) {
                if (k != j) {
                    sub.dados[i-1][colSub++] = m.dados[i][k];
                }
            }
        }
        
        double sinal = (j % 2 == 0) ? 1 : -1;
        det += sinal * m.dados[0][j] * determinanteMatriz(sub);
        liberarMatriz(&sub);
    }
    return det;
}

Matriz inversaMatriz(const Matriz& m) {
    if (!ehQuadrada(m)) {
        cout << "Erro: Matriz não é quadrada!" << endl;
        return criarMatriz(0, 0);
    }
    
    double det = determinanteMatriz(m);
    if (fabs(det) < 1e-10) {
        cout << "Erro: Matriz singular (determinante zero)!" << endl;
        return criarMatriz(0, 0);
    }
    
    Matriz inversa = criarMatriz(m.linhas, m.colunas);
    
    if (m.linhas == 1) {
        inversa.dados[0][0] = 1.0 / m.dados[0][0];
    }
    else if (m.linhas == 2) {
        inversa.dados[0][0] = m.dados[1][1] / det;
        inversa.dados[0][1] = -m.dados[0][1] / det;
        inversa.dados[1][0] = -m.dados[1][0] / det;
        inversa.dados[1][1] = m.dados[0][0] / det;
    }
    else {
        cout << "Inversa para matrizes >2x2 não implementada." << endl;
    }
    
    return inversa;
}