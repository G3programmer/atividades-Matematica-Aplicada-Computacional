#include "header.h"

double calcularConta(double consumo) {
    double valor = 0.0;
    
    if (consumo <= FAIXA1_LIMITE) {
        valor = consumo * FAIXA1_PRECO;
    }
    else if (consumo <= FAIXA2_LIMITE) {
        valor = FAIXA1_LIMITE * FAIXA1_PRECO;
        valor += (consumo - FAIXA1_LIMITE) * FAIXA2_PRECO;
    }
    else if (consumo <= FAIXA3_LIMITE) {
        valor = FAIXA1_LIMITE * FAIXA1_PRECO;
        valor += (FAIXA2_LIMITE - FAIXA1_LIMITE) * FAIXA2_PRECO;
        valor += (consumo - FAIXA2_LIMITE) * FAIXA3_PRECO;
    }
    else {
        valor = FAIXA1_LIMITE * FAIXA1_PRECO;
        valor += (FAIXA2_LIMITE - FAIXA1_LIMITE) * FAIXA2_PRECO;
        valor += (FAIXA3_LIMITE - FAIXA2_LIMITE) * FAIXA3_PRECO;
        valor += (consumo - FAIXA3_LIMITE) * FAIXA4_PRECO;
    }
    
    return valor;
}