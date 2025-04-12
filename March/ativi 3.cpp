#include <iostream>
using namespace std;

int main() {
    float nota,a,b,c;
    cout << "Digite a primeira nota" << endl;
    cin >> a;
    cout << "Digite a segunda nota" << endl;
    cin >> b;
    cout << "Digite a terceira nota" << endl;
    cin >> c;

     nota = a+b+c/3;

    if (nota <= 6) {
        cout << "Recuperação" << endl;
    } else {
        cout << "aprovado" << endl;
    }

    return 0;
}
