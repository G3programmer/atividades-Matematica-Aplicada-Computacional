#include <iostream>
#include <iomanip>
#include "header.h"
using namespace std;

// VARIÁVEL GLOBAL AQUIIII
double temperaturaMediaGlobal = 0.0;

// LEITURA DOS DADOS, POR ISSO USEI VOID
void lerDadosTemperatura(double matriz[][MAX_SENSORES], int dias, int sensores) {
    cout << "REGISTRO DE TEMPERATURAS - " << dias << " DIAS, " << sensores << " SENSORES" << endl;
    cout << "============================================" << endl;
    
    for (int i = 0; i < dias; i++) {
        cout << "\nDIA " << (i + 1) << ":" << endl;
        for (int j = 0; j < sensores; j++) {
            cout << "Temperatura do Sensor " << (j + 1) << " (em °C): ";
            cin >> matriz[i][j];
        }
    }
}

// CALCULADORA DE MÉDIAS, USEI VOID PARA ARMAZENAR NORMAL
void calcularMediasSensores(double matriz[][MAX_SENSORES], int dias, int sensores, double medias[]) {
    for (int j = 0; j < sensores; j++) {
        double soma = 0.0;
        for (int i = 0; i < dias; i++) {
            soma += matriz[i][j];
        }
        medias[j] = soma / dias;
    }
}

// FUNÇÃO APENAS PARA ATUALIZAR, ENTÃO USEI VOID
void atualizarTemperaturaMediaGlobal(double matriz[][MAX_SENSORES], int dias, int sensores) {
    double somaTotal = 0.0;
    
    for (int i = 0; i < dias; i++) {
        for (int j = 0; j < sensores; j++) {
            somaTotal += matriz[i][j];
        }
    }
    
    temperaturaMediaGlobal = somaTotal / (dias * sensores);
}

// FUNÇÃO DE EXIBIÇÃO
void exibirResultados(double matriz[][MAX_SENSORES], double medias[], int dias, int sensores) {
    cout << "\n=== RESULTADOS DO MONITORAMENTO ===" << endl;
    
    // Exibir tabela de temperaturas
    cout << "\nTabela de Temperaturas (°C):" << endl;
    cout << "Dia\t";
    for (int j = 0; j < sensores; j++) {
        cout << "Sensor " << (j + 1) << "\t";
    }
    cout << endl;
    
    cout << fixed << setprecision(1);
    for (int i = 0; i < dias; i++) {
        cout << (i + 1) << "\t";
        for (int j = 0; j < sensores; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    
    // EXIBIR MÉDIAS POR SENSOR
    cout << "\nMédias por Sensor:" << endl;
    for (int j = 0; j < sensores; j++) {
        cout << "Sensor " << (j + 1) << ": " << medias[j] << "°C" << endl;
    }
    
    // EXIBIR TEMPERATURA MÉDIA GLOBAL
    cout << "\nTemperatura Média Global: " << temperaturaMediaGlobal << "°C" << endl;
}