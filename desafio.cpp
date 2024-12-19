#include <iostream>

using namespace std;

void mostrarDado(int resultado) {
    switch (resultado) {
        case 1:
            cout << "  *  \n";
            break;
        case 2:
            cout << "*   \n    *\n";
            break;
        case 3:
            cout << "*   \n  * \n    *\n";
            break;
        case 4:
            cout << "*   *\n     \n*   *\n";
            break;
        case 5:
            cout << "*   *\n  *  \n*   *\n";
            break;
        case 6:
            cout << "*   *\n*   *\n*   *\n";
            break;
    }
}

int main() {
    int tentativas = 0;
    char comando;

    cout << "Simulador de Dado\n";
    cout << "Pressione Enter para jogar o dado ou 'q' para sair.\n";

    do {
        // Incrementa o contador de tentativas
        tentativas++;

        // Gera um número pseudo-aleatório simples entre 1 e 6
        int resultado = (tentativas * 37 % 6) + 1; // Fórmula simples para simular aleatoriedade

        // Mostra o resultado
        cout << "Resultado do dado: " << resultado << "\n";
        mostrarDado(resultado);

        // Pede pelo próximo comando
        cout << "Pressione Enter para jogar novamente ou 'q' para sair: ";
        comando = cin.get();

    } while (comando != 'q');

    // Mostra o total de tentativas ao final
    cout << "Voce jogou o dado " << tentativas << " vezes.\n";

    return 0;
}











