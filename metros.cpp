#include <iostream>

using namespace std;

int main() {
    char frase[100];
    cout << "-------------------------- Bem-vindo ao jogo Adivinha a Frase! --------------------------" << endl;
    cout << "                                       !Regras!" << endl << endl;
    cout << "Algum jogador deve inserir uma palavra ou frase para ser adivinhada para que o jogo comece!" << endl << endl;
    
    cout << "Insira a frase a ser adivinhada: ";
    cin.getline(frase, 100);
    
    system("clear");
    
    bool descoberto[100] = {false};
    int letrasRestantes = 0;
    
   
    for (int i = 0; frase[i] != '\0'; i++) {
        if (frase[i] != ' ') {
            letrasRestantes++;
        }
    }
    
    
    while (letrasRestantes > 0) {
        cout << "\n";
        
        
        for (int i = 0; frase[i] != '\0'; i++) {
            if (frase[i] == ' ') {
                cout << " ";
            } else if (descoberto[i]) {
                cout << frase[i];
            } else {
                cout << "_";
            }
        }
        cout << endl;
        
        cout << "Adivinhe uma letra: ";
        char tentativa;
        cin >> tentativa;
        
        bool acertou = false;
        
        for (int i = 0; frase[i] != '\0'; i++) {
            if (frase[i] == tentativa && !descoberto[i]) {
                descoberto[i] = true;
                letrasRestantes--;
                acertou = true;
            }
        }
    }
    
    cout << "\nParabéns! A palavra/frase escolhida foi: " << frase << endl;
    
    return 0;
}
