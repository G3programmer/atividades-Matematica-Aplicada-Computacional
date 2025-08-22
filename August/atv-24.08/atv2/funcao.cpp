#include "header.h"

// FUÇÃO QUE RECEBE ENERGIA POR VALOR
int cura(int energia) {
    energia += 10;
    return energia;  //RETORNA O VALOR, MAS ORIGINAL INTACTO
}

// POR REFERÊNCIA
void curaReal(int &energia) {
    energia += 10; // ALTERA O VALOR ORIGINAL
}
