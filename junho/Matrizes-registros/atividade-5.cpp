#include <iostream>
using namespace std;

struct Aluno {
    string nome;
    float nota1, nota2, media;
};

int main() {
    const int TAM = 3;
    Aluno alunos[TAM];
    float somaMedias = 0;
    int i;
    for (i = 0; i < TAM; ++i) {
        cout << "\nAluno " << i + 1 << endl;
        cout << "Nome: ";
        cin >> alunos[i].nome;

        cout << "Nota 1: ";
        cin >> alunos[i].nota1;

        cout << "Nota 2: ";
        cin >> alunos[i].nota2;

        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2) / 2;
        somaMedias += alunos[i].media;
    }

    cout << "\n--- Relação Geral ---\n";
    for (i = 0; i < TAM; ++i) {
        cout << "Aluno: " << alunos[i].nome
             << " | Nota 1: " << alunos[i].nota1
             << " | Nota 2: " << alunos[i].nota2
             << " | Média: " << alunos[i].media << endl;
    }

    float mediaGeral = somaMedias / TAM;
    cout << "\nMédia geral da turma: " << mediaGeral << endl;

    return 0;
}
