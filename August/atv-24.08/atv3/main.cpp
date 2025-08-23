#include <iostream>
#include <string>
#include "header.h"
using namespace std;

int main() {
    int quantiaAlunos;
    
    // PERGUNTA A QUANTIDADE DE ALUNOS
    cout << "Quantos alunos deseja cadastrar? ";
    cin >> quantiaAlunos;
    
    // CRIA OS ARRAYS PARA NOMES E NOTAS
    string nomes[quantiaAlunos];
    int notas[quantiaAlunos][5]; // 5 notas por aluno
    
    // LEITURA DOS DADOS DOS ALUNOS
    for(int i = 0; i < quantiaAlunos; i++) {
        cout << "\n--- ALUNO " << (i + 1) << " ---" << endl;
        cout << "Nome do aluno: ";
        cin.ignore(); // Limpa o buffer do teclado
        getline(cin, nomes[i]);
        
        cout << "Digite as 5 notas de " << nomes[i] << ":" << endl;
        for(int j = 0; j < 5; j++) {
            cout << "Nota " << (j + 1) << ": ";
            cin >> notas[i][j];
        }
    }
    
    // EXIBE AS NOTAS ORIGINAIS
    cout << "\n=== NOTAS ORIGINAIS ===" << endl;
    for(int i = 0; i < quantiaAlunos; i++) {
        cout << "\n" << nomes[i] << ": ";
        for(int j = 0; j < 5; j++) {
            cout << notas[i][j] << " ";
        }
    }
    
    // APLICA BONUS NAS NOTAS DE TODOS OS ALUNOS
    for(int i = 0; i < quantiaAlunos; i++) {
        bonusNotas(notas[i], 5);
    }
    
    // EXIBE AS NOTAS ATUALIZADAS
    cout << "\n\n=== NOTAS COM BONUS (DOBRADAS) ===" << endl;
    for(int i = 0; i < quantiaAlunos; i++) {
        cout << "\n" << nomes[i] << ": ";
        for(int j = 0; j < 5; j++) {
            cout << notas[i][j] << " ";
        }
    }

    system("pause");
    return 0;
}