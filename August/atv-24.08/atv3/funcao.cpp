#include "header.h"

// FUNÇÃO QUE DÁ BONUS NAS NOTAS
void bonusNotas(int notas[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        notas[i] *= 2; // MULTIPLICADOR DE NOTA (POR 2)
    }
}

//Usei void porque a função não precisa retornar nada e sim modificar o array diretamente.