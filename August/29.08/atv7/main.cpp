/*Implementar operações de soma, multiplicação, inversa e determinante de matrizes
usando alocação dinâmica. Limitar tamanho a 100×100. Verificar se a operação é
válida antes de executar.*/

#include <iostream>
#include "header.h"
using namespace std;

int main() {
    cout << "=== OPERAÇÕES COM MATRIZES ===" << endl;
    
    // CRIAR MATRIZES 2x2
    Matriz A = criarMatriz(2, 2);
    A.dados[0][0] = 4; A.dados[0][1] = 7;
    A.dados[1][0] = 2; A.dados[1][1] = 6;
    
    Matriz B = criarMatriz(2, 2);
    B.dados[0][0] = 1; B.dados[0][1] = 3;
    B.dados[1][0] = 5; B.dados[1][1] = 2;
    
    cout << "\nMatriz A:" << endl;
    imprimirMatriz(A);
    
    cout << "\nMatriz B:" << endl;
    imprimirMatriz(B);
    
    // SOMA
    cout << "\nSoma A + B:" << endl;
    Matriz C = somarMatrizes(A, B);
    imprimirMatriz(C);
    
    // MULTIPLICAÇÃO
    cout << "\nMultiplicação A * B:" << endl;
    Matriz D = multiplicarMatrizes(A, B);
    imprimirMatriz(D);
    
    // Determinante
    cout << "\nDeterminante de A: " << determinanteMatriz(A) << endl;
    
    // INVERSA
    cout << "\nInversa de A:" << endl;
    Matriz invA = inversaMatriz(A);
    imprimirMatriz(invA);
    
    // TESTE 3x3
    cout << "\n=== MATRIZ 3x3 ===" << endl;
    Matriz E = criarMatriz(3, 3);
    E.dados[0][0] = 1; E.dados[0][1] = 2; E.dados[0][2] = 3;
    E.dados[1][0] = 0; E.dados[1][1] = 1; E.dados[1][2] = 4;
    E.dados[2][0] = 5; E.dados[2][1] = 6; E.dados[2][2] = 0;
    
    cout << "\nMatriz E:" << endl;
    imprimirMatriz(E);
    cout << "Determinante de E: " << determinanteMatriz(E) << endl;
    
    // LIMPA MEMÓRIA
    liberarMatriz(&A);
    liberarMatriz(&B);
    liberarMatriz(&C);
    liberarMatriz(&D);
    liberarMatriz(&invA);
    liberarMatriz(&E);
    
    system("pause");
    return 0;
}