#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    /* numeros 1 ate 45
    e Estrelas 1 ate 12
    */

    srand(time(0));
    cout << "numeros: ";
    for (int i = 0; i < 5; i++) cout<< rand() % 50 + 1 << " ";
    cout << endl;
    cout << "Estrelas: ";
    for (int i = 0; i < 2; i++) cout << rand() % 12 + 1 << " ";
    cout << endl;

    return 0;
    }

    /**
     * Jogo do Bingo
     * 
     * 1ª parte
     * Será pedido ao ultilizador quantos cartões de bingo ele deseja gerar.
     * Cada cartão de bingo terá 5 linhas
     * 
    

      
    */

   