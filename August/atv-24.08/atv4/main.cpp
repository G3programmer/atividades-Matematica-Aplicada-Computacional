#include <iostream>
#include "header.h"
using namespace std;

int main() {
    const int DIAS = 7;
    const int PRODUTOS = 2;
    int vendas[DIAS][PRODUTOS];
    
    // LEITURA DAS VENDAS
    cout << "REGISTRO DE VENDAS DIÁRIAS (7 DIAS, 2 PRODUTOS)" << endl;
    cout << "==============================================" << endl;
    
    for(int i = 0; i < DIAS; i++) {
        cout << "\nDIA " << (i + 1) << ":" << endl;
        for(int j = 0; j < PRODUTOS; j++) {
            cout << "Vendas do Produto " << (j + 1) << ": ";
            cin >> vendas[i][j];
        }
    }
    
    // EXIBE A MATRIZ ORIGINAL
    cout << "\n=== VENDAS ORIGINAIS ===" << endl;
    exibirVendas(vendas, DIAS);
    
    // APLICA DESCONTO DE 10%
    aplicarDesconto(vendas, DIAS);
    
    // EXIBE A MATRIZ COM DESCONTO
    cout << "\n=== VENDAS COM DESCONTO DE 10% ===" << endl;
    exibirVendas(vendas, DIAS);
    
    // CÁLCULO DO TOTAL DE VENDAS
    int totalOriginal = 0;
    int totalComDesconto = 0;
    
    for(int i = 0; i < DIAS; i++) {
        for(int j = 0; j < PRODUTOS; j++) {
            totalOriginal += vendas[i][j] / 0.9; // Recupera o valor original
            totalComDesconto += vendas[i][j];
        }
    }
    
    cout << "\n=== RESUMO ===" << endl;
    cout << "Total de vendas originais: " << totalOriginal << endl;
    cout << "Total de vendas com desconto: " << totalComDesconto << endl;
    cout << "Valor do desconto aplicado: " << (totalOriginal - totalComDesconto) << endl;
    
    system("pause");
    return 0;
}