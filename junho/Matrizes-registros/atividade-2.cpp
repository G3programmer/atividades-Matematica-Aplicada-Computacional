#include <iostream>
using namespace std;
int main()
{
    int a[3][3];
    int row, col;
    int soma = 0;
    int i;
    for (row = 0; row < 3; ++row) {
        for (col = 0; col < 3; ++col) {
            cout << "Digite um valor para a matriz na linha [" << row << "] coluna [" << col << "]: ";
            cin >> a[row][col];
            soma += a[row][col];
        }
    }
    cout << "\nMatriz inserida:\n" << endl;
    for (row = 0; row < 3; ++row) {
        for (col = 0; col < 3; ++col) {
            cout << a[row][col] << "\t";
        }
        cout << endl;
    }
    cout << "\nSoma de todos os elementos: " << soma << endl;
    cout << "\nElementos da diagonal principal: ";
    for (i = 0; i < 3; ++i) {
        cout << a[i][i] << " ";
    }
    cout << "\nElementos da diagonal secundária: ";
    for (int i = 0; i < 3; ++i) {
        cout << a[i][2 - i] << " ";
    }
    cout << endl;
    return 0;
}
