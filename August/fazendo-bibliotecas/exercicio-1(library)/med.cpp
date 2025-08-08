#include <stdio.h>
#include "func.h"

struct Aluno calcularMedia(struct Aluno a) {
    a.media = (a.notas[0] + a.notas[1] + a.notas[2]) / 3.0;
    return a;
}

struct Aluno imprimirAluno(struct Aluno a) {
    printf("Nome: %s\n", a.nome);
    printf("Notas: %.2f, %.2f, %.2f\n",/*Método para apresentar as 3 notas*/ a.notas[0], a.notas[1], a.notas[2]);
    printf("Media: %.2f\n", a.media);
    printf("-----------------------------\n");
    return a;
}