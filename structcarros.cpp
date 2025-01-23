#include <iostream>
using namespace std;

struct Carro{
    string marca;
    string matricula;
};

Carro carros[] = {

    {"fiat", "",},
    {"mercedes", "",},
    {"dacia", "",},
    {"renault", "",},
};

int main(){

    for(Carro c : carros){
        cout << "Digite a matricula para o carro - " << c.marca << "  ";
        cin >> c.matricula;
    }
    
    cout << carros[0].marca << "  " << carros[0].matricula;

return 0;
}