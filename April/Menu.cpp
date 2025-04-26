/* 
1 - Hamburguer ................ R$ 15,00
2 - Pizza ..................... R$ 30,00
3 - Salada .................... R$ 12,00
4 - Suco Natural .............. R$ 8,00
5 - Refrigerante .............. R$ 6,00
--------------------------------
*/
#include <iostream>
using namespace std;

int main() {
    int opcao;
    cout << "#================ Menu ================#\n"
            "| 1 - Hamburguer ............... R$ 15,00 |\n"
            "| 2 - Pizza .................... R$ 30,00 |\n"
            "| 3 - Salada ................... R$ 12,00 |\n"
            "| 4 - Suco Natural ............. R$ 8,00  |\n"
            "| 5 - Refrigerante ............. R$ 6,00  |\n"
            "#=======================================#\n"
            "Digite o número do seu pedido: ";
    cin >> opcao;

    switch (opcao) {
        case 1: cout << "Você pediu: Hamburguer - R$ 15,00\n"; break;
        case 2: cout << "Você pediu: Pizza - R$ 30,00\n"; break;
        case 3: cout << "Você pediu: Salada - R$ 12,00\n"; break;
        case 4: cout << "Você pediu: Suco Natural - R$ 8,00\n"; break;
        case 5: cout << "Você pediu: Refrigerante - R$ 6,00\n"; break;
        default: cout << "Opção inválida. Tente novamente.\n";
    }

    return 0;
}
