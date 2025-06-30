#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Digite um caractere: "<<endl;
    cin >> ch;

    // VER SE NÃO É CARACTER ESPECIAL OU LETRA E SIM UM DIGITO
    if (ch >= '0' && ch <= '9') {
        cout << "Dígito" << endl;
    }
    // VER SE É LETRA OU SE NÃO
    else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        // DEIXAR MINUSCULA PARA ANÁLISE
        char c = (ch >= 'A' && ch <= 'Z') ? ch + ('a' - 'A') : ch;

        // VAMOS VER SE É VOGAL
        switch(c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                cout << "Vogal" << endl;
                break;
            default:
                cout << "Consoante" << endl;
                break;
        }
    }
    else {
        cout << "Caractere especial" << endl;
    }

    return 0;
}
