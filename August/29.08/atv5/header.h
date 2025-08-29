#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
using namespace std;

struct Funcionario {
    string nome;
    int codigo;
};

const int NUM_FUNCIONARIOS = 3;
extern Funcionario autorizados[NUM_FUNCIONARIOS];

bool verificarAcesso(string nome, int codigo);

#endif