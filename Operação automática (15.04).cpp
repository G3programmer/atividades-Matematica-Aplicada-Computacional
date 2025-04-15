#include <iostream>
using namespace std;
int main() {
    int caracol, lesma, soma, sub, mult, rest;
    float die;
    cout<<"Digite o primeiro número:\n"<<endl;
    cin >> caracol;
    cout<<"Agora o segundo número"<<endl;
    cin >> lesma;
     soma = caracol+lesma;
    cout<<"Os números somados são: "<< soma <<"\n"<<endl;
     sub = caracol-lesma;
    cout<<"Os números subtraidos são: "<< sub <<"\n"<<endl;
     mult = caracol*lesma;
    cout<<"Os números multiplicados são: "<< mult <<"\n"<<endl;
     die = (float)caracol / lesma;
    cout<<"Os números divididos são: "<< die <<"\n"<<endl;
     rest = caracol % lesma;
    cout<<"Os números divididos são: "<< rest <<"\n"<<endl;
    return 0;
}
