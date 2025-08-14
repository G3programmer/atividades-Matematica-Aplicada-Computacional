#ifndef FUNC_H
#define FUNC_H

#include <iostream>
using namespace std;

// Retorna 1 se for primo, 0 caso contrário
int ehPrimo(int num);

// Lê números e retorna 1 (sucesso)
int lerNumeros(int *vet, int n);

// Conta quantos primos existem e retorna o total
int contarPrimos(int *vet, int n);

// Preenche o vetor de primos e retorna a quantidade preenchida
int preencherPrimos(int *origem, int n, int *destino);

#endif
