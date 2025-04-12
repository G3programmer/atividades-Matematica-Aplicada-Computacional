#include <iostream>
using namespace std;

int main() {
    int mes;

    cout << "|---Verificação de Estações---|" << endl;

    // Laço para garantir que o mês inserido seja válido
    do {
        cout << "Digite o número do mês (1 a 12): ";
        cin >> mes;

        if (mes < 1 || mes > 12) {
            cout << "Esse mês não existe, tente novamente!" << endl;
        }
    } while (mes < 1 || mes > 12);
    switch (mes) {
        case 12: case 1: case 2:
            cout << "É Verão" << endl;
            break;
        case 3: case 4: case 5:
            cout << "É Outono" << endl;
            break;
        case 6: case 7: case 8:
            cout << "É Inverno" << endl;
            break;
        case 9: case 10: case 11:
            cout << "É Primavera" << endl;
            break;
    }

    return 0;
}
