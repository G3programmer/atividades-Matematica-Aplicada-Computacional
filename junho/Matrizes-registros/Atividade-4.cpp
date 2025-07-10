#include <iostream>
using namespace std;

struct aluno {
    string nome;
    float nota1,nota2,media;
    };

int main() {
    const int TAM=3;
    aluno alunos[TAM];
    int i;
    
    for(i=0;i<TAM;++i) {    
        cout<<"Digite o nome do aluno: "<<endl;
        cin>>alunos[i].nome;
        
        cout<<"Digite a primeira nota do aluno: "<<endl;
        cin>>alunos[i].nota1;
        
        cout<<"Digite a segunda nota do aluno: "<<endl;
        cin>>alunos[i].nota2;
        
        alunos[i].media=(alunos[i].nota1+alunos[i].nota2)/2;
    }
    
    for(i=0;i<TAM;++i) {
        cout<<"Aluno: "<<alunos[i].nome<<"| Média: "<<alunos[i].media<<endl;
    }
    
    
    
    return 0;
}
