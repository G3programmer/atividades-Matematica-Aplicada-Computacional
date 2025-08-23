#include "header.h"

// FUNÇÃO QUE APLICA DESCONTO DE 10% EM TODOS OS VALORES
void aplicarDesconto(int m[][2], int linhas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < 2; j++) {
            m[i][j] = m[i][j] * 0.9; // REDUZ EM 10% (MULTIPLICA POR 0.9)
        }
    }
}

// FUNÇÃO QUE EXIBE A MATRIZ DE VENDAS
void exibirVendas(int m[][2], int linhas) {
    cout << "Dia\tProduto 1\tProduto 2" << endl;
    cout << "--------------------------------" << endl;
    for(int i = 0; i < linhas; i++) {
        cout << (i + 1) << "\t";
        for(int j = 0; j < 2; j++) {
            cout << m[i][j] << "\t\t";
        }
        cout << endl;
    }
}