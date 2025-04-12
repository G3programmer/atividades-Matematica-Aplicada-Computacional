#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Digite o primeiro número" << endl;
    cin >> a;

    if (a % 2 == 0) {
        cout << "É par" << endl;
    } else {
        cout << "É ímpar" << endl;
    }

    return 0;
}
