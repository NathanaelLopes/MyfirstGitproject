#include <iostream>

using namespace std;

int main(){

    // int tabuada;
   /* string nome;
    int ano;

    cout << "Ola poderia dizer-me o seu nome?" << endl;
    cin >> nome;
    cout << "Olá  " << nome << endl;


    cout << "Qual foi ano que vocẽ nasceu?" << endl;
    cin >> ano;

    cout << "você tem   " << 2024 - ano << endl;

    for(int i = 1; i<=10; i++){
        cout << i << "\t";
        }
    */

   /*cout << "Qual tabuada que queres?" << endl;
   cin >> tabuada;

   for(int i = 1; i<=10; i++){
    cout << "  " << i << " x " << tabuada <<" = " << i*tabuada << endl;}
    */
int largura, altura;
cout << "digite a lagura" << endl;
cin >> largura;
cout << "digite a altura" << endl;
cin >> altura;

    for(int i = 0; i < altura; i++){

        for (int j = 0; j < largura; j++){
            cout << " * ";             

        }
      cout << endl;                      
    }

return 0;
}

