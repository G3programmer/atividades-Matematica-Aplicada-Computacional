#include <iostream>
#include <iomanip>
using namespace std;

int main() {
        // ======= Declaração de variáveis no topo =======
    const int LIMITE = 50;
    float vendas[LIMITE];
    int pagamento[LIMITE];
    int qtdVendas;
    float total, maior, menor, valor;
    int vista, credito, debito, forma;
    int i;

    // ======= Inicialização =======
    total = 0;
    maior = -1e9;
    menor = 1e9;
    vista = 0;
    credito = 0;
    debito = 0;

    // Estilização inicial
    cout << " =================================================================================================================\n";
    cout << "         __   ___  __   ___       __          __   __   __      __   ___          ___       __        __  \n";
    cout << "        / _` |__  |__) |__  |\\ | /  ` |  /\\  |  \\ /  \\ |__)    |  \\ |__     \\  / |__  |\\ | |  \\  /\\  /__` \n";
    cout << "        \\__> |___ |  \\ |___ | \\| \\__, | /~~\\ |__/ \\__/ |  \\    |__/ |___     \\/  |___ | \\| |__/ /~~\\ .__/ \n";
    cout << "                                                                                                         \n";
    cout << " =================================================================================================================\n";
    cout << " ========* Por Gabriel Morozini *=================================================================================\n\n";
    cout << " #####################################################################\n";
    cout << " | Digite a quantidade de vendas que gostaria de registrar: (MAX:50) |\n";
    cout << " #####################################################################\n";
    while (!(cin >> qtdVendas) || qtdVendas < 1 || qtdVendas > LIMITE) {
        cout << "Entrada inválida! Digite um número entre 1 e 50: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    // ======= Entrada das vendas =======
    for (i = 0; i < qtdVendas;) {
        cout << "\nVenda #" << (i + 1) << ":\n";

        // Valor da venda
        cout << "Digite o valor da venda: R$ ";
        if (!(cin >> valor) || valor <= 0) {
            cout << "Valor inválido! Digite novamente.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        // Forma de pagamento
        cout << "Digite a forma de pagamento (1=À Vista, 2=Crédito, 3=Débito): ";
        if (!(cin >> forma) || (forma != 1 && forma != 2 && forma != 3)) {
            cout << "Código inválido! Digite novamente.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        // Armazenamento
        vendas[i] = valor;
        pagamento[i] = forma;

        total += valor;
        if (valor > maior) maior = valor;
        if (valor < menor) menor = valor;

        if (forma == 1) vista++;
        else if (forma == 2) credito++;
        else debito++;

        i++; // avança para a próxima venda
    }

    // ======= Relatório final =======
    cout << fixed << setprecision(2);  // <-- Formatação de saída para floats
    cout << "\n=================== RELATÓRIO FINAL ===================\n";
    cout << "Total de vendas registradas: " << qtdVendas << endl;
    cout << "Valor total vendido: R$ " << total << endl;
    cout << "Média das vendas: R$ " << (total / qtdVendas) << endl;
    cout << "Vendas à vista: " << vista << endl;
    cout << "Vendas no crédito: " << credito << endl;
    cout << "Vendas no débito: " << debito << endl;
    cout << "Maior venda: R$ " << maior << endl;
    cout << "Menor venda: R$ " << menor << endl;
    cout << "=======================================================\n";

    return 0;
}
