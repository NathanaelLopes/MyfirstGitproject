#include <iostream>
using namespace std;

int main() {
    bool chaveVirada = false; 
    char comando;

    // Ciclo para virar a chave e ligar o carro
    while (true) {
        cout << "Pressione 'V' para virar a chave: ";
        cin >> comando;

        if (comando == 'V' || comando == 'v') {
            chaveVirada = true;
            cout << "Chave virada!" << endl;
            break; 
             // Sai do ciclo quando a chave for virada

           } else { 

            cout << "Comando inválido! Tente novamente." << endl;
        }
    }

    if (chaveVirada) {
        while (true) {
            cout << "Pressione 'L' para ligar o carro: ";
            cin >> comando;

            if (comando == 'L' || comando == 'l') {
                cout << "Carro ligado! Vrum Vrum!" << endl;
                break;  
                // Sai do ciclo quando o carro for ligado

             } else {

                cout << "Erro! Não conseguiu ligar o carro. Tente novamente." << endl;
            }
        }
    } else {
        cout << "Erro! Chave não foi virada." << endl;
    }

    return 0;
}
