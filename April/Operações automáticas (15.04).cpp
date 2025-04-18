#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    // Recebe dois números inteiros do usuário
    cout << "Digite o primeiro número inteiro: ";
    cin >> num1;

    cout << "Digite o segundo número inteiro: ";
    cin >> num2;

    // Realiza e exibe as operações
    cout << "\nResultados:\n";
    cout << "Soma: " << num1 + num2 << endl;
    cout << "Subtracao: " << num1 - num2 << endl;
    cout << "Multiplicacao: " << num1 * num2 << endl;

    // Verifica divisão por zero
    if (num2 != 0) {
        cout << "Divisao: " << static_cast<float>(num1) / num2 << endl;
        cout << "Resto da divisao: " << num1 % num2 << endl;
    } else {
        cout << "Divisao: Indefinida (divisao por zero)" << endl;
        cout << "Resto da divisao: Indefinido (divisao por zero)" << endl;
    }

    return 0;
}
