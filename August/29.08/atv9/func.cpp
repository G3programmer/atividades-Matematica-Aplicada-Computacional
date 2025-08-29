#include <iostream>
#include <string>
#include "header.h"
using namespace std;

void cadastrarProfessores(Professor professores[]) {
    string nomes[] = {"Ana Silva", "Carlos Santos", "Maria Oliveira", "João Pereira", 
                     "Paula Costa", "Marcos Souza", "Julia Lima", "Pedro Alves", 
                     "Luciana Ribeiro", "Fernando Martins"};
    string areas[] = {"Programação", "Redes", "Banco de Dados", "Segurança", "IA", 
                     "Web", "Mobile", "Cloud", "DevOps", "UX/UI"};
    
    for(int i = 0; i < MAX_PROFESSORES; i++) {
        professores[i].nome = nomes[i];
        professores[i].area = areas[i];
        professores[i].cargaHoraria = 20 + (i % 5) * 4;
    }
}

void cadastrarLaboratorios(Laboratorio laboratorios[]) {
    string nomes[] = {"Lab 1 - Programação", "Lab 2 - Redes", "Lab 3 - Hardware", 
                     "Lab 4 - Multimídia", "Lab 5 - Pesquisa"};
    int capacidades[] = {30, 25, 20, 15, 10};
    string equipamentos[] = {"Computadores i5, Projetor", "Roteadores, Switches", 
                            "Arduinos, Multímetros", "Câmeras, Tablets", 
                            "VR, Servidores"};
    
    for(int i = 0; i < MAX_LABS; i++) {
        laboratorios[i].nome = nomes[i];
        laboratorios[i].capacidade = capacidades[i];
        laboratorios[i].equipamentos = equipamentos[i];
    }
}

Turma* cadastrarTurmas(Professor professores[], int &numTurmas) {
    cout << "Quantas turmas deseja cadastrar? ";
    cin >> numTurmas;
    cin.ignore();
    
    Turma* turmas = new Turma[numTurmas];
    
    for(int i = 0; i < numTurmas; i++) {
        cout << "\nTurma " << i+1 << ":\n";
        cout << "Disciplina: ";
        getline(cin, turmas[i].disciplina);
        cout << "Número de alunos: ";
        cin >> turmas[i].numAlunos;
        cin.ignore();
        
        cout << "\nProfessores disponíveis:\n";
        for(int j = 0; j < MAX_PROFESSORES; j++) {
            cout << j+1 << ". " << professores[j].nome << " - " << professores[j].area << endl;
        }
        
        int escolha;
        cout << "Escolha o professor (1-10): ";
        cin >> escolha;
        cin.ignore();
        
        if(escolha >= 1 && escolha <= MAX_PROFESSORES) {
            turmas[i].professor = professores[escolha-1];
        } else {
            cout << "Escolha inválida! Atribuindo professor padrão.\n";
            turmas[i].professor = professores[0];
        }
    }
    
    return turmas;
}

bool professorDisponivel(HorarioAula agenda[], int numAgendamentos, 
                         Professor prof, string dia, string hora) {
    for(int i = 0; i < numAgendamentos; i++) {
        if(agenda[i].professor.nome == prof.nome && 
           agenda[i].dia == dia && 
           agenda[i].hora == hora) {
            return false;
        }
    }
    return true;
}

bool laboratorioDisponivel(HorarioAula agenda[], int numAgendamentos, 
                           Laboratorio lab, string dia, string hora) {
    for(int i = 0; i < numAgendamentos; i++) {
        if(agenda[i].lab.nome == lab.nome && 
           agenda[i].dia == dia && 
           agenda[i].hora == hora) {
            return false;
        }
    }
    return true;
}

bool capacidadeSuficiente(Laboratorio lab, Turma turma) {
    return lab.capacidade >= turma.numAlunos;
}

