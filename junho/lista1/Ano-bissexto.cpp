#include <iostream>
using namespace std;

/*
Faça um programa que leia um ano e diga se ele ´e bissexto. Um ano ´e bissexto se:
• E divis´ıvel por 4 e n˜ao por 100, ou ´
• E divis´ıvel por 400 ´
Use apenas estruturas condicionais if.
*/

int main()
{
    int a;
    cout<<"Digite o ano para verificar se é bissexto:"<<endl;
    cin>>a;
    if(a%4==0 && a%100!=0 || a%400==0){
        cout<<"O ano é bissexto"<<endl;
    }
    else{
        cout<<"Não é um ano bissexto"<<endl;
    }

    return 0;
}
