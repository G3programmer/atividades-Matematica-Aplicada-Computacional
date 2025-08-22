#ifndef FUNC_H
#define FUNC_H

struct Pedido {
    char nome[30];
    char lanche[30];
    char dia[12];
    int quantidade;
};

bool registrarPedido(Pedido p);
int listarPedidos();

#endif