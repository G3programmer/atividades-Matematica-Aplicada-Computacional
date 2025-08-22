#include <stdio.h>
#include <string.h>
#include "header.h"

#define MAX_PEDIDOS 100

Pedido pedidosLista[MAX_PEDIDOS];
int totalPedidos = 0;

// TRUE SE FOR REGISTRADO E FALSE SE NÃO FOR REGISTRADO
bool registrarPedido(Pedido p) {
    if (totalPedidos < MAX_PEDIDOS) {
        pedidosLista[totalPedidos++] = p;
        return true;
    }
    return false;
}

//APRESENTA TOTAL DE PEDIDOS REGISTRADOS
int listarPedidos() {
    printf("\nLista de pedidos:\n");
    for (int i = 0; i < totalPedidos; i++) {
        printf("%d. Nome: %s | Lanche: %s | Dia: %s | Qtd: %d\n",
            i+1,
            pedidosLista[i].nome,
            pedidosLista[i].lanche,
            pedidosLista[i].dia,
            pedidosLista[i].quantidade
        );
    }
    printf("Total de pedidos: %d\n", totalPedidos);
    return totalPedidos;
}