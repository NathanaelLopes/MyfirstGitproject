#include <iostream>
#include <cmath>

//#define CONSTANTE_PLANK 6.62607015e-34
//#define ENERGIAML 2.18E-18

using namespace std;


/*float calculoLuz(float x, float lambda){
    return x*lambda;
}*/

/*float Teoremadevirial(float n, float x = ENERGIAML){
    return -x/(-n*n);
}*/

/*float calculoEnergiaFotoes(float f, float h = CONSTANTE_PLANK){
    return h*f;
}*/

int main(){

    system("clear");
   /*float f;
    cout << "Frequencia: ";
    cin >> f;
    cout << "Energia: " << calculoEnergiaFotoes(f, 6.63e-34) << endl;*/

    /*float f, lambda;
    cout << "comprimento de onda: ";
    cin >> lambda;
    cout << "Frequencia: ";
    cin >> f;
    cout << "velocida da luz: " << calculoLuz(lambda, f) << endl;*/

 /*float x;
 cout << "Numero da orbita em que se encontra: ";
 cin >> x;
 cout << "O nivel de orbita é: " << Teoremadevirial(x) << endl;*/


 /**
  * Elaboa uma funçao que calcule a formula apresentada pelo professor
  */

 void resolvente(float a, float b, float c){
   float x1, x2;
   float delta = (b*b)-(4*a*c);
   if(delta < 0){
    cout << "não existem raizes reais" << endl;
   }else{
      x1 = (-b+sqrt(delta))/(2*a);
      x2 = (-b-sqrt(delta))/(2*a);
      cout << "x1: " << x1 << endl;
      cout << "x2: " << x2 << endl;
   }
    return 0;
}
}

