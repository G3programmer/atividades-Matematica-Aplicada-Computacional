#ifndef FUNC_H
#define FUNC_H

struct Aluno {
    char nome[50];
    float notas[3];
    float media; 
};

struct Aluno calcularMedia(struct Aluno a);

struct Aluno imprimirAluno(struct Aluno a);

#endif