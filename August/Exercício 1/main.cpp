#include <iostream>
#include <cstring>
#include "header.h"
using namespace std;

Pedido criarPedido() {
    Pedido p;
    cout << "Digite o nome do cliente: ";
    cin.getline(p.nome, 30);
    cout << "Digite o lanche: ";
    cin.getline(p.lanche, 30);
    cout << "Digite o dia (dd/mm/aaaa): ";
    cin.getline(p.dia, 12);
    cout << "Digite a quantidade: ";
    cin >> p.quantidade;
    cin.ignore(); // LIMPA O BUFFER DO TECLADO
    return p;
}

int main() {
    int qtd;
    cout << "Quantos pedidos deseja registrar? ";
    cin >> qtd;
    cin.ignore(); // LIMPA O BUFFER DO TECLADO

    for (int i = 0; i < qtd; i++) {
        cout << "\nPedido #" << (i+1) << endl;
        Pedido p = criarPedido();
        registrarPedido(p);
    }

    listarPedidos();

    system("pause");
    return 0;
}
