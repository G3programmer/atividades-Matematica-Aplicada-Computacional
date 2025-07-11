#include <iostream>
using namespace std;

int main() {
    int matriz[4][4];
    int row, col;
    int multiplosDe3 = 0;

    for (row = 0; row < 4; ++row) {
        for (col = 0; col < 4; ++col) {
            cout << "Digite o valor para [" << row << "][" << col << "]: ";
            cin >> matriz[row][col];

            if (matriz[row][col] % 3 == 0) {
                multiplosDe3++;
            }

            if (matriz[row][col] % 2 == 0) {
                matriz[row][col] = 0;
            }
        }
    }
    cout << "\nQuantidade de múltiplos de 3: " << multiplosDe3 << endl;
    cout << "\nMatriz resultante (pares substituídos por zero):\n" << endl;
    for (row = 0; row < 4; ++row) {
        for (col = 0; col < 4; ++col) {
            cout << matriz[row][col] << "\t";
        }
        cout << endl;
    }
    return 0;
}
