#include <iostream>
using namespace std;

const float PI=3.14159;
float raio;

int main(){
    cout << "indique o valor do raio:" << endl;
    cin >> raio;


    cout << "o perimetro da circunferencia é" << endl;
    cout << 2*PI*raio << endl;

    cout << "A area da circunferencia é" << endl;
    cout << PI*(raio*raio) << endl;

    cout << "O diametro da circunferencia é" << endl;
    cout << 2*PI << endl;

    return 0;
}