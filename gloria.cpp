#include <iostream>   
#include <ctime>      // trabalhar com tempo (time)
#include <cstdlib>    // gerar números aleatórios (rand, srand)
using namespace std;


// array que representa o tabuleiro
string casas[30];

// Posições dos jogadores no tabuleiro
int posJ1;
int posJ2;

// Variáveis de controle para as casas especiais
bool PerdeVezJ1;   
bool EsperaJ1;     
bool PerdeVezJ2;   
bool EsperaJ2;     

// Nomes dos jogadores
string nomeJ1;
string nomeJ2;


int main() {

    // Inicializa variáveis e estados iniciais
    posJ1 = 0; posJ2 = 0;                 // Jogadores começam na casa 0
    PerdeVezJ1 = false; PerdeVezJ2 = false;
    EsperaJ1 = false; EsperaJ2 = false;

    cout << "============================================================ Bem vindo ao JOGO DA GLORIA!============================================================" << endl;

    // Solicita o nome dos dois jogadores
    cout << "Digite o nome do Jogador 1: ";
    getline(cin, nomeJ1);
    cout << "Digite o nome do Jogador 2: ";
    getline(cin, nomeJ2);

    // Inicializa o gerador de números aleatórios
    srand(time(0));

    // Define todas as casas inicialmente como "Normal"
    for (int i = 0; i < 30; i++) casas[i] = "Normal";

    // Define as casas especiais com suas respectivas regras
    casas[4] = "Perde a vez";       
    casas[9] = "Volta 3";           
    casas[14] = "Avança 3";        
    casas[19] = "Joga novamente";   
    casas[24] = "Espera passar";    

    bool acabou = false; // Variável de controle para saber se o jogo terminou
    int jogador = 1;     // Começa com o jogador 1


    while (!acabou) {

        // Limpa a tela no início de cada rodada
        #ifdef _WIN32
            system("cls");   
        #else
            system("clear"); 
        #endif

        // Mostra o tabuleiro com as posições dos jogadores
        cout << "\n================================================== TABULEIRO =========================================================\n";
        for (int i = 0; i < 30; i++) {

            // Verifica e mostra a posição dos jogadores
            if (i == posJ1 && i == posJ2)
                cout << "[J1J2]"; // Ambos na mesma casa
            else if (i == posJ1)
                cout << "[J1]";   // Jogador 1
            else if (i == posJ2)
                cout << "[J2]";   // Jogador 2
            else if (casas[i] != "Normal") {
                // Exibe um símbolo para casas especiais
                if (casas[i] == "Perde a vez") cout << "[❌]";
                else if (casas[i] == "Volta 3") cout << "[👇3]";
                else if (casas[i] == "Avança 3") cout << "[👆3]";
                else if (casas[i] == "Joga novamente") cout << "[🔁]";
                else if (casas[i] == "Espera passar") cout << "[✋]";
            }
            else
                cout << "[" << i + 1 << "]"; // Mostra o número da casa
        }
        cout << endl;

        // Mostra a legenda dos símbolos usados
        cout << "\nLegenda: ❌ = Perde a vez | 👇3 = Volta 3 | 👆3 = Avança 3 | 🔁 = Joga novamente | ✋ = Espera passar\n";

      
        if (posJ1 >= 29) { 
            cout << "\n🎉 " << nomeJ1 << " venceu o jogo!" << endl; 
            break; 
        }
        if (posJ2 >= 29) { 
            cout << "\n🎉 " << nomeJ2 << " venceu o jogo!" << endl; 
            break; 
        }

        // Mostra qual jogador vai jogar
        cout << "\nVez de ";
        if (jogador == 1) cout << nomeJ1;
        else cout << nomeJ2;
        cout << ". Pressione ENTER para rolar o dado...";
        cin.get(); // Espera o jogador pressionar ENTER

        // Sorteia um número entre 1 e 6 para o dado
        int dado = rand() % 6 + 1;
        cout << "🎲 Dado: " << dado << endl;
        cout << "Pressione ENTER para continuar...";
        cin.get();  // espera o jogador

        // JOGADOR 1 
        if (jogador == 1) {
            posJ1 += dado; // Avança o jogador

            // Chegou ou passou da última casa → vitória
            if (posJ1 >= 29) {
                cout << "\n🎉 " << nomeJ1 << " venceu o jogo!" << endl;
                acabou = true;
            } 
            // Casa 5 → perde a próxima vez
            else if (posJ1 == 4) {
                cout << "Casa 5: " << nomeJ1 << " perde a próxima vez!" << endl;
                PerdeVezJ1 = true;
            } 
            // Casa 10 → volta 3 casas
            else if (posJ1 == 9) {
                cout << "Casa 10: " << nomeJ1 << " volta 3 casas!" << endl;
                posJ1 -= 3;
            } 
            // Casa 15 → avança 3 casas
            else if (posJ1 == 14) {
                cout << "Casa 15: " << nomeJ1 << " avança 3 casas!" << endl;
                posJ1 += 3;
            } 
            // Casa 20 → joga novamente (mantém a vez)
            else if (posJ1 == 19) {
                cout << "Casa 20: " << nomeJ1 << " joga novamente!" << endl;
                continue;
            } 
            // Casa 25 → deve esperar ser ultrapassado
            else if (posJ1 == 24) {
                cout << "Casa 25: " << nomeJ1 << " deve esperar ser ultrapassado!" << endl;
                EsperaJ1 = true;
            }

            jogador = 2; // Passa a vez para o jogador 2
        } 

        //JOGADOR 2 
        else {
            posJ2 += dado; // Avança o jogador

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

            jogador = 1; // Passa a vez para o jogador 1
        }
    }

    return 0;
}
