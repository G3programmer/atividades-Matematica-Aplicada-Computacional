/*
5. Um prédio comercial possui um sistema que libera a entrada somente para
funcionários autorizados. O programa deve receber o nome e o código de acesso de
uma pessoa e verificar se ela está na lista de autorizados. Use struct para
representar cada funcionário e seleções para verificar a entrada
*/

#include "header.h"

int main() {
    string nome;
    int codigo;

    cout << "Sistema de Acesso do Predio\n";
    cout << "Digite seu nome: ";
    getline(cin, nome);
    cout << "Digite seu codigo de acesso: ";
    cin >> codigo;

    if (verificarAcesso(nome, codigo)) {
        cout << "Acesso liberado. Bem-vindo(a), " << nome << "!\n";
    } else {
        cout << "Acesso negado. Credenciais invalidas.\n";
    }
    system("pause");
    return 0;
}