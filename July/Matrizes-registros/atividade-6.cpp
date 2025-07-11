#include <iostream>
#include <iomanip>
using namespace std;

struct Funcionario {
    string nome;
    float salarioBruto;
    float descontos[3]; 
    float descontoTotal;
    float salarioLiquido;
};

int main() {
    const int TAM = 4;
    const int NUM_DESCONTOS = 3;

    Funcionario funcionarios[TAM];
    int i, j;
    float maiorSalarioLiquido = 0;
    int indiceMaior = 0;

    for (i = 0; i < TAM; ++i) {
        cout << "\nFuncionário " << i + 1 << endl;
        cout << "Nome: ";
        cin >> funcionarios[i].nome;

        cout << "Salário Bruto: R$ ";
        cin >> funcionarios[i].salarioBruto;

        funcionarios[i].descontoTotal = 0;

        for (j = 0; j < NUM_DESCONTOS; ++j) {
            cout << "Desconto " << j + 1 << ": R$ ";
            cin >> funcionarios[i].descontos[j];
            funcionarios[i].descontoTotal += funcionarios[i].descontos[j];
        }

        funcionarios[i].salarioLiquido = funcionarios[i].salarioBruto - funcionarios[i].descontoTotal;

        if (funcionarios[i].salarioLiquido > maiorSalarioLiquido) {
            maiorSalarioLiquido = funcionarios[i].salarioLiquido;
            indiceMaior = i;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\n--- Tabela de Funcionários ---\n";
    cout << left << setw(12) << "Nome" 
         << setw(15) << "Bruto"
         << setw(15) << "Desconto Total"
         << setw(15) << "Líquido" << endl;

    for (i = 0; i < TAM; ++i) {
        cout << left << setw(12) << funcionarios[i].nome
             << "R$ " << setw(12) << funcionarios[i].salarioBruto
             << "R$ " << setw(12) << funcionarios[i].descontoTotal
             << "R$ " << funcionarios[i].salarioLiquido << endl;
    }
    cout << "\nFuncionário com maior salário líquido: " 
         << funcionarios[indiceMaior].nome
         << " (R$ " << funcionarios[indiceMaior].salarioLiquido << ")" << endl;

    return 0;
}
