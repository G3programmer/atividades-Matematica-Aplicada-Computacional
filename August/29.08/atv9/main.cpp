#include <iostream>
#include "header.h"
using namespace std;

int main() {
    Professor professores[MAX_PROFESSORES];
    Laboratorio laboratorios[MAX_LABS];
    HorarioAula agenda[MAX_HORARIOS];
    int numAgendamentos = 0;
    int numTurmas = 0;
    Turma* turmas = nullptr;
    
    // CADASTRO INICIAL
    cadastrarProfessores(professores);
    cadastrarLaboratorios(laboratorios);
    
    int opcao;
    do {
        cout << "\n=== SISTEMA DE AGENDAMENTO ===" << endl;
        cout << "1. Cadastrar turmas" << endl;
        cout << "2. Agendar aula" << endl;
        cout << "3. Relatório por professor" << endl;
        cout << "4. Relatório por laboratório" << endl;
        cout << "5. Horários livres/ocupados" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha: ";
        cin >> opcao;
        cin.ignore();
        
        switch(opcao) {
            case 1:
                if(turmas != nullptr) delete[] turmas;
                turmas = cadastrarTurmas(professores, numTurmas);
                break;
            case 2:
                if(turmas == nullptr) {
                    cout << "Cadastre turmas primeiro!\n";
                } else {
                    agendarAula(agenda, numAgendamentos, turmas, 
                               laboratorios, professores, numTurmas);
                }
                break;
            case 3:
                relatorioProfessor(agenda, numAgendamentos, professores);
                break;
            case 4:
                relatorioLaboratorio(agenda, numAgendamentos, laboratorios);
                break;
            case 5:
                horariosLivresOcupados(agenda, numAgendamentos);
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }
    } while(opcao != 0);
    
    // LIMPAR MEMÓRIA
    if(turmas != nullptr) delete[] turmas;
 
    system("pause");
    return 0;
}