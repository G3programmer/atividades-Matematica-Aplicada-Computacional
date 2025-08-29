/*
Crie um programa que leia o consumo mensal de energia elétrica de uma residência
e calcule o valor da conta com base nas faixas de consumo. Use estruturas de
seleção e modularize o código em arquivos separados. 
*/

#include <iostream>
#include <iomanip>
#include "header.h"
using namespace std;

int main() {
    double consumo;
    
    cout << "=== CALCULADORA DE CONTA DE ENERGIA ===\n\n";
    cout << "Digite o consumo mensal (kWh): ";
    cin >> consumo;
    
    if (consumo < 0) {
        cout << "Erro: Consumo não pode ser negativo!\n";
        return 1;
    }
    
    double valorConta = calcularConta(consumo);
    
    cout << fixed << setprecision(2);
    cout << "\n=== RESUMO DA CONTA ===\n";
    cout << "Consumo: " << consumo << " kWh\n";
    cout << "Valor da conta: R$ " << valorConta << endl;
    
    system("pause");
    return 0;
}