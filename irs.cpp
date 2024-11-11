#include <iostream>
using namespace std;

float horas;
float salario;
float descontoIRS;
float IRS = 0.125;

int main(){

    cout << "Quantas horas trabalheste?" << endl;
    cin >> horas;

    cout << "quanto ganhas por horas?" << endl;
    cin >> salario;

    float total = horas * salario;
    descontoIRS = total * IRS;
    float totalComDesconto = total - descontoIRS;

    cout << "vais receber" << endl;
    cout << total << "Euros" << endl;

    cout << "Com de desconto do IRS vais receber" << endl;
    cout << totalComDesconto << " Euros" << endl;

    return 0;

}