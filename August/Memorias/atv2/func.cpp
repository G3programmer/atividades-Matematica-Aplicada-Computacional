#include "func.h"

int ehPrimo(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int lerNumeros(int *vet, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Digite o numero " << i + 1 << ": ";
        cin >> vet[i];
    }
    return 1; // sucesso
}

int contarPrimos(int *vet, int n) {
    int qtd = 0;
    for (int i = 0; i < n; i++) {
        if (ehPrimo(vet[i])) qtd++;
    }
    return qtd;
}

int preencherPrimos(int *origem, int n, int *destino) {
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (ehPrimo(origem[i])) {
            destino[idx++] = origem[i];
        }
    }
    return idx; // retorna quantos primos foram inseridos
}
