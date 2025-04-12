#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "=== MENU PRINCIPAL ===" << endl;
    cout << "1) Jogar" << endl;
    cout << "2) Carregar jogo" << endl;
    cout << "3) Opções de jogo" << endl;
    cout << "4) Sair" << endl;
    cout << "Escolha uma opção: ";
    cin >> a;

    switch(a) {
        case 1:
            cout << "\nEscolha a dificuldade:" << endl;
            cout << "1) Recém nascido" << endl;
            cout << "2) Comecei ontem" << endl;
            cout << "3) Sou um jogador" << endl;
            cout << "4) Trabalho com isso" << endl;
            cout << "5) Os inimigos me temem" << endl;
            cout << "Opção: ";
            cin >> b;

            switch(b) {
                case 1: cout << "Dificuldade: Recém nascido selecionada. \n Iniciando o jogo" << endl; break;
                case 2: cout << "Dificuldade: Comecei ontem selecionada. \n Iniciando o jogo" << endl; break;
                case 3: cout << "Dificuldade: Sou um jogador selecionada. \n Iniciando o jogo" << endl; break;
                case 4: cout << "Dificuldade: Trabalho com isso selecionada. \n Iniciando o jogo" << endl; break;
                case 5: cout << "Dificuldade: Os inimigos me temem selecionada. \n Iniciando o jogo" << endl; break;
                default: cout << "Dificuldade inválida!" << endl;
            }
            break;

        case 2:
            cout << "Carregando jogo..." << endl;
            break;

        case 3:
            cout << "Opções de jogo:" << endl;
            cout << "- Áudio" << endl;
            cout << "- Vídeo" << endl;
            cout << "- Controles" << endl;
            break;

        case 4:
            cout << "Saindo do jogo..." << endl;
            break;

        default:
            cout << "Opção inválida!" << endl;
    }

    return 0;
}
