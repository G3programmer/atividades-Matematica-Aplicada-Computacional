#include<iostream>
using namespace std;

int main() {
    int idade;
    cout << "Digite a sua idade" << endl;
    cin >> idade;

    // Apenas removi a linha com 'fah' pois ela não está relacionada
    // à lógica atual. Caso queira trabalhar com temperatura, isso deve ser implementado.

    if (idade <= 12) {
        cout << "Você é criança" << endl;
    }
    else if (idade >= 13 && idade <= 17) {
        cout << "Você é adolescente" << endl;
    }
    else {
        cout << "Você é adulto" << endl;
    }

    return 0;
}
