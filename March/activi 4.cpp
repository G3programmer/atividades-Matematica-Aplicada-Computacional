#include<iostream>
using namespace std;
int main() {
    float cel, fah;
    cout <<"Digite o grau celsius"<< endl;
    cin >> cel;
    fah = (cel * 9.0/5.0)+ 32;
    cout <<"Temperatura em Fahrenheit: "<<fah<<"°F"<<endl;
    return 0;
}
