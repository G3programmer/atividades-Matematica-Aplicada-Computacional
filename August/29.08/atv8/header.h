#ifndef HEADER_H
#define HEADER_H

struct Ponto {
    double x;
    double y;
};

// BÁSICO
double distancia(Ponto a, Ponto b);
double produtoVetorial(Ponto a, Ponto b, Ponto c);

// POLIGONO
double calcularPerimetro(Ponto pontos[], int n);
double calcularArea(Ponto pontos[], int n);
bool ehConvexo(Ponto pontos[], int n);

#endif