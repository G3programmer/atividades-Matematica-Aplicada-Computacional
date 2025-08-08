#include <stdio.h>
#include <iostream>
#include <locale.h>
#include "func.h"

using namespace std;

int main()
{
    struct Aluno alunos[5]; /*REGISTRAR OS 5 ALUNOS*/

      for (int i = 0; i < 5; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf(" %49[^\n]", alunos[i].nome);
        printf("Digite as notas do aluno (3 notas): ");
        scanf("%f %f %f", &alunos[i].notas[0], &alunos[i].notas[1], &alunos[i].notas[2]);

        alunos[i] = calcularMedia(alunos[i]); // CALCULA A MÉDIA
      }
   
  printf("\n===== Dados dos Alunos =====\n");
    for (int i = 0; i < 5; i++) {
        alunos[i] = imprimirAluno(alunos[i]);
    }

    system("pause"); // MANTER NO MEU TERMINAL PQ DPS Q TERMINA ELE FECHA    
    return 0;

}