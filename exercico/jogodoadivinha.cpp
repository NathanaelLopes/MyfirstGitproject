#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    // Array do alfabeto em minúsculas
    char alfabeto[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                     'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    // O computador escolhe uma letra aleatória
    char letraEscolhida = alfabeto[rand() % 26];
    
    // Variáveis do jogodoadivinha
    char chute;
    int tentativas = 6;
    bool acertou = false;
    
    // Inicializa o gerador de números aleatórios
    srand(time(0));
    
    //Instruções do jogo
    cout << "Bem-vindo ao jogo de adivinhar a letra!" << endl;
    cout << "Tente adivinhar a letra escolhida pelo computador." << endl;
    cout << "você tem " << tentativas << " tentativas." << endl;

    // Loop do jogo
    while (tentativas > 0) {
        cout << "\nDigite uma letra (a-z): ";
        cin >> chute;

        // Verifica se a entrada é válida
        if (chute < 'a' || chute > 'z') {
            cout << "Letra inválida! Por favor, coloque uma letra minúscula (a-z)." << endl;
            continue;
        }
        
        if (chute == letraEscolhida) {
            acertou = true;
            break;

        } else if (chute < letraEscolhida) {
            cout << "A letra escolhida é maior que " << chute << "." << endl;
        } else {
            cout << "A letra escolhida é menor que " << chute << "." << endl;
        }

        tentativas--;
        cout << "Tens " << tentativas << " tentativa(s) restante(s)." << endl;
    }

    // Resultado do jogo
    if (acertou) {
        cout << "\nParabéns! Acertaste a letra escolhida: " << letraEscolhida << "!" << endl;
    } else {
        cout << "\nQue pena! Não acertaste. A letra escolhida era: " << letraEscolhida << "." << endl;
    }

    return 0;
}
