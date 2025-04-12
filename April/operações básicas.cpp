#include<iostream>
using namespace std;

int main() {
 float a, b, z;
 char c;
 
    cout << "Digite o primeiro valor" << endl;
    cin >> a;
    cout << "Digite alguma operação (+, -, *, /)" << endl;
    cin >> c;
    cout << "Digite o primeiro valor" << endl;
    cin >> b;
    
/*    if(c == "+") {
        z=a+b;
        cout << "O resultado é igual a " << z << endl;
    }
    
    else if(c == "-") {
        z=a-b;
        cout << "O resultado é igual a " << z << endl;
    }
    
    else if(c == "*") {
        z=a*b;
        cout << "O resultado é igual a " << z << endl;
    }
    
    else if(c == "/") {
        z=a/b;
        cout << "O resultado é igual a " << z << endl;
    }
*/  switch(op) {
    
     case '+': z =a+b; break;
     case '-': z =a-b; break;
     case '*': z =a*b; break;
     case '/': z =a/b; break; 
      default:
      cout << "Operação inválida" << endl;
      return 1;
    }
  }
 cout << "O resultado é igual a " << z << endl;
    return 0;
}
