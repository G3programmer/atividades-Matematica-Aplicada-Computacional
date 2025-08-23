#ifndef header_h
#define header_h

    const int MAX_SENSORES = 10; // COLOQUEI UM LIMITE DE 10

// TEMPERATURA MÉDIA (VARIÁVEL GLOBAL)
extern double temperaturaMediaGlobal;

// FUNÇÕES
void lerDadosTemperatura(double matriz[][MAX_SENSORES], int dias, int sensores);
void calcularMediasSensores(double matriz[][MAX_SENSORES], int dias, int sensores, double medias[]);
void atualizarTemperaturaMediaGlobal(double matriz[][MAX_SENSORES], int dias, int sensores);
void exibirResultados(double matriz[][MAX_SENSORES], double medias[], int dias, int sensores);

#endif