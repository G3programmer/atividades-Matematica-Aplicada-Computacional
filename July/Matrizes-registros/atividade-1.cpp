#include <iostream>
using namespace std;

int main()
{
    int a[2][2];
    int row, col;

    for (row = 0; row < 2; ++row) {
        for (col = 0; col < 2; ++col) {
            cout << "Digite um valor para a matriz na linha [" << row << "] coluna [" << col << "]: ";
            cin >> a[row][col];
        }
    }

    cout << "\nMatriz inserida:\n" << endl;
    for (row = 0; row < 2; ++row) {
        for (col = 0; col < 2; ++col) {
            cout <<"Elemento ["<<row<<"]""["<<col<<"]: valor= "<<a[row][col]<<endl;
        }
    }

    return 0;
}
