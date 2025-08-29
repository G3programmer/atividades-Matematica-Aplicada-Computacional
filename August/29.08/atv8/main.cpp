/*
8. Receber um conjunto de pontos no plano e determinar:
• Perímetro
• Área (usando fórmula do polígono de Gauss)
• Se o polígono é convexo
*/
#include <iostream>
#include <iomanip>
#include "header.h"
using namespace std;

int main() {
    int n;
    cout << "=== ANALISE DE POLIGONO ===" << endl;
    cout << "Quantos pontos tem o poligono? ";
    cin >> n;
    
    if (n < 3) {
        cout << "Um poligono precisa de pelo menos 3 pontos!" << endl;
        return 1;
    }
    
    Ponto pontos[n];
    
    cout << "\nDigite as coordenadas dos pontos (x y):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Ponto " << i + 1 << ": ";
        cin >> pontos[i].x >> pontos[i].y;
    }
    
    // Exibir pontos
    cout << "\nPontos do poligono:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << ": (" << pontos[i].x << ", " << pontos[i].y << ")" << endl;
    }
    
    // Cálculos
    double perimetro = calcularPerimetro(pontos, n);
    double area = calcularArea(pontos, n);
    bool convexo = ehConvexo(pontos, n);
    
    // Resultados
    cout << fixed << setprecision(2);
    cout << "\n=== RESULTADOS ===" << endl;
    cout << "Perimetro: " << perimetro << endl;
    cout << "Area: " << area << endl;
    cout << "O poligono é " << (convexo ? "CONVEXO" : "NAO CONVEXO") << endl;
    
    
    system("pause");
    return 0;
}