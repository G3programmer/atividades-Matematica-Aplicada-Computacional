
#include <iostream>
#include "func.h"
using namespace std;

int main() {
    int n;

    cout << "Quantos numeros inteiros deseja digitar? ";
    cin >> n;
 
    // ALOCAÇÃO
    int *vet = new int[n];

    lerNumeros(vet, n);

    // CONTA OS PRIMOS E CRIA VETOR DE PRIMOS
    int qtdPrimos = contarPrimos(vet, n);
    int *primos = new int[qtdPrimos];

    // PREENCHE O VETOR DE PRIMOS
    preencherPrimos(vet, n, primos);

    // EXIBE TODOS OS NÚMEROS
    cout << "\nTodos os numeros digitados: ";
    for (int i = 0; i < n; i++) {
        cout << vet[i] << " ";
    }

    // EXIBE OS NÚMEROS PRIMOS
    cout << "\nNumeros primos encontrados: ";
    for (int i = 0; i < qtdPrimos; i++) {
        cout << primos[i] << " ";
    }

    // EEXIBE A QUANTIDADE DE PRIMOS
    cout << "\nQuantidade de primos: " << qtdPrimos << endl;

    // LIMPEZA DA MEMÓRIA
    delete[] vet;
    delete[] primos;

    system("pause"); // MANTER NO MEU TERMINAL PQ DPS Q TERMINA ELE FECHA    
    return 0;

}
