#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

string casas[30];
int posJ1;
int posJ2;
bool PerdeVezJ1;
bool EsperaJ1;
bool PerdeVezJ2;
bool EsperaJ2;
string nomeJ1;
string nomeJ2;

int main() {

    posJ1 = 0; posJ2 = 0;
    PerdeVezJ1 = false; PerdeVezJ2 = false;
    EsperaJ1 = false; EsperaJ2 = false;

    cout << "============================================================ Bem vindo ao JOGO DA GLORIA!============================================================" << endl;
    // --- pedir nomes dos jogadores ---
    cout << "Digite o nome do Jogador 1: ";
    getline(cin, nomeJ1);

    cout << "Digite o nome do Jogador 2: ";
    getline(cin, nomeJ2);

    srand(time(0)); // ativa o aleatório

    // cria o tabuleiro
    for (int i = 0; i < 30; i++) {
        casas[i] = "Normal";
    }

    // define as casas especiais
    casas[4] = "Perde a vez";
    casas[9] = "Volta 3";
    casas[14] = "Avança 3";
    casas[19] = "Joga novamente";
    casas[24] = "Espera passar";

    bool acabou = false;
    int jogador = 1;

    while (!acabou) {

        // limpa a tela a cada rodada
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        // mostra tabuleiro
        cout << "\n================================================== TABULEIRO =========================================================\n";
        for (int i = 0; i < 30; i++) {
            if (i == posJ1 && i == posJ2)
                cout << "[J1J2]";
            else if (i == posJ1)
                cout << "[J1]";
            else if (i == posJ2)
                cout << "[J2]";
            else if (casas[i] != "Normal") {
                // mostra nome resumido da casa especial
                if (casas[i] == "Perde a vez") cout << "[❌]";
                else if (casas[i] == "Volta 3") cout << "[👇3]";
                else if (casas[i] == "Avança 3") cout << "[👆3]";
                else if (casas[i] == "Joga novamente") cout << "[🔁]";
                else if (casas[i] == "Espera passar") cout << "[✋]";
            }
            else
                cout << "[" << i + 1 << "]";
        }
        cout << endl;

        // legenda das casas especiais
        cout << "\nLegenda: ❌ = Perde a vez | 👇3 = Volta 3 | 👆3 = Avança 3 | 🔁 = Joga novamente | ✋ = Espera passar\n";

        // verificar fim de jogo
        if (posJ1 >= 29) { 
            cout << "\n🎉 " << nomeJ1 << " venceu o jogo!" << endl; 
            break; 
        }
        if (posJ2 >= 29) { 
            cout << "\n🎉 " << nomeJ2 << " venceu o jogo!" << endl; 
            break; 
        }

        // mostra de quem é a vez
        cout << "\nVez de ";
        if (jogador == 1) cout << nomeJ1;
        else cout << nomeJ2;
        cout << ". Pressione ENTER para rolar o dado...";
        cin.get();

        int dado = rand() % 6 + 1;
        cout << "🎲 Dado: " << dado << endl;

        // --- jogador 1 ---
        if (jogador == 1) {
            posJ1 += dado;

            if (posJ1 >= 29) {
                cout << "\n🎉 " << nomeJ1 << " venceu o jogo!" << endl;
                acabou = true;
            } 
            else if (posJ1 == 4) {
                cout << "Casa 5: " << nomeJ1 << " perde a próxima vez!" << endl;
                PerdeVezJ1 = true;
            } 
            else if (posJ1 == 9) {
                cout << "Casa 10: " << nomeJ1 << " volta 3 casas!" << endl;
                posJ1 -= 3;
            } 
            else if (posJ1 == 14) {
                cout << "Casa 15: " << nomeJ1 << " avança 3 casas!" << endl;
                posJ1 += 3;
            } 
            else if (posJ1 == 19) {
                cout << "Casa 20: " << nomeJ1 << " joga novamente!" << endl;
                continue;
            } 
            else if (posJ1 == 24) {
                cout << "Casa 25: " << nomeJ1 << " deve esperar ser ultrapassado!" << endl;
                EsperaJ1 = true;
            }

            jogador = 2; // troca
        } 

        // --- jogador 2 ---
        else {
            posJ2 += dado;

            if (posJ2 >= 29) {
                cout << "\n🎉 " << nomeJ2 << " venceu o jogo!" << endl;
                acabou = true;
            } 
            else if (posJ2 == 4) {
                cout << "Casa 5: " << nomeJ2 << " perde a próxima vez!" << endl;
                PerdeVezJ2 = true;
            } 
            else if (posJ2 == 9) {
                cout << "Casa 10: " << nomeJ2 << " volta 3 casas!" << endl;
                posJ2 -= 3;
            } 
            else if (posJ2 == 14) {
                cout << "Casa 15: " << nomeJ2 << " avança 3 casas!" << endl;
                posJ2 += 3;
            } 
            else if (posJ2 == 19) {
                cout << "Casa 20: " << nomeJ2 << " joga novamente!" << endl;
                continue;
            } 
            else if (posJ2 == 24) {
                cout << "Casa 25: " << nomeJ2 << " deve esperar ser ultrapassado!" << endl;
                EsperaJ2 = true;
            }

            jogador = 1; // troca
        }
    }

    return 0;
}

