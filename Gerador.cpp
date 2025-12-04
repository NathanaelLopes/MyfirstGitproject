#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;

// Códigos de cores ANSI
const string RESET    = "\033[0m";
const string VERDE    = "\033[32;1m";   // verde brilhante (intensificado)
const string VERMELHO = "\033[31;1m";   // vermelho brilhante
const string AMARELO  = "\033[38;5;220m"; // amarelo dourado (via 256 cores)
const string AZUL     = "\033[38;5;33m";  // azul ciano escuro
const string NEGRITO  = "\033[1m";

//limpar
void limparEcra(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif 
}

class Bingo {
private:
    vector<bool> numerosSorteados;
    vector<int> numerosDisponiveis;
    
public:
    Bingo() : numerosSorteados(101, false) {
        for(int i = 1; i <= 100; i++) {
            numerosDisponiveis.push_back(i);
        }
        // Embaralhar números
        random_device rd;
        mt19937 g(rd());
        shuffle(numerosDisponiveis.begin(), numerosDisponiveis.end(), g);
    }
     
    void exibirCartela() {
        limparEcra();

        cout << "                                                                                                            \n";
        cout << "                                                                                                            \n";
     cout << AZUL << "         ██████╗ █████╗ ██████╗ ████████╗███████╗██╗      █████╗     ██████╗ ██╗███╗   ██╗ ██████╗  ██████╗ \n";
        cout << "        ██╔════╝██╔══██╗██╔══██╗╚══██╔══╝██╔════╝██║     ██╔══██╗    ██╔══██╗██║████╗  ██║██╔════╝ ██╔═══██╗ \n";
        cout << "        ██║     ███████║██████╔╝   ██║   █████╗  ██║     ███████║    ██████╔╝██║██╔██╗ ██║██║  ███╗██║   ██║ \n";
        cout << "        ██║     ██╔══██║██╔══██╗   ██║   ██╔══╝  ██║     ██╔══██║    ██╔══██╗██║██║╚██╗██║██║   ██║██║   ██║ \n";
        cout << "        ╚██████╗██║  ██║██║  ██║   ██║   ███████╗███████╗██║  ██║    ██████╔╝██║██║ ╚████║╚██████╔╝╚██████╔╝ \n";
        cout << "         ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚══════╝╚═╝  ╚═╝    ╚═════╝ ╚═╝╚═╝  ╚═══╝ ╚═════╝  ╚═════╝  \n" << RESET;  
        cout << endl;

       for(int i = 1; i <= 100; i++) {
            if(numerosSorteados[i]) {
                cout << NEGRITO << VERDE << setw(4) << i << RESET;
            } else {
                cout << setw(4) << i;
            }
            
            if(i % 10 == 0) {
                cout << "\n";
            }
        }
        
        cout << "\n" << AMARELO << "Números sorteados: " << contarSorteados() << "/100" << RESET << "\n";
    }
    
    int sortearNumero() {
        if(numerosDisponiveis.empty()) {
            return -1; // Todos os números foram sorteados
        }
        
        int numero = numerosDisponiveis.back();
        numerosDisponiveis.pop_back();
        numerosSorteados[numero] = true;
        
        return numero;
    }
    
    int contarSorteados() {
        int count = 0;
        for(int i = 1; i <= 100; i++) {
            if(numerosSorteados[i]) count++;
        }
        return count;
    }
    
    bool todosSorteados() {
        return numerosDisponiveis.empty();
    }
};

void modoManual(Bingo& bingo) {
    while(!bingo.todosSorteados()) {
        int numeroSorteado = bingo.sortearNumero();
        
        bingo.exibirCartela();
        
        cout << "\n" << NEGRITO << VERMELHO << "🎯 NÚMERO SORTEADO: " 
             << numeroSorteado << " 🎯" << RESET << "\n\n";
        
        cout << "Pressione ENTER para próximo número (ou Ctrl+C para sair)...";
        cin.get();
    }
    
    bingo.exibirCartela();
    cout << "\n" << NEGRITO << AMARELO << "🎊 BINGO COMPLETO! Todos os números foram sorteados! 🎊\n" << RESET;
}

void modoAutomatico(Bingo& bingo) {
    cout << "\n" << AMARELO << "Modo automático iniciado! Sorteando a cada 2 segundos...\n" << RESET;
    cout << "Pressione Ctrl+C para parar.\n\n";
    
    this_thread::sleep_for(chrono::seconds(2));
    
    while(!bingo.todosSorteados()) {
        int numeroSorteado = bingo.sortearNumero();
        
        bingo.exibirCartela();
        
        cout << "\n" << NEGRITO << VERMELHO << "🎯 NÚMERO SORTEADO: " 
             << numeroSorteado << " 🎯" << RESET << "\n\n";
        
        if(!bingo.todosSorteados()) {
            this_thread::sleep_for(chrono::seconds(2));
        }
    }
    
    bingo.exibirCartela();
    cout << "\n" << NEGRITO << AMARELO << "🎊 BINGO COMPLETO! Todos os números foram sorteados! 🎊\n" << RESET;
}

int main() {
    limparEcra();
    Bingo bingo;
    
    cout << NEGRITO << AZUL;
    cout << "                                                                                            \n";
    cout << "                                                                                            \n";
    cout << "                ██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ ██╗██╗\n";
    cout << "                ██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗██║██║\n";
    cout << "                ██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║██║██║\n";
    cout << "                ██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║╚═╝╚═╝\n";
    cout << "                ██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝██╗██╗\n";
    cout << "                ╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ ╚═╝╚═╝\n" << RESET;
    cout << "                                                                                            \n";
    cout << "                                                                                            \n";
    
     
    cout << AMARELO << "\nEscolha o modo de jogo:\n" << RESET;
    cout << "1 - Modo Manual (pressione ENTER para cada sorteio)\n";
    cout << "2 - Modo Automático (sorteio automático a cada X segundos)\n";
    cout << "\nDigite sua escolha: ";
    
    int escolha;
    cin >> escolha;
    cin.ignore(); // Limpar buffer
    
    if(escolha == 2) {
        modoAutomatico(bingo);
    } else {
        cout << "\nPressione ENTER para começar...\n";
        cin.get();
        modoManual(bingo);
    }
    
    return 0;
}
