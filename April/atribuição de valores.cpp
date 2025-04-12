#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Digite um valor de 0 a 10" << endl;
    cin >> a;

    switch(a) {
        case 9:
        case 10:
            cout << "Você recebeu um A" << endl;
            break;

        case 7:
        case 8:
            cout << "Você recebeu um B" << endl;
            break;

        case 5:
        case 6:
            cout << "Você recebeu um C" << endl;
            break;

        case 3:
        case 4:
            cout << "Você recebeu um D" << endl;
            break;

        case 0:
        case 1:
        case 2:
            cout << "Você recebeu um E" << endl;
            break;

        default:
            cout << "Valor inválido!" << endl;
    }

    return 0;
}
