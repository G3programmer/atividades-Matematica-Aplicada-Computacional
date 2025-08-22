#include <iostream>
#include "header.h"
using namespace std;

int main() {
    int energia;
     int novaEnergia; 

    cout << "Digite a energia inicial do personagem: ";
    cin >> energia;
    cout << "\nEnergia inicial: " << energia << endl;

    // CURA POR VALOR
    
    novaEnergia = cura(energia);
    cout << "Depois de cura (por valor): " << novaEnergia << endl;
    cout << "Energia original permanece: " << energia << endl;
    
    // CURA REAL

    curaReal(energia);
    cout << "Depois de cura real (por referência): " << energia << endl;
    
    system("pause");
    return 0;
}