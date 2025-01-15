#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Configurar a semente para números aleatórios
    srand(time(0));

    string modeloCarro1, modeloCarro2;
    int cavalaria1, torque1, cavalaria2, torque2;

    // Solicitar o modelo do primeiro carro
    cout << "Digite o modelo do primeiro carro (sem espaços): ";
    cin >> modeloCarro1;

    // Gerar valores aleatórios para o primeiro carro
    cavalaria1 = rand() % 401 + 100; // Entre 100 e 500 cv
    torque1 = rand() % 401 + 100;    // Entre 100 e 500 Nm

    // Solicitar o modelo do segundo carro
    cout << "Digite o modelo do segundo carro (sem espaços): ";
    cin >> modeloCarro2;

    // Gerar valores aleatórios para o segundo carro
    cavalaria2 = rand() % 401 + 100; // Entre 100 e 500 cv
    torque2 = rand() % 401 + 100;    // Entre 100 e 500 Nm

    // Exibir os resultados
    cout << "\nResultados do dinamômetro:\n";
    cout << modeloCarro1 << ": " << cavalaria1 << " cv, " << torque1 << " Nm\n";
    cout << modeloCarro2 << ": " << cavalaria2 << " cv, " << torque2 << " Nm\n";

    // Comparar os dois carros
    if (cavalaria1 > cavalaria2) {
        cout << modeloCarro1 << " é mais potente que " << modeloCarro2 << " por " 
             << (cavalaria1 - cavalaria2) << " cv.\n";

    } else if (cavalaria2 > cavalaria1) {
        cout << modeloCarro2 << " é mais potente que " << modeloCarro1 << " por " 
             << (cavalaria2 - cavalaria1) << " cv.\n";

    } else {
        cout << "Ambos os carros têm a mesma potência de " << cavalaria1 << " cv.\n";
    }
    

    return 0;
}
