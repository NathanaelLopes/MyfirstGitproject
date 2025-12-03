#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <iomanip>

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
        system("clear || cls"); // Limpa a tela (funciona em Linux/Mac e Windows)

                 cout << "                                                                                                        \n";
                 cout << "                                                                                                        \n";
cout  << AZUL << "             ██████╗ █████╗ ██████╗ ████████╗███████╗██╗      █████╗     ██████╗ ██╗███╗   ██╗ ██████╗  ██████╗ \n";
                 cout << "    ██╔════╝██╔══██╗██╔══██╗╚══██╔══╝██╔════╝██║     ██╔══██╗    ██╔══██╗██║████╗  ██║██╔════╝ ██╔═══██╗ \n";
                 cout << "    ██║     ███████║██████╔╝   ██║   █████╗  ██║     ███████║    ██████╔╝██║██╔██╗ ██║██║  ███╗██║   ██║ \n";
                 cout << "    ██║     ██╔══██║██╔══██╗   ██║   ██╔══╝  ██║     ██╔══██║    ██╔══██╗██║██║╚██╗██║██║   ██║██║   ██║ \n";
                 cout << "    ╚██████╗██║  ██║██║  ██║   ██║   ███████╗███████╗██║  ██║    ██████╔╝██║██║ ╚████║╚██████╔╝╚██████╔╝ \n";
                 cout << "     ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚══════╝╚═╝  ╚═╝    ╚═════╝ ╚═╝╚═╝  ╚═══╝ ╚═════╝  ╚═════╝  \n" << RESET;  

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
    cout << "                           \nPressione ENTER para sortear cada número...\n";
    cin.get();
    
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
    
    return 0;
}
