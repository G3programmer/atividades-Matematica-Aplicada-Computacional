#include <iostream>
using namespace std;

struct Produto {
    string nome;
    float preco;
};

int main() {
    const int TAM = 2;
    Produto produtos[TAM];

    for (int i = 0; i < TAM; ++i) {
        cout << "\nProduto " << i + 1 << endl;
        cout << "Nome: ";
        cin >> produtos[i].nome;

        cout << "Preço: R$ ";
        cin >> produtos[i].preco;
    }

    cout << "\n--- Informações dos Produtos ---\n";
    for (int i = 0; i < TAM; ++i) {
        cout << "Produto " << i + 1 << ": "
             << produtos[i].nome << " - R$ " << produtos[i].preco << endl;
    }
    return 0;
}
