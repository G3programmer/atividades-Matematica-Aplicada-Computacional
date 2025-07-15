#include <iostream>
#include <sstream>
#include <string>
#include <thread>   // necessário para sleep
#include <chrono>   // necessário para sleep
using namespace std;

// Função para limpar a tela
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

struct Reserva {
    int id_sala;
    int dia;
    int hora;
    bool feita;
};

struct Sala {
    int id;
    int capacidade;
    bool disponivel;
    Reserva reservas[7][12];
};

int main() {
    Sala salas[10];
    int totalSalas = 0;
    int opcao;
    string entrada;

    // --- Verificação de usuário com opções numéricas ---
    int tipoUsuario = 0;
    while (true) {
        limparTela();
        cout << "Você é:\n";
        cout << "1. Admin\n";
        cout << "2. Usuário\n";
        cout << "Escolha uma opção (1 ou 2): ";
        getline(cin >> ws, entrada);
        stringstream ss(entrada);
        if ((ss >> tipoUsuario) && ss.eof() && (tipoUsuario == 1 || tipoUsuario == 2)) break;
        cout << "Opção inválida. Digite 1 para Admin ou 2 para Usuário.\n";
        this_thread::sleep_for(chrono::seconds(2));
    }
    bool isAdmin = (tipoUsuario == 1);

    do {
        limparTela();  // limpa a tela a cada início de ciclo do menu

        cout << "\n--- MENU ---\n";
        if (isAdmin) {
            cout << "1. Cadastrar sala\n";
            cout << "2. Ver status\n";
            cout << "3. Fazer reserva\n";
            cout << "4. Cancelar reserva\n";
            cout << "5. Sair\n";
            cout << "Opcao: ";
            while (true) {
                getline(cin >> ws, entrada);
                stringstream ss(entrada);
                if ((ss >> opcao) && ss.eof() && opcao >= 1 && opcao <= 5) break;
                cout << "Opção inválida. Digite um número entre 1 e 5: ";
            }
        } else {
            // Usuário normal não pode cadastrar sala
            cout << "1. Ver status\n";
            cout << "2. Fazer reserva\n";
            cout << "3. Cancelar reserva\n";
            cout << "4. Sair\n";
            cout << "Opcao: ";
            while (true) {
                getline(cin >> ws, entrada);
                stringstream ss(entrada);
                if ((ss >> opcao) && ss.eof() && opcao >= 1 && opcao <= 4) break;
                cout << "Opção inválida. Digite um número entre 1 e 4: ";
            }

            // Mapear as opções do usuário para as do admin para reaproveitar código:
            // usuário escolheu 1 (Ver status) => opcao = 2 (admin)
            // usuário escolheu 2 (Fazer reserva) => opcao = 3 (admin)
            // usuário escolheu 3 (Cancelar reserva) => opcao = 4 (admin)
            // usuário escolheu 4 (Sair) => opcao = 5 (admin)
            opcao += 1;
        }

        if (opcao == 1) {  // Cadastrar sala (somente admin)
            if (!isAdmin) {
                cout << "Opção inválida para usuário comum.\n";
                this_thread::sleep_for(chrono::seconds(2));
                continue;
            }

            if (totalSalas < 10) {
                Sala s;

                cout << "ID da sala: ";
                while (true) {
                    getline(cin >> ws, entrada);
                    stringstream ss(entrada);
                    if ((ss >> s.id) && ss.eof()) break;
                    cout << "Valor inválido. Digite um número inteiro para o ID da sala: ";
                }

                cout << "Capacidade: ";
                while (true) {
                    getline(cin >> ws, entrada);
                    stringstream ss(entrada);
                    if ((ss >> s.capacidade) && ss.eof() && s.capacidade > 0) break;
                    cout << "Valor inválido. Digite um número inteiro positivo para a capacidade: ";
                }

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
                this_thread::sleep_for(chrono::seconds(2));
            } else {
                cout << "Limite de salas atingido.\n";
                this_thread::sleep_for(chrono::seconds(2));
            }
        }

        else if (opcao == 2) {  // Ver status
            for (int i = 0; i < totalSalas; i++) {
                cout << "\nSala ID: " << salas[i].id
                     << " | Capacidade: " << salas[i].capacidade
                     << " | Disponível: " << (salas[i].disponivel ? "Sim" : "Nao") << "\n";

                cout << "Reservas:\n";
                for (int d = 0; d < 7; d++) {
                    for (int h = 0; h < 12; h++) {
                        if (salas[i].reservas[d][h].feita) {
                            cout << "  Dia " << (d + 1) << ", Hora " << (h + 1) << ": Reservado\n";
                        }
                    }
                }
            }
            this_thread::sleep_for(chrono::seconds(3));
        }

        else if (opcao == 3) {  // Fazer reserva
            int id, dia, hora, pessoas;

            cout << "ID da sala: ";
            while (true) {
                getline(cin >> ws, entrada);
                stringstream ss(entrada);
                if ((ss >> id) && ss.eof()) break;
                cout << "Valor inválido. Digite um número inteiro para o ID da sala: ";
            }

            cout << "Dia (1 a 7): ";
            while (true) {
                getline(cin >> ws, entrada);
                stringstream ss(entrada);
                if ((ss >> dia) && ss.eof() && dia >= 1 && dia <= 7) break;
                cout << "Valor inválido. Digite um número inteiro entre 1 e 7 para o dia: ";
            }

            cout << "Hora (1 a 12): ";
            while (true) {
                getline(cin >> ws, entrada);
                stringstream ss(entrada);
                if ((ss >> hora) && ss.eof() && hora >= 1 && hora <= 12) break;
                cout << "Valor inválido. Digite um número inteiro entre 1 e 12 para a hora: ";
            }

            cout << "Quantidade de pessoas: ";
            while (true) {
                getline(cin >> ws, entrada);
                stringstream ss(entrada);
                if ((ss >> pessoas) && ss.eof() && pessoas > 0) break;
                cout << "Valor inválido. Digite um número inteiro positivo para a quantidade de pessoas: ";
            }

            bool encontrada = false;
            for (int i = 0; i < totalSalas; i++) {
                if (salas[i].id == id) {
                    encontrada = true;
                    if (!salas[i].disponivel) {
                        cout << "Sala indisponível.\n";
                    } else if (pessoas > salas[i].capacidade) {
                        cout << "A sala não suporta essa quantidade de pessoas. Capacidade máxima: " << salas[i].capacidade << "\n";
                    } else if (salas[i].reservas[dia - 1][hora - 1].feita) {
                        cout << "Já está reservada.\n";
                    } else {
                        salas[i].reservas[dia - 1][hora - 1].feita = true;
                        cout << "Reserva feita!\n";
                    }
                    break;
                }
            }
            if (!encontrada) cout << "Sala não encontrada.\n";
            this_thread::sleep_for(chrono::seconds(2));
        }

        else if (opcao == 4) {  // Cancelar reserva
            int id, dia, hora;

            cout << "ID da sala: ";
            while (true) {
                getline(cin >> ws, entrada);
                stringstream ss(entrada);
                if ((ss >> id) && ss.eof()) break;
                cout << "Valor inválido. Digite um número inteiro para o ID da sala: ";
            }

            cout << "Dia (1 a 7): ";
            while (true) {
                getline(cin >> ws, entrada);
                stringstream ss(entrada);
                if ((ss >> dia) && ss.eof() && dia >= 1 && dia <= 7) break;
                cout << "Valor inválido. Digite um número entre 1 e 7 para o dia: ";
            }

            cout << "Hora (1 a 12): ";
            while (true) {
                getline(cin >> ws, entrada);
                stringstream ss(entrada);
                if ((ss >> hora) && ss.eof() && hora >= 1 && hora <= 12) break;
                cout << "Valor inválido. Digite um número entre 1 e 12 para a hora: ";
            }

            bool encontrada = false;
            for (int i = 0; i < totalSalas; i++) {
                if (salas[i].id == id) {
                    encontrada = true;
                    if (salas[i].reservas[dia - 1][hora - 1].feita) {
                        salas[i].reservas[dia - 1][hora - 1].feita = false;
                        cout << "Reserva cancelada.\n";
                    } else {
                        cout << "Nenhuma reserva nesse horário.\n";
                    }
                    break;
                }
            }
            if (!encontrada) cout << "Sala não encontrada.\n";
            this_thread::sleep_for(chrono::seconds(2));
        }

    } while (opcao != 5);

    cout << "Saindo do sistema...\n";
    return 0;
}
