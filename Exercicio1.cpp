#include <iostream>
using namespace std;


int main(){

    int numero;
    cout << "introduza um número" << endl;
    cin >> numero;

    cout << (numero % 2 == 0 ? "par" : "impar") << endl;

}
