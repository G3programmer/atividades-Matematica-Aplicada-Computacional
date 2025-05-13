#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a,b,c;
    cin >>a>>b>>c;
    double triangulo =(a*c)/2.0;
    double circulo =3.14159*c*c;
    double trapezio =((a+b)*c)/2.0;
    double quadrado =b*b;
    double retangulo =a*b;

    cout << fixed << setprecision(3);
    cout << "TRIANGULO: "<<triangulo<<endl;
    cout << "CIRCULO: "<<circulo<<endl;
    cout << "TRAPEZIO: "<<trapezio<<endl;
    cout << "QUADRADO: "<<quadrado<<endl;
    cout << "RETANGULO: "<<retangulo<<endl;

    return 0;
}
