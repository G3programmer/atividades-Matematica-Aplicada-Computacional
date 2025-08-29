#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
using namespace std;

const int MAX_PROFESSORES = 10;
const int MAX_LABS = 5;
const int MAX_HORARIOS = 20; // 5 DIAS * 4 HORÁRIOS CADA

struct Professor {
    string nome;
    string area;
    int cargaHoraria;
};

struct Laboratorio {
    string nome;
    int capacidade;
    string equipamentos;
};

struct Turma {
    string disciplina;
    int numAlunos;
    Professor professor;
};

struct HorarioAula {
    string dia;
    string hora;
    Turma turma;
    Laboratorio lab;
    Professor professor;
};

// CADASTRO
void cadastrarProfessores(Professor professores[]);
void cadastrarLaboratorios(Laboratorio laboratorios[]);
Turma* cadastrarTurmas(Professor professores[], int &numTurmas);

// AGENDAMENTO
bool agendarAula(HorarioAula agenda[], int &numAgendamentos, Turma turmas[], 
                 Laboratorio labs[], Professor profs[], int numTurmas);

// VALIDAÇÃO
bool professorDisponivel(HorarioAula agenda[], int numAgendamentos, 
                         Professor prof, string dia, string hora);
bool laboratorioDisponivel(HorarioAula agenda[], int numAgendamentos, 
                           Laboratorio lab, string dia, string hora);
bool capacidadeSuficiente(Laboratorio lab, Turma turma);

// FUNÇÃO RELATÓRIO
void relatorioProfessor(HorarioAula agenda[], int numAgendamentos, 
                       Professor professores[]);
void relatorioLaboratorio(HorarioAula agenda[], int numAgendamentos, 
                         Laboratorio laboratorios[]);
void horariosLivresOcupados(HorarioAula agenda[], int numAgendamentos);

#endif