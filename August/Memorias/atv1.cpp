#include <iostream>
using namespace std;
int main()
{
    int num; //MEMÓRIA STACK, MAS N PODE, VAMOS DEIXAR COMO HEAP
    int i;
    float soma = 0;
    float media;

    cout <<"Quantos números você gostaria de verificar?"<< endl;
    cin >> num;

    float *vet = new float[num]; // ALOCAÇÃO DINÂMICAAAA 

    //LEITURA DOS NÚMEROS
    for(i = 0; i < num; i++) {
        cout << "Digite o número " << i + 1 << ": ";
        cin >> vet[i];
        soma += vet[i]; // JÁ SOMAMOS
    }

    // CÁLCULO DA MÉDIA
    media = soma / num;
    cout << "Media: " << media << endl;

    //LIMPEZA DA MEMÓRIA
    delete[] vet;

    return 0;
}

/*
    tipo *p=new(tipo)  new é o malloc do c
    para o free do c, usa delete no c++
    new para quando n sabemos o tamanho do vetor
    int *vet = new int[10];
*/
