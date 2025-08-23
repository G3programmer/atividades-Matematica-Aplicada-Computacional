#include <iostream>
#include "header.h"
using namespace std;

int main() {
    const int DIAS = 7;
    const int SENSORES = 3;

    // ARMAZENAMENTO EM MATRIZ
    double temperaturas[DIAS][MAX_SENSORES];
    
    // LEITURA DOS DADOS
    lerDadosTemperatura(temperaturas, DIAS, SENSORES);
   
    // CALCULA MÉDIAS DOS SENSORES
    double medias[SENSORES];
    calcularMediasSensores(temperaturas, DIAS, SENSORES, medias);
    
    // ATUALIZA TEMPERATURA MÉDIA GLOBAL
    atualizarTemperaturaMediaGlobal(temperaturas, DIAS, SENSORES);
     
    // EXIBE RESULTADOS
    exibirResultados(temperaturas, medias, DIAS, SENSORES);
    
    system("pause");
    return 0;
}