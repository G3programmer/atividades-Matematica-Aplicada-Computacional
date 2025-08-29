#include "header.h"

Funcionario autorizados[NUM_FUNCIONARIOS] = {
    {"Joao Silva", 1234},
    {"Maria Santos", 5678},
    {"Pedro Alves", 9012}
};

bool verificarAcesso(string nome, int codigo) {
    for (int i = 0; i < NUM_FUNCIONARIOS; i++) {
        if (autorizados[i].nome == nome && autorizados[i].codigo == codigo) {
            return true;
        }
    }
    return false;
}