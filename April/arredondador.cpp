#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double numero;

    
    cout << "Digite um número real: ";
    cin >> numero;

    
    int inteiro = static_cast<int>(numero); 
    double arredondadoCima = ceil(numero);   
    double arredondadoBaixo = floor(numero); 
    
    
    cout << "\nResultados:\n";
    cout << "Número original: " << numero << endl;
    cout << "Convertido para inteiro: " << inteiro << endl;
    cout << "Arredondado para cima: " << arredondadoCima << endl;
    cout << "Arredondado para baixo: " << arredondadoBaixo << endl;

    return 0;
}
