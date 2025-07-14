#include <iostream>
using namespace std;

struct Reserva {
    int id_sala;
    int dia;
    int hora;
    bool feita; // se há ou não reserva
};

struct Sala {
    int id;
    int capacidade;
    bool disponivel;
    Reserva reservas[7][12]; // 7 dias, 12 horários
};

int main() {
    Sala salas[10];
    int totalSalas = 0;
    int opcao;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Cadastrar sala\n";
        cout << "2. Ver status\n";
        cout << "3. Fazer reserva\n";
        cout << "4. Cancelar reserva\n";
        cout << "5. Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            if (totalSalas < 10) {
                Sala s;
                cout << "ID da sala: ";
                cin >> s.id;
                cout << "Capacidade: ";
                cin >> s.capacidade;
                s.disponivel = true;

                for (int d = 0; d < 7; d++) {
                    for (int h = 0; h < 12; h++) {
                        s.reservas[d][h].id_sala = s.id;
                        s.reservas[d][h].dia = d;
                        s.reservas[d][h].hora = h;
                        s.reservas[d][h].feita = false;
                    }
                }

                salas[totalSalas++] = s;
                cout << "Sala cadastrada!\n";
            } else {
                cout << "Limite de salas atingido.\n";
            }
        }

        else if (opcao == 2) {
            for (int i = 0; i < totalSalas; i++) {
                cout << "\nSala ID: " << salas[i].id
                     << " | Capacidade: " << salas[i].capacidade
                     << " | Disponível: " << (salas[i].disponivel ? "Sim" : "Nao") << "\n";

                cout << "Reservas:\n";
                for (int d = 0; d < 7; d++) {
                    for (int h = 0; h < 12; h++) {
                        if (salas[i].reservas[d][h].feita) {
                            cout << "  Dia " << d << ", Hora " << h << ": Reservado\n";
                        }
                    }
                }
            }
        }

        else if (opcao == 3) {
            int id, dia, hora;
            cout << "ID da sala: ";
            cin >> id;
            cout << "Dia (0 a 6): ";
            cin >> dia;
            cout << "Hora (0 a 11): ";
            cin >> hora;

            bool encontrada = false;
            for (int i = 0; i < totalSalas; i++) {
                if (salas[i].id == id) {
                    encontrada = true;
                    if (!salas[i].disponivel) {
                        cout << "Sala indisponível.\n";
                    } else if (salas[i].reservas[dia][hora].feita) {
                        cout << "Já está reservada.\n";
                    } else {
                        salas[i].reservas[dia][hora].feita = true;
                        cout << "Reserva feita!\n";
                    }
                    break;
                }
            }
            if (!encontrada) cout << "Sala não encontrada.\n";
        }

        else if (opcao == 4) {
            int id, dia, hora;
            cout << "ID da sala: ";
            cin >> id;
            cout << "Dia (0 a 6): ";
            cin >> dia;
            cout << "Hora (0 a 11): ";
            cin >> hora;

            bool encontrada = false;
            for (int i = 0; i < totalSalas; i++) {
                if (salas[i].id == id) {
                    encontrada = true;
                    if (salas[i].reservas[dia][hora].feita) {
                        salas[i].reservas[dia][hora].feita = false;
                        cout << "Reserva cancelada.\n";
                    } else {
                        cout << "Nenhuma reserva nesse horário.\n";
                    }
                    break;
                }
            }
            if (!encontrada) cout << "Sala não encontrada.\n";
        }

    } while (opcao != 5);

    return 0;
}
