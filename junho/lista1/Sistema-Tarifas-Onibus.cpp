#include <iostream>
using namespace std;

/*
Crian¸ca at´e 6 anos: Gr´atis
• Idoso (acima de 65): R$ 2,00
• Estudante com carteirinha: R$ 2,50
• Adulto: R$ 4,00
Pe¸ca ao usu´ario a idade e se ´e estudante (S ou N).
Use if, else if e else
*/


/*
qtd de criança é= "d"
qtd de idoso é= "g"
qtd de estudantes é= "f"
*/

int main()
{
    int b,c,d,e,f;
    float a;
    char x,y,crianca,idoso,estudante;
    
    cout<<"====================================="<<endl;
    cout<<"# Bem Vindo ao Sistema de Tarifário #"<<endl;
    cout<<"#        Do Gabriel Morozini        #"<<endl;
    cout<<"====================================="<<endl;
    cout<<"|    Digite Seu nome e sua idade    |"<<endl;
    cout<<"====================================="<<endl;
    cout<<"Seu Nome: "<<endl;
    cin>>x;
    cout<<"Sua idade: "<<endl;
    cin>>b;
    cout<<"Você é estudante? (S/N)"<<endl;
    cin>>estudante;
    
    
    /*Parte de adulto*/
    if(b<=18) (estudante=='N'||estudante=='n') {
        cout<<"Tem mais alguém com você? (S/N)"<<endl;
        cin>>y;
        if(y=='S' || y=='s'){
            cout<<"Quantas pessoas?"<<endl;
            cin>>c;
            
            /*Verificar se há pessoas normais*/
            
            /*Verifica se há estudante*/
            
            /*Verificar as crianças*/
            cout<<"Há criança(s)? (S/N)"<<endl;
            cin>>crianca;
            
            /*FAZER UM IF, else if e else AQUI Ó*/
            if(crianca=='S' || crianca=='s') {
                cout<<"Quantas crianças? "<<endl;
                cin>>d;
            }
            else {
               /*Código quebra aqui*/                
            }
            
            cout<<"Há Idoso(s)? (S/N)"<<endl;
            cin>>idoso;
            
            /*FAZER UM IF, else if e else AQUI Ó*/            
            if(crianca=='S'|| crianca=='s') {
                cout<<"Quantos idosos? "<<endl;
                cin>>e;
                g=e*2.00;
            }
            
            
               /*Código quebra aqui*/ 
            }
        }
        else if (y=='N' || y=='n') {
            /*Termina o valor aqui*/
        }
        
        else {
            cout<<"Opção inválida, tente novamente!"<<endl;
        }
        
    }
    
    /*Parte de idoso*/
    if(b>=60) {
    cout<<"Tem mais alguém com você? (S/N)"<<endl;
        cin>>y;
        if(y=='S' || y=='s'){
            cout<<"Quantas pessoas?"<<endl;
            cin>>c;
            
            cout<<"Há criança(s)? (S/N)"<<endl;
            cin>>crianca;
            
            /*FAZER UM IF, else if e else AQUI Ó*/
            
            cout<<"Há Idoso(s)? (S/N)"<<endl;
            cin>>idoso;
            
            /*FAZER UM IF, else if e else AQUI Ó*/            
            
        }
        else if (y=='N' || y=='n') {
            /*Termina o valor aqui*/
        }
        
        else {
            cout<<"Opção inválida, tente novamente!"<<endl;
        }
        
    }
    
    /*Parte para saber se tem carteirinha para estudante*/
    if()
    
    
    
    
/* aqui vai ser derntro de um porque criança não anda sozinha poxa
    if(b<=6) {
    }
*/


/*  
total=g+    
d= é crianças de 6 anos ent tanto faz
g= é idoso
*/

    return 0;
}
