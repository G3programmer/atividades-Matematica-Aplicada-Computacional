#include <iostream>
#include <iomanip>  //USEI PARA DEFINIR A APRESENTAÇÃO DOS VALORES, CONSIGO ESCOLHER A QUANTIA DEPOIS DA VIRGULA
#include <cstdlib> //PEGUEI PARA LIMPAR A TELA DEPOIS DE CONCLUIR ALGUMA FUNÇÃO AQUI 

using namespace std;

int main() {
    string nome;
    double saldo = 1000.0;
    int opcao;
    double valor;

    // USUÁRIO OBRIGADO A ESCREVER SEU NOME
    cout << "=================================\n";
    cout << "   BEM-VINDO AO BANCO VIRTUAL\n";
    cout << "=================================\n";
    cout << "Digite seu nome: ";
    getline(cin, nome);  // EU DEIXO ESCREVER NOMES COM ESPAÇO

    do {
        system("clear"); // LIMPA A TELA E DEIXA BONITO

        cout << "==============================\n";
        cout << " Olá, " << nome << "!\n";
        cout << "    SISTEMA BANCÁRIO\n";
        cout << "==============================\n";
        cout << "[1] Ver Saldo\n";
        cout << "[2] Depositar\n";
        cout << "[3] Sacar\n";
        cout << "[4] Sair\n";
        cout << "------------------------------\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << fixed << setprecision(2);
                cout << "\nSeu saldo atual é: R$ " << saldo << "\n";
                break;
            case 2:
                cout << "\nDigite o valor para depositar: R$ ";
                cin >> valor;
                if (valor > 0) {
                    saldo += valor;
                    cout << "Depósito realizado com sucesso!\n";
                } else {
                    cout << "Valor inválido!\n";
                }
                break;
            case 3:
                cout << "\nDigite o valor para sacar: R$ ";
                cin >> valor;
                if (valor > 0 && valor <= saldo) {
                    saldo -= valor;
                    cout << "Saque realizado com sucesso!\n";
                } else {
                    cout << "Saque inválido. Verifique o saldo.\n";
                }
                break;
            case 4:
                cout << "\nSaindo do sistema...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }

        if (opcao != 4) {
            cout << "\nPressione ENTER para continuar...";
            cin.ignore();
            cin.get();
        }

    } while (opcao != 4);

    // DESPEDIDA DO SISTEMA
    cout << "\nObrigado por utilizar nosso sistema, " << nome << "!\n";
    cout << "Volte sempre.\n";

    return 0;
}
