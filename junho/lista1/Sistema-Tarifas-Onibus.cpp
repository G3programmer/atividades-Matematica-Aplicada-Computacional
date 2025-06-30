#include <iostream>
#include <string>
using namespace std;

/*
Regras:
- Criança até 6 anos: Grátis, mas só pode com acompanhante
- Idoso acima de 65: R$2,00
- Estudante com carteirinha: R$2,50
- Adulto: R$4,00
*/

int main() {
    string nome;
    int idade, qtd;
    float total = 0.0;
    char estudante, resposta;

    cout << "=====================================" << endl;
    cout << "# Bem Vindo ao Sistema de Tarifário #" << endl;
    cout << "#        Do Gabriel Morozini        #" << endl;
    cout << "=====================================" << endl;

    // Dados do usuário principal
    cout << "Digite seu nome: ";
    cin >> nome;

    cout << "Digite sua idade: ";
    cin >> idade;

    // Caso: criança sozinha (proibido)
    if (idade <= 6) {
        cout << "\nCrianças até 6 anos não podem entrar sozinhas." << endl;
        cout << "Há um acompanhante maior de idade com você? (S/N): ";
        cin >> resposta;

        if (resposta == 'N' || resposta == 'n') {
            cout << "\n⚠️ A entrada não é permitida sem acompanhante maior de idade." << endl;
            return 0;
        }
        else if (resposta == 'S' || resposta == 's') {
            cout << "Criança acompanhada. Entrada gratuita para a criança." << endl;
        }
        else {
            cout << "Opção inválida. Encerrando." << endl;
            return 0;
        }
    }
    else if (idade >= 65) {
        total += 2.0;
        cout << "Idoso: R$2.00" << endl;
    }
    else {
        // Jovens e adultos entre 7 e 64 anos
        cout << "Você é estudante com carteirinha? (S/N): ";
        cin >> estudante;

        if (estudante == 'S' || estudante == 's') {
            total += 2.5;
            cout << "Estudante com carteirinha: R$2.50" << endl;
        }
        else if (estudante == 'N' || estudante == 'n') {
            total += 4.0;
            if (idade < 18) {
                cout << "Jovem sem carteirinha: R$4.00" << endl;
            } else {
                cout << "Adulto: R$4.00" << endl;
            }
        }
        else {
            cout << "Opção inválida. Considerando como sem carteirinha." << endl;
            total += 4.0;
        }
    }

    // Acompanhantes
    cout << "\nTem mais alguém com você? (S/N): ";
    cin >> resposta;

    if (resposta == 'S' || resposta == 's') {
        // Adultos
        cout << "Há adultos (entre 19 e 64 anos)? (S/N): ";
        cin >> resposta;
        if (resposta == 'S' || resposta == 's') {
            cout << "Quantos adultos? ";
            cin >> qtd;
            if (qtd > 0) {
                total += qtd * 4.0;
            }
        }

        // Estudantes
        cout << "Há estudantes com carteirinha? (S/N): ";
        cin >> resposta;
        if (resposta == 'S' || resposta == 's') {
            cout << "Quantos estudantes? ";
            cin >> qtd;
            if (qtd > 0) {
                total += qtd * 2.5;
            }
        }

        // Idosos
        cout << "Há idosos (65+)? (S/N): ";
        cin >> resposta;
        if (resposta == 'S' || resposta == 's') {
            cout << "Quantos idosos? ";
            cin >> qtd;
            if (qtd > 0) {
                total += qtd * 2.0;
            }
        }

        // Crianças
        cout << "Há crianças (até 6 anos)? (S/N): ";
        cin >> resposta;
        if (resposta == 'S' || resposta == 's') {
            cout << "Quantas crianças? ";
            cin >> qtd;
            if (qtd > 0) {
                cout << qtd << " criança(s) têm entrada gratuita." << endl;
            }
        }
    }

    // Resultado final
    cout << "\n=====================================" << endl;
    cout << "Total a pagar: R$" << total << endl;
    cout << "Obrigado pela visita, " << nome << "!" << endl;
    cout << "=====================================" << endl;

    return 0;
}