bool agendarAula(HorarioAula agenda[], int &numAgendamentos, Turma turmas[], 
                 Laboratorio labs[], Professor profs[], int numTurmas) {
    if(numAgendamentos >= MAX_HORARIOS) {
        cout << "Agenda lotada!\n";
        return false;
    }
    
    // MOSTRAR TURMAS
    cout << "\nTurmas disponíveis:\n";
    for(int i = 0; i < numTurmas; i++) {
        cout << i+1 << ". " << turmas[i].disciplina << " - " 
             << turmas[i].professor.nome << " - " 
             << turmas[i].numAlunos << " alunos\n";
    }
    
    int escolhaTurma;
    cout << "Escolha a turma: ";
    cin >> escolhaTurma;
    cin.ignore();
    
    if(escolhaTurma < 1 || escolhaTurma > numTurmas) {
        cout << "Turma inválida!\n";
        return false;
    }
    
    Turma turmaEscolhida = turmas[escolhaTurma-1];
    
    // MOSTRAR LABORATÓRIOS
    cout << "\nLaboratórios disponíveis:\n";
    for(int i = 0; i < MAX_LABS; i++) {
        cout << i+1 << ". " << labs[i].nome << " - " 
             << labs[i].capacidade << " lugares - " 
             << labs[i].equipamentos << endl;
    }
    
    int escolhaLab;
    cout << "Escolha o laboratório: ";
    cin >> escolhaLab;
    cin.ignore();
    
    if(escolhaLab < 1 || escolhaLab > MAX_LABS) {
        cout << "Laboratório inválido!\n";
        return false;
    }
    
    Laboratorio labEscolhido = labs[escolhaLab-1];
    
    // VER CAPACIDADE
    if(!capacidadeSuficiente(labEscolhido, turmaEscolhida)) {
        cout << "Capacidade insuficiente do laboratório!\n";
        return false;
    }
    
    // ESCOLHA DE HORÁRIO
    string dia, hora;
    cout << "Dia da semana: ";
    getline(cin, dia);
    cout << "Horário (ex: 14h-16h): ";
    getline(cin, hora);
    
    // VERIFICAÇÃO DE DISPONIBILIDADE
    if(!professorDisponivel(agenda, numAgendamentos, turmaEscolhida.professor, dia, hora)) {
        cout << "Professor não disponível neste horário!\n";
        return false;
    }
    
    if(!laboratorioDisponivel(agenda, numAgendamentos, labEscolhido, dia, hora)) {
        cout << "Laboratório não disponível neste horário!\n";
        return false;
    }
    
    // AGENDAR
    agenda[numAgendamentos].dia = dia;
    agenda[numAgendamentos].hora = hora;
    agenda[numAgendamentos].turma = turmaEscolhida;
    agenda[numAgendamentos].lab = labEscolhido;
    agenda[numAgendamentos].professor = turmaEscolhida.professor;
    
    numAgendamentos++;
    cout << "Aula agendada com sucesso!\n";
    return true;
}

void relatorioProfessor(HorarioAula agenda[], int numAgendamentos, 
                       Professor professores[]) {
    cout << "\n=== RELATÓRIO POR PROFESSOR ===\n";
    
    for(int i = 0; i < MAX_PROFESSORES; i++) {
        cout << "\nProfessor: " << professores[i].nome << endl;
        cout << "Horários:\n";
        
        bool temAula = false;
        for(int j = 0; j < numAgendamentos; j++) {
            if(agenda[j].professor.nome == professores[i].nome) {
                cout << " - " << agenda[j].dia << " " << agenda[j].hora 
                     << " - " << agenda[j].turma.disciplina 
                     << " (" << agenda[j].lab.nome << ")\n";
                temAula = true;
            }
        }
        
        if(!temAula) {
            cout << " - Nenhuma aula agendada\n";
        }
    }
}

void relatorioLaboratorio(HorarioAula agenda[], int numAgendamentos, 
                         Laboratorio laboratorios[]) {
    cout << "\n=== RELATÓRIO POR LABORATÓRIO ===\n";
    
    for(int i = 0; i < MAX_LABS; i++) {
        cout << "\nLaboratório: " << laboratorios[i].nome << endl;
        cout << "Agenda da semana:\n";
        
        bool temAula = false;
        for(int j = 0; j < numAgendamentos; j++) {
            if(agenda[j].lab.nome == laboratorios[i].nome) {
                cout << " - " << agenda[j].dia << " " << agenda[j].hora 
                     << " - " << agenda[j].turma.disciplina 
                     << " (" << agenda[j].professor.nome << ")\n";
                temAula = true;
            }
        }
        
        if(!temAula) {
            cout << " - Nenhuma aula agendada\n";
        }
    }
}

void horariosLivresOcupados(HorarioAula agenda[], int numAgendamentos) {
    cout << "\n=== HORÁRIOS LIVRES E OCUPADOS ===\n";
    
    string dias[] = {"Segunda", "Terca", "Quarta", "Quinta", "Sexta"};
    string horarios[] = {"08h-10h", "10h-12h", "14h-16h", "16h-18h"};
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            bool ocupado = false;
            
            for(int k = 0; k < numAgendamentos; k++) {
                if(agenda[k].dia == dias[i] && agenda[k].hora == horarios[j]) {
                    ocupado = true;
                    break;
                }
            }
            
            cout << dias[i] << " " << horarios[j] << ": " 
                 << (ocupado ? "OCUPADO" : "LIVRE") << endl;
        }
    }
}