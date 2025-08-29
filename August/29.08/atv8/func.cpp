#include <iostream>
#include <cmath>
#include "header.h"
using namespace std;

// DISTANCIA DE DOIS PONTOS
double distancia(Ponto a, Ponto b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

// PRODUTO VETORIAL
double produtoVetorial(Ponto a, Ponto b, Ponto c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// PERIMETRO DO POLIGONO
double calcularPerimetro(Ponto pontos[], int n) {
    if (n < 3) return 0.0;
    
    double perimetro = 0.0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        perimetro += distancia(pontos[i], pontos[next]);
    }
    return perimetro;
}

//AREA DO POLIGONO (FÓRMULA DE GAUSS)
double calcularArea(Ponto pontos[], int n) {
    if (n < 3) return 0.0;
    
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        area += (pontos[i].x * pontos[next].y) - (pontos[next].x * pontos[i].y);
    }
    return fabs(area) / 2.0;
}

// VERIFICAÇÃO DE CONVEXIDADE
bool ehConvexo(Ponto pontos[], int n) {
    if (n < 3) return false;
    
    bool positivo = false;
    bool negativo = false;
    
    for (int i = 0; i < n; i++) {
        Ponto a = pontos[i];
        Ponto b = pontos[(i + 1) % n];
        Ponto c = pontos[(i + 2) % n];
        
        double cross = produtoVetorial(a, b, c);
        
        if (cross > 0) positivo = true;
        if (cross < 0) negativo = true;
        
        // NÃO SERÁ CONVEXO SE TIVER AMBOS OS SINAIS 
        if (positivo && negativo) return false;
    }
    
    return true;
}