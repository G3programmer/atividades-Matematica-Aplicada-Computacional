#include<iostream>
using namespace std;
/*
E aqui nos encontramos novamente como da última vez, codando ;)
Esse é para a transformação de número para nome
*/

int main() {
    int x;
    cout<<"Digite um número para ser escrito:"<<endl;
    cin>>x;
    
    switch(x) {
        case 0:
        cout<<"Zero"<<endl;
        break;
        
        case 1:
        cout<<"Um"<<endl;
        break;
        
        case 2:
        cout<<"Dois"<<endl;
        break;
        
        case 3:
        cout<<"Três"<<endl;
        break;
        
        case 4:
        cout<<"Quatro"<<endl;
        break;
        
        case 5:
        cout<<"Cinco"<<endl;
        break;
        
        case 6:
        cout<<"Seis"<<endl;
        break;
        
        case 7:
        cout<<"Sete"<<endl;
        break;
        
        case 8:
        cout<<"Oito"<<endl;
        break;
        
        case 9:
        cout<<"Nove"<<endl;
        break;
        
        case 10:
        cout<<"Dez"<<endl;
        break;
        
        
        default:
        cout<<"Nota inválida"<<endl;
    }

    return 0;
}
