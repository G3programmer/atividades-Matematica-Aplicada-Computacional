#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i;
    float n[7];     // Vetor com 7 temperaturas
    float soma = 0;
    int colunas = 0;

    cout << "Digite a temperatura dos 7 dias consecutivos:\n";

    for (i = 0; i < 7; i++) {
        cout << "Digite a temperatura [" << i + 1 << "]: ";
        cin >> n[i];
        soma += n[i];
    }

    cout << "\nTemperaturas digitadas:\n";
    for (i = 0; i < 7; i++) {
        cout << setw(8) << fixed << setprecision(1) << n[i];
        colunas++;
        if (colunas == 5) {
            cout << endl;
            colunas = 0;
        }
    }

    // Calcular média
    float media = soma / 7;
    cout << "\n\nMédia das temperaturas: " << fixed << setprecision(2) << media << "°C\n";

    // Mostrar dias com temperatura acima da média
    cout << "\nDias com temperatura acima da média:\n";
    bool encontrou = false;
    for (i = 0; i < 7; i++) {
        if (n[i] > media) {
            cout << "Dia " << i + 1 << " com " << n[i] << "°C\n";
            encontrou = true;
        }
    }
    if (!encontrou) {
        cout << "Nenhum dia teve temperatura acima da média.\n";
    }

    // Encontrar maior e menor temperatura
    float maior = n[0];
    float menor = n[0];

    for (i = 1; i < 7; i++) {
        if (n[i] > maior) {
            maior = n[i];
        }
        if (n[i] < menor) {
            menor = n[i];
        }
    }

    cout << "\nMaior temperatura registrada: " << maior << "°C\n";
    cout << "Menor temperatura registrada: " << menor << "°C\n";

    return 0;
}
