#include <iostream>
#include <iomanip> // PARA ORGANIZAR A APRESENTAÇÃO DO VETOR
using namespace std;

int main()
{
    int a, i;
    int colunas = 0;
    
    cout << "Escolha a quantidade de numeros que deseja informar:\n";
    cin >> a;

    int n[a]; // AQUI VAI SER ONDE O USUÁRIO ESCOLHE O TAMANHO

    for (i = 0; i < a; i++) {
        cout << "Digite o numero [" << i + 1 << "]: ";
        cin >> n[i];
    }

    cout << "\nVocê digitou (na ordem inversa):\n\n";


    for (i = a - 1; i >= 0; i--) {
        cout << setw(6) << n[i]; // DEIXEI PARA ORGANIZAR EM 5 COLUNAS SEM BUGAR UM NO OUTRO, POR ISSO USEI O IOMANIP NO INÍCIO
        colunas++;
        if (colunas == 5) {
            cout << endl;
            colunas = 0;
        }
    }

    // ELE SEMPRE VAI GERAR 5 ESPAÇOS POR LINHA, MAS SE GERAR +1 LINHA PARA AS SOBRAS, VAI SOBRAR ESPAÇO
    if (colunas != 0) {
        cout << endl;
    }

    return 0;
}
